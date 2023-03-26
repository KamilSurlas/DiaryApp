#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include "wpis.h"
#include <QMessageBox>
#include "nowewpisy.h"
#include "qmainwindow.h"
#include "obslugaplikow.h"
#include "enum.h"
#include <QException>
#include <exception>
class ObslugaPlikow;
class noweWpisy;
class MainWindow;
class Program : public QObject
{
    Q_OBJECT
public:
    explicit Program(QObject *parent = nullptr);
    void setGUI(MainWindow *ui = nullptr) {GUI = ui;}
    void dodajNowyWpis();
    int getIloscFiltrowanych();
    void zmniejszIndexFiltr();
    void zwiekszIndexFiltr();
    int getIndexAktualnegoWpisu();
    int getIndexAktFiltr();
    int getIloscWpisow();
    void zmniejszIndex();
    void zwiekszIndex();
    void usunWpis();
    void aktualizajWpisy();
    void edytujWpis(QString nowaTresc,QDateTime nowaData);
    void wczytajZPliku(QString nazwaPliku = "Wpisy.txt");
    void zapiszDoPliku(QString nazwaPliku = "Wpisy.txt"); 
    void wpiszSmutne();
    void wpiszNeutralne();
    void wpiszRadosne();
    void wyczyscFiltry();
    void usunPlikZWpisami();
    void aktualizujIndexy(kierunekPrzewijania kier);
    bool czyMoznaFiltrowac(rodzajWspomnienia rodzaj);
    void wybierzSciezke();
    void usunFiltr(rodzajWspomnienia rodzaj);
signals:
    void wypiszWpisy(QString wpisAktualny,QString WpisPoprzedni,QString WpisNastepny);
    void dodanoWpis();
    void bladDodaniaWpisu();
    void usunietoWpis();
    void edytowanoWpis();
    void wpisyWczytane();
    void wpisowBrak();
    void brakBackupa();
    void zapisanoWpisy();
    void filtrSmutne();
    void filtrNeutralne();
    void filtrRadosne();
    void wybranoSciezke(QString sciezka);

private:
    MainWindow *GUI = nullptr;
    noweWpisy *GUINowychWpisow = nullptr;
};


#endif // PROGRAM_H
