#include "nowewpisy.h"
#include "ui_nowewpisy.h"

noweWpisy::noweWpisy(daneNowegoWpisu &dane,QWidget *parent) :
    QDialog(parent),m_dane(&dane),ui(new Ui::noweWpisy)
{
    ui->setupUi(this);
    ui->ustawDATE_GODZINE->setDateTime(QDateTime(QDate(QDate::currentDate()),QTime(QTime::currentTime().hour(),QTime::currentTime().minute(),0)));

}
noweWpisy::~noweWpisy()
{
    delete ui;
}


void noweWpisy::on_dodajWpis_clicked()
{
    if(ui->wpisNeutralny->isChecked() || ui->wpisRadosny->isChecked() || ui->wpisSmutny->isChecked())
    {
    if(!ui->nowyWpis->document()->isEmpty())
    {
    m_dane->data = ui->ustawDATE_GODZINE->dateTime();
    m_dane->tekst = ui->nowyWpis->toPlainText();

    ui->nowyWpis->clear();
    }
    }
    deleteLater();
}


void noweWpisy::on_przyciskAnuluj_clicked()
{
    deleteLater();
}


void noweWpisy::on_wpisNeutralny_clicked()
{
    ui->wpisRadosny->setCheckState(Qt::Unchecked);
    ui->wpisSmutny->setCheckState(Qt::Unchecked);
    m_dane->rodzajWspomnienia = rodzajWspomnienia::Neutralne;
}


void noweWpisy::on_wpisSmutny_clicked()
{
    ui->wpisNeutralny->setCheckState(Qt::Unchecked);
    ui->wpisRadosny->setCheckState(Qt::Unchecked);
    m_dane->rodzajWspomnienia = rodzajWspomnienia::Smutne;
}


void noweWpisy::on_wpisRadosny_clicked()
{
    ui->wpisNeutralny->setCheckState(Qt::Unchecked);
    ui->wpisSmutny->setCheckState(Qt::Unchecked);
    m_dane->rodzajWspomnienia = rodzajWspomnienia::Radosne;
}

