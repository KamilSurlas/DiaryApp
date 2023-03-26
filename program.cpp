#include "program.h"


Program::Program(QObject *parent)
    : QObject(parent)
{

}

void Program::dodajNowyWpis()
{
   daneNowegoWpisu daneWpisu;
   GUINowychWpisow = new noweWpisy(daneWpisu);
   GUINowychWpisow->exec();
   if(!daneWpisu.tekst.isEmpty()){
        Wpis nowyWpis(daneWpisu.data,daneWpisu.tekst,daneWpisu.rodzajWspomnienia);
        Wpis::setToList(nowyWpis);
        emit dodanoWpis();
   }
   else
       emit bladDodaniaWpisu();
}

int Program::getIloscFiltrowanych()
{
    return Wpis::getIloscWpisowFiltrowanych();
}



void Program::zmniejszIndexFiltr()
{
    Wpis::zmniejszIndFiltr();
}

void Program::zwiekszIndexFiltr()
{
    Wpis::zwiekszIndFiltr();
}

int Program::getIndexAktualnegoWpisu()
{
    return Wpis::getIndex();
}

int Program::getIndexAktFiltr()
{
    return Wpis::getIndexAktualnegoWpisuFiltr();
}

int Program::getIloscWpisow()
{
    return Wpis::getIloscWpisow();
}


void Program::zmniejszIndex()
{
    Wpis::zmniejszInd();
}

void Program::zwiekszIndex()
{
    Wpis::zwiekszInd();
}

void Program::usunWpis()
{
    Wpis::usun();
    Wpis::zmniejszInd();
    if(Wpis::getIndex() < 0) Wpis::zwiekszInd();
    emit usunietoWpis();
}

void Program::aktualizajWpisy()
{
     int poprzedniIndex;
     int nastepnyIndex;
     QString nastepny;
     QString poprzedni;
     QString aktualny;
      if(Wpis::getIloscWpisowFiltrowanych() == 0){
      poprzedniIndex = Wpis::getIndex() - 1;
      nastepnyIndex = Wpis::getIndex() + 1;
      if(Wpis::getListaWpisow().isEmpty())
          throw std::out_of_range("");
      aktualny = QString(Wpis::getWpis(Wpis::getIndex()));
       if(nastepnyIndex == getIloscWpisow())
       {
            nastepny = QString("<span style=\" color:#ff0000;\">%1</span>").arg("BRAK NASTEPNEGO WPISU");
       } else
       {
           nastepny = QString(Wpis::getWpis(nastepnyIndex));
       }
       if(poprzedniIndex < 0)
       {
           poprzedni = QString("<span style=\" color:#ff0000;\">%1</span>").arg("BRAK POPRZEDNIEGO WPISU");
       } else
       {
          poprzedni = QString(Wpis::getWpis(poprzedniIndex));
       }
    } else {
        poprzedniIndex = Wpis::getIndexAktualnegoWpisuFiltr() - 1;
        nastepnyIndex = Wpis::getIndexAktualnegoWpisuFiltr() + 1;
         aktualny = QString(Wpis::getWpisZListyFiltrowanej(Wpis::getIndexAktualnegoWpisuFiltr()));
         if(nastepnyIndex == Wpis::getIloscWpisowFiltrowanych())
         {
              nastepny = QString("<span style=\" color:#ff0000;\">%1</span>").arg("BRAK NASTEPNEGO WPISU");
         } else
         {
             nastepny = QString(Wpis::getWpisZListyFiltrowanej(nastepnyIndex));
         }
         if(poprzedniIndex < 0)
         {
             poprzedni = QString("<span style=\" color:#ff0000;\">%1</span>").arg("BRAK POPRZEDNIEGO WPISU");
         } else
         {
            poprzedni = QString(Wpis::getWpisZListyFiltrowanej(poprzedniIndex));
         }
    }
    emit wypiszWpisy(aktualny,poprzedni,nastepny);
}





void Program::edytujWpis(QString nowaTresc, QDateTime nowaData)
{
    rodzajWspomnienia rodzajWspomnienia = Wpis::getListaWpisow()[Wpis::getIndex()].getRodzajWspomnienia();
    Wpis::usun();
    Wpis edytowanyWpis(nowaData,nowaTresc,rodzajWspomnienia);
    Wpis::setToList(edytowanyWpis);
    emit edytowanoWpis();
}

void Program::wczytajZPliku(QString nazwaPliku)
{

    ObslugaPlikow plik;
    if(plik.czyZnalezionoPlik(nazwaPliku)){
        Wpis::wyczyscWpisy();
        plik.odczytajZPliku(nazwaPliku);
        Wpis::setIndexAkt(plik.getOdczytanyIndex());
        emit wpisyWczytane();
    }
    else
    {
        emit wpisowBrak();
    }
}

void Program::zapiszDoPliku(QString nazwaPliku)
{
    if(Wpis::getListaWpisow().size() > 0)
    {
        ObslugaPlikow plik;
        plik.zapiszDoPliku(Wpis::getIndex(),Wpis::getListaWpisow().size(),nazwaPliku);
        emit zapisanoWpisy();
    }
}

void Program::wpiszSmutne()
{
    Wpis::wydzielWpisy(rodzajWspomnienia::Smutne);
    emit filtrSmutne();
}

void Program::wpiszNeutralne()
{
    Wpis::wydzielWpisy(rodzajWspomnienia::Neutralne);
    emit filtrNeutralne();

}

void Program::wpiszRadosne()
{
    Wpis::wydzielWpisy(rodzajWspomnienia::Radosne);
    emit filtrRadosne();
}

void Program::wyczyscFiltry()
{
    Wpis::wyczyscWpisyFiltrowane();
}

void Program::usunPlikZWpisami()
{
 ObslugaPlikow plik;
 plik.usunPlikZWpisami();
}

void Program::aktualizujIndexy(kierunekPrzewijania kier)
{
    if(kier == kierunekPrzewijania::NaDol){
        if(Wpis::getIloscWpisowFiltrowanych() == 0){
            if((Wpis::getIndex()+ 1) < Wpis::getIloscWpisow())
            {
                Wpis::zwiekszInd();
                aktualizajWpisy();
            }
        }    else if((Wpis::getIndexAktualnegoWpisuFiltr() + 1) <Wpis::getIloscWpisowFiltrowanych())
        {
            Wpis::zwiekszIndFiltr();
            aktualizajWpisy();
        }


    } else if(kier == kierunekPrzewijania::WGore){
        if(Wpis::getIloscWpisowFiltrowanych() == 0){
            if((Wpis::getIndex()) > 0)
            {
                Wpis::zmniejszInd();
                aktualizajWpisy();
            }
        }
        else if(Wpis::getIndexAktualnegoWpisuFiltr() > 0)
        {
           Wpis::zmniejszIndFiltr();
           aktualizajWpisy();
        }
    }
}

bool Program::czyMoznaFiltrowac(rodzajWspomnienia rodzaj)
{
    return Wpis::sprawdzCzyMoznaOdfiltrowac(rodzaj);
}

void Program::wybierzSciezke()
{
    ObslugaPlikow plik;
    plik.wybierzSciezke();
    emit wybranoSciezke(plik.getSciezkaDoBackupu());
}

void Program::usunFiltr(rodzajWspomnienia rodzaj)
{
    Wpis::usunFiltr(rodzaj);
}


