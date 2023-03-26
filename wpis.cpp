#include "wpis.h"
int Wpis::indexAktualnego = 0;
int Wpis::indexAktualnegoFiltr = 0;
QList<Wpis> Wpis::listaWszystkichWpisow = {};
QList<Wpis> Wpis::listaWpisowFiltrowanych = {};


Wpis::Wpis(QDateTime data_czas, QString nowyWpis, rodzajWspomnienia rodzajWspomnienia)
{
    if(nowyWpis.size() > 0)
    {
    m_wpis = nowyWpis;
    m_data_czas = data_czas;
    m_rodzajWspomnienia = rodzajWspomnienia;
    }
}

Wpis::Wpis()
{

}
void Wpis::setTresc(QString tresc)
{
   m_wpis = tresc;
}
QString Wpis::getWpis(){
    return m_wpis;
}
QDateTime Wpis::getData_Czas() {
    return m_data_czas;
}

rodzajWspomnienia Wpis::getRodzajWspomnienia()
{
    return m_rodzajWspomnienia;
}
bool Wpis::operator==(const Wpis& prawyOperand) const{
    if(this != &prawyOperand){
        return (this->m_data_czas == prawyOperand.m_data_czas);
    }else{
        return true;
    }
}
bool Wpis::operator!=(const Wpis& prawyOperand) const{
    return !(*this == prawyOperand);
}
bool Wpis::operator<(const Wpis& prawyOperand) const {
    return (this->m_data_czas < prawyOperand.m_data_czas);
}

QString Wpis::przygotujDoZapisania()
{

    return this->m_data_czas.toString() + "\n" + QString::number(int(m_rodzajWspomnienia)) + "\n" + this->m_wpis;
    }

Wpis::operator QString()
{
    QVector<QString> rodzajeWspomnien = {"Smutny","Neutralny","Radosny"};
    return QString("<span style=\"font-weight: bold;\">%1</span>").arg(this->m_data_czas.toString()) + " " +QString("<span style=\"font-weight: bold;\">%1</span>").arg(rodzajeWspomnien[(int(this->m_rodzajWspomnienia))]) + "<br>" + this->m_wpis;
}
int Wpis::getIndex()
{
    return indexAktualnego;
}
QList<Wpis> Wpis::getListaWpisow()
{
    return listaWszystkichWpisow;
}

QList<Wpis> Wpis::getListaWpisowFiltrowanych()
{
    return listaWpisowFiltrowanych;
}

void Wpis::zmniejszInd()
{
    indexAktualnego--;
}

void Wpis::zwiekszInd()
{
    indexAktualnego++;
}

void Wpis::setIndexAkt(int index)
{
    indexAktualnego = index;
}

void Wpis::zmniejszIndFiltr()
{
    indexAktualnegoFiltr--;
}

void Wpis::zwiekszIndFiltr()
{
    indexAktualnegoFiltr++;
}

void Wpis::usun()
{
    if(listaWszystkichWpisow.size() > 0)
    listaWszystkichWpisow.removeAt(indexAktualnego);
}

int Wpis::getIloscWpisow()
{
    return listaWszystkichWpisow.size();
}

void Wpis::usunFiltr(rodzajWspomnienia rodzajWpisu)
{
    if(Wpis::sprawdzCzyMoznaOdfiltrowac(rodzajWpisu)){
        for(int i =0;i<listaWpisowFiltrowanych.size();i++)
            if(listaWpisowFiltrowanych[i].getRodzajWspomnienia() == rodzajWpisu)
        listaWpisowFiltrowanych.removeAt(i);
    }
    indexAktualnegoFiltr = listaWpisowFiltrowanych.size();
}

int Wpis::getIloscWpisowFiltrowanych()
{
    return listaWpisowFiltrowanych.size();
}


Wpis Wpis::getWpis(int index)
{
    return listaWszystkichWpisow[index];
}

Wpis Wpis::getWpisZListyFiltrowanej(int index)
{
    return listaWpisowFiltrowanych[index];
}

void Wpis::wyczyscWpisy()
{
    Wpis::listaWszystkichWpisow.clear();
}

void Wpis::wyczyscWpisyFiltrowane()
{
    Wpis::listaWpisowFiltrowanych.clear();
}

int Wpis::getIndexAktualnegoWpisuFiltr()
{
    return indexAktualnegoFiltr;
}

bool Wpis::sprawdzCzyMoznaOdfiltrowac(rodzajWspomnienia rodzajWspomnienia)
{
    bool czyMozna = false;
    if(listaWszystkichWpisow.size() > 0){
    for(int i=0;i<listaWszystkichWpisow.size();i++)
    {
        if(listaWszystkichWpisow[i].getRodzajWspomnienia() == rodzajWspomnienia)
        {
            czyMozna = true;
            break;
        }
    }
    }
    return czyMozna;
}

void Wpis::wydzielWpisy(rodzajWspomnienia rodzajWpisu)
{
    for(int i=0;i<listaWszystkichWpisow.size();i++)
    {
        if(listaWszystkichWpisow[i].getRodzajWspomnienia() == rodzajWpisu){
            listaWpisowFiltrowanych.push_back(listaWszystkichWpisow[i]);
        }

        indexAktualnegoFiltr = listaWpisowFiltrowanych.size() - 1;

    }

}

void Wpis::setToList(Wpis pojedynczyWpis)
{
    for(QList<Wpis>::Iterator iter = listaWszystkichWpisow.begin();iter!=listaWszystkichWpisow.end();++iter)
    {
       if(*iter == pojedynczyWpis)
       {
          listaWszystkichWpisow.replace(std::distance(listaWszystkichWpisow.begin(),iter),pojedynczyWpis);
          std::sort(listaWszystkichWpisow.begin(),listaWszystkichWpisow.end(),[](Wpis a, Wpis b){return a < b;});
          return;
       }
     }
     listaWszystkichWpisow.push_back(pojedynczyWpis);
     std::sort(listaWszystkichWpisow.begin(),listaWszystkichWpisow.end(),[](Wpis a, Wpis b){return a < b;});
     indexAktualnego = listaWszystkichWpisow.indexOf(pojedynczyWpis);
}
Wpis::~Wpis(){

}


