#include "obslugaplikow.h"
ObslugaPlikow::ObslugaPlikow(QWidget *parent)
    : QWidget(parent)
{

}

void ObslugaPlikow::odczytajZPliku(QString nazwaPliku)
{ 
    if(czyZnalezionoPlik(nazwaPliku)){      
        if(nazwaPliku == "Wpisy.txt")
         mojPlik.setFileName(QDir::currentPath() + "/" + nazwaPliku);       
        else
           mojPlik.setFileName(nazwaPliku);
         if(mojPlik.open(QIODevice::ReadOnly | QIODevice::Text))
         {
           {
                 QTextStream stream(&mojPlik);
                 odczytanyIndex= mojPlik.readLine().toInt();
                 while(stream.atEnd()==false)
                 {               
                     QDateTime odczytanaData = QDateTime::fromString(stream.readLine());
                     int rodzajWspomnienia = stream.readLine().toInt();
                     QString odczytanaNotatka = stream.readLine();
                     Wpis odczytanyWpis(odczytanaData,odczytanaNotatka,static_cast<enum rodzajWspomnienia>(rodzajWspomnienia));
                     Wpis::setToList(odczytanyWpis);
                 }
             }
             mojPlik.close();
     }
     }
}

void ObslugaPlikow::zapiszDoPliku(int indexAktualnegoWpisu, int iloscWpisow,QString nazwaPliku)
{
    {
        if(mojPlik.fileName().isEmpty()){
            if(nazwaPliku == "Wpisy.txt")
            mojPlik.setFileName(QDir::currentPath() + "/" + nazwaPliku);
            else mojPlik.setFileName(nazwaPliku);
        }
        if(mojPlik.open(QIODevice::WriteOnly  | QIODevice::Text))
        {
            QTextStream stream(&mojPlik);

            stream << indexAktualnegoWpisu << "\n";
            for(int i=0;i<iloscWpisow;i++){
                stream << Wpis::getListaWpisow()[i].przygotujDoZapisania() + "\n";
            }
            mojPlik.close();
        }
    }
}

void ObslugaPlikow::wybierzSciezke()
{
    QString nazPliku;
    nazPliku = QFileDialog::getOpenFileName(this,"Wskaż plik","","Plik tekstowy (*.txt)");
    sciezkaBackup = nazPliku;
}

void ObslugaPlikow::usunPlikZWpisami()
{
     QFileInfo info(QDir::currentPath() + "/" + "Wpisy.txt");
     if(info.isFile() && info.exists())
     QFile::remove(QDir::currentPath() + "/" + "Wpisy.txt");
}

QString ObslugaPlikow::getSciezkaDoBackupu()
{
    return sciezkaBackup;
}
int ObslugaPlikow::getOdczytanyIndex()
{
    return odczytanyIndex;
}
bool ObslugaPlikow::czyZnalezionoPlik(QString nazwaPliku)
{
    QFileInfo plik;
    if(nazwaPliku == "Wpisy.txt")
        plik.setFile(QDir::currentPath() + "/" + nazwaPliku);
    else plik.setFile(nazwaPliku);
    if(plik.isFile() && plik.exists())
        return true;
    else return false;
}


