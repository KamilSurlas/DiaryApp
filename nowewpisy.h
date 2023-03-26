#ifndef NOWEWPISY_H
#define NOWEWPISY_H

#include <QDialog>
#include <QCheckBox>
#include <QVector>
#include "enum.h"
#include "program.h"
#include "wpis.h"
class Program;
namespace Ui {

class noweWpisy;
}
struct daneNowegoWpisu
{
    QString tekst;
    QDateTime data;
    rodzajWspomnienia rodzajWspomnienia;
};



class noweWpisy : public QDialog
{
    Q_OBJECT

public:
    explicit noweWpisy(daneNowegoWpisu &dane, QWidget *parent = nullptr);
    ~noweWpisy();
private slots:
    void on_dodajWpis_clicked();
    void on_przyciskAnuluj_clicked();

    void on_wpisNeutralny_clicked();

    void on_wpisSmutny_clicked();

    void on_wpisRadosny_clicked();

private:
    daneNowegoWpisu *m_dane = nullptr;
    Ui::noweWpisy *ui;
};

#endif // NOWEWPISY_H
