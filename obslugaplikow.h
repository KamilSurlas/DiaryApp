#ifndef OBSLUGAPLIKOW_H
#define OBSLUGAPLIKOW_H

#include <QWidget>
#include "wpis.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDateTime>
#include <QString>
#include "program.h"
class Program;
class ObslugaPlikow : public QWidget
{
    Q_OBJECT
public:
    explicit ObslugaPlikow(QWidget *parent = nullptr);
    int getOdczytanyIndex();
    bool czyZnalezionoPlik(QString nazwaPliku);
    void odczytajZPliku(QString nazwaPliku);
    void zapiszDoPliku(int indexAktualnegoWpisu, int iloscWpisow,QString nazwaPliku = "Wpisy.txt");
    void wybierzSciezke();
    void usunPlikZWpisami();
    QString getSciezkaDoBackupu();
signals:
    void wczytanoPlik(int index);
private:
    QString sciezkaBackup;
    QFile mojPlik;
    int odczytanyIndex;
};

#endif // OBSLUGAPLIKOW_H
