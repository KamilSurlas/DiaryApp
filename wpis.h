#ifndef WPIS_H
#define WPIS_H
#include <QObject>
#include <qdatetime.h>
#include <QList>
#include <QVector>
#include "enum.h"
#include <QFont>
#include <QException>
#include <exception>
class Wpis
{
public:
    Wpis(QDateTime data_czas,QString nowyWpis,rodzajWspomnienia rodzajWspomnienia);
    Wpis();
    void setTresc(QString tresc);
    ~Wpis();
    QString getWpis();
    QDateTime getData_Czas();
    rodzajWspomnienia getRodzajWspomnienia();
    bool operator==(const Wpis& prawyOperand) const;
    bool operator!=(const Wpis& prawyOperand) const;
    bool operator<(const Wpis& prawyOperand) const;
    static void setToList(Wpis pojedynczyWpis);
    QString przygotujDoZapisania();
    explicit operator QString();
    static int getIndex();
    static QList<Wpis> getListaWpisow();
    static QList<Wpis> getListaWpisowFiltrowanych();
    static void zmniejszInd();
    static void zwiekszInd();
    static void setIndexAkt(int index);
    static void zmniejszIndFiltr();
    static void zwiekszIndFiltr();
    static void usun();
    static int getIloscWpisow();
    static void usunFiltr(rodzajWspomnienia rodzajWpisu);
    static int getIloscWpisowFiltrowanych();
    static Wpis getWpis(int index);
    static Wpis getWpisZListyFiltrowanej(int index);
    static void wyczyscWpisy();
    static void wyczyscWpisyFiltrowane();
    static int getIndexAktualnegoWpisuFiltr();
    static bool sprawdzCzyMoznaOdfiltrowac(rodzajWspomnienia rodzajWspomnienia);
    static void wydzielWpisy(rodzajWspomnienia rodzajWpisu);
private:
    static int indexAktualnegoFiltr;
    static int indexAktualnego;
    static QList<Wpis> listaWszystkichWpisow;
    static QList<Wpis> listaWpisowFiltrowanych;
    QString m_wpis;
    QDateTime m_data_czas;
    rodzajWspomnienia m_rodzajWspomnienia;
};

#endif // WPIS_H
