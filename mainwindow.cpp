#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdatetime.h"
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent,Program *program)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      glownaAplikacja(program)
{
    program->setGUI(this);
    if(glownaAplikacja->getIloscWpisow()>0)
    {
        ui->edytujWpis->setEnabled(true);

    }

    ui->setupUi(this);

    ui->szukajWpisu->setText("Szukaj w pamietniku");
    ui->stackedWidget->setCurrentIndex(0);
    ui->wpisNastepny->setText(QString("<span style=\" color:#ff0000;\">%1</span>").arg("BRAK NASTEPNEGO WPISU"));
    ui->wpisAktualny->setText(QString("<span style=\" color:#ff0000;\">%1</span>").arg("BRAK AKTUALNEGO WPISU"));
    ui->wpisPoprzedni->setText(QString("<span style=\" color:#ff0000;\">%1</span>").arg("BRAK POPRZEDNIEGO WPISU"));
    connect(program,SIGNAL(dodanoWpis()),this,SLOT(on_dodanoWpis_OK()));
    connect(program,SIGNAL(usunietoWpis()),this,SLOT(on_usunietoWpis_OK()));
    connect(program,SIGNAL(edytowanoWpis()),this,SLOT(on_edytowanoWpis_OK()));
    connect(program,SIGNAL(wpisyWczytane()),this,SLOT(on_wpisyWczytane_OK()));
    connect(program,SIGNAL(wpisowBrak()),this,SLOT(on_wpisyWczytane_FAIL()));
    connect(program,SIGNAL(zapisanoWpisy()),this,SLOT(on_zapisanoWpisy_OK()));
    connect(program,SIGNAL(bladDodaniaWpisu()),this,SLOT(on_dodanoWpis_FAIL()));
    connect(program,SIGNAL(filtrSmutne()),this,SLOT(on_filtrSmutne_OK()));
    connect(program,SIGNAL(filtrNeutralne()),this,SLOT(on_filtrNeutralne_OK()));
    connect(program,SIGNAL(filtrRadosne()),this,SLOT(on_filtrRadosne_OK()));
    connect(program,SIGNAL(wybranoSciezke(QString)),this,SLOT(on_wybranoSciezke_OK(QString)));
    connect(program,SIGNAL(wypiszWpisy(QString,QString,QString)),this,SLOT(on_wypiszWpisy_OK(QString,QString,QString)));
    glownaAplikacja->wczytajZPliku();
    if(glownaAplikacja->getIloscWpisow() > 0){
        ui->pokazWszystko->setCheckState(Qt::Checked);
    }
}
MainWindow::~MainWindow()
{
    glownaAplikacja->zapiszDoPliku();
    delete ui;
}

void MainWindow::on_dodajNowyWpis_clicked()
{
    glownaAplikacja->dodajNowyWpis();
}
void MainWindow::on_doGory_clicked()
{
   glownaAplikacja->aktualizujIndexy(kierunekPrzewijania::WGore);
   glownaAplikacja->aktualizajWpisy();
}
void MainWindow::on_naDol_clicked()
{
   glownaAplikacja->aktualizujIndexy(kierunekPrzewijania::NaDol);
   glownaAplikacja->aktualizajWpisy();
}

void MainWindow::on_usunWpis_clicked()
{  
    try {
        glownaAplikacja->usunWpis();
    }  catch (...) {
        ui->wpisAktualny->setText(QString("<span style=\" color:#ff0000;\">%1</span>").arg("BRAK AKTUALNEGO WPISU"));
        glownaAplikacja->usunPlikZWpisami();
        ui->komunikaty->setText("Usunieto ostatni wpis!");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *przycisk)
{
    switch(przycisk->key())
    {
    case Qt::Key_Up:
        on_doGory_clicked(); break;
    case Qt::Key_Down:
        on_naDol_clicked(); break;
    case Qt::Key_Delete:
        on_usunWpis_clicked(); break;
    }
}

void MainWindow::on_edytujWpis_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->wpisEdycja->setText(Wpis::getWpis(Wpis::getIndex()).getWpis());
    ui->dataEdycja->setDateTime(Wpis::getWpis(Wpis::getIndex()).getData_Czas());
}
void MainWindow::on_zapiszEdycja_clicked()
{
    if(ui->wpisEdycja->toPlainText() != Wpis::getWpis(Wpis::getIndex()).getWpis() || ui->dataEdycja->dateTime() != Wpis::getWpis(Wpis::getIndex()).getData_Czas()){
        glownaAplikacja->edytujWpis(ui->wpisEdycja->toPlainText(),ui->dataEdycja->dateTime());
    }
}


void MainWindow::on_anulujEdycja_clicked()
{
    ui->komunikaty->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if(event->angleDelta().y() > 0)
    {
        on_doGory_clicked();
    }
    else
    {
        on_naDol_clicked();
    }
}

void MainWindow::szukajWPamietniku()
{
    QString szukanyTekst = ui->szukajWpisu->text();
    QTextDocument *wpisA = ui->wpisAktualny->document();
    QTextDocument *wpisP = ui->wpisPoprzedni->document();
    QTextDocument *wpisN = ui->wpisNastepny->document();
    QTextDocument *wpisy[3] = {wpisA,wpisP,wpisN};
    QTextCursor glowicaA(wpisy[0]);
    QTextCursor glowicaP(wpisy[1]);
    QTextCursor glowicaN(wpisy[2]);
    QTextCursor glowice[3] = {glowicaA,glowicaP,glowicaN};
    QTextCharFormat czcionka;
    czcionka.setForeground(Qt::red);
    for(int i=0;i<3;i++)
    {
        wpisy[i]->undo();
        while(!glowice[i].isNull() && !glowice[i].atEnd())
        { 
            glowice[i] = wpisy[i]->find(szukanyTekst,glowice[i]);
            if(!glowice[i].isNull())
            {
                glowice[i].mergeCharFormat(czcionka);              
            }
        }

    }
}


void MainWindow::on_szukajWpisu_selectionChanged()
{
    czySzukac = true;
    ui->komunikaty->clear();
    ui->szukajWpisu->clear();
}
void MainWindow::on_szukajWpisu_textChanged()
{
    szukajWPamietniku();
}
void MainWindow::on_zakonczPrzycisk_clicked()
{
    czySzukac = false;
    glownaAplikacja->aktualizajWpisy();
    ui->komunikaty->setText("Zakonczono szukanie");
    ui->szukajWpisu->setText("Szukaj w pamietniku");
}

void MainWindow::on_dodanoWpis_OK()
{
    glownaAplikacja->aktualizajWpisy();
    if(glownaAplikacja->getIloscWpisow()== 1){
        ui->pokazWszystko->setCheckState(Qt::Checked);
    }
    ui->edytujWpis->setEnabled(true);
    ui->komunikaty->setText("dodano wpis");
}

void MainWindow::on_usunietoWpis_OK()
{  
    ui->komunikaty->setText("Usunieto wpis [" + QString::number(glownaAplikacja->getIndexAktualnegoWpisu()) + "]");
    glownaAplikacja->aktualizajWpisy();
}

void MainWindow::on_edytowanoWpis_OK()
{
    ui->komunikaty->setText("Pomyslnie edytowano wpis");
    glownaAplikacja->aktualizajWpisy();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_wpisyWczytane_OK()
{
    glownaAplikacja->aktualizajWpisy();
    ui->komunikaty->setText("wczytano wpisy");
}

void MainWindow::on_wpisyWczytane_FAIL()
{
    ui->komunikaty->setText("brak pliku z wpisami");
}

void MainWindow::on_zapisanoWpisy_OK()
{
    ui->komunikaty->setText("zapisano wpisy");
}

void MainWindow::on_dodanoWpis_FAIL()
{
    ui->komunikaty->setText("Blad dodania wpisu. Upewnij sie ze podales tresc wpisu oraz rodzaj wspomnienia");
}

void MainWindow::on_filtrSmutne_OK()
{
    glownaAplikacja->aktualizajWpisy();
}

void MainWindow::on_filtrNeutralne_OK()
{
    glownaAplikacja->aktualizajWpisy();
}

void MainWindow::on_filtrRadosne_OK()
{
    glownaAplikacja->aktualizajWpisy();
}
void MainWindow::on_wczytajBackup_clicked()
{
    if(!ui->sciezkaBackup->text().isEmpty()){
        QMessageBox okienkoInformacje;
        okienkoInformacje.setText("Uwaga!");
        okienkoInformacje.setInformativeText("Wczytanie backup'u spowoduje utrate aktualnych wpisow. Czy mimo tego chcesz kontynuować?");
        okienkoInformacje.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        okienkoInformacje.setIcon(QMessageBox::Warning);
        try {
            switch(okienkoInformacje.exec())
            {

            case QMessageBox::Yes: glownaAplikacja->wczytajZPliku(ui->sciezkaBackup->text());

                break;
            case QMessageBox::No: break;

            }
        }  catch (...) {
            ui->komunikaty->setText("Brak wpisow w backup'ie");
        }

    }
}

void MainWindow::on_wybranoSciezke_OK(QString sciezka)
{
    if(!sciezka.isEmpty())
        ui->sciezkaBackup->setText(sciezka);
}
void MainWindow::on_zapiszBackup_clicked()
{
    if(!ui->sciezkaBackup->text().isEmpty())
        glownaAplikacja->zapiszDoPliku(ui->sciezkaBackup->text());
}


void MainWindow::on_pokazWszystko_clicked()
{
    if(glownaAplikacja->getIloscWpisow() > 0){
    glownaAplikacja->wyczyscFiltry();
    ui->pokazNeutralne->setCheckState(Qt::Unchecked);
    ui->pokazRadosne->setCheckState(Qt::Unchecked);
    ui->pokazSmutne->setCheckState(Qt::Unchecked);
    if(glownaAplikacja->getIloscWpisow() > 0)
        glownaAplikacja->aktualizajWpisy();
     } else {
        ui->pokazWszystko->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_wypiszWpisy_OK(QString wpisAktualny,QString wpisPoprzedni,QString wpisNastepny)
{
    ui->wpisAktualny->setText(wpisAktualny);
    ui->wpisNastepny->setText(wpisNastepny);
    ui->wpisPoprzedni->setText(wpisPoprzedni);
    if(czySzukac)
        szukajWPamietniku();
}
void MainWindow::on_pokazSmutne_clicked()
{
    if(glownaAplikacja->czyMoznaFiltrowac(rodzajWspomnienia::Smutne)){
        if(ui->pokazSmutne->isChecked())
        {
            if(ui->pokazNeutralne->isChecked() && ui->pokazRadosne->isChecked()){
                ui->pokazWszystko->setCheckState(Qt::Checked);
                on_pokazWszystko_clicked();
                ui->pokazNeutralne->setCheckState(Qt::Unchecked);
                ui->pokazRadosne->setCheckState(Qt::Unchecked);
                ui->pokazSmutne->setCheckState(Qt::Unchecked);
            } else {
                ui->pokazWszystko->setCheckState(Qt::Unchecked);
                glownaAplikacja->wpiszSmutne();
            }
        }
        else if(!ui->pokazNeutralne->isChecked() && !ui->pokazRadosne->isChecked()){
            ui->pokazWszystko->setCheckState(Qt::Checked);
            on_pokazWszystko_clicked();
        } else {
            glownaAplikacja->usunFiltr(rodzajWspomnienia::Smutne);
        }
    }
    else{

        ui->pokazSmutne->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_pokazNeutralne_clicked()
{
    if(glownaAplikacja->czyMoznaFiltrowac(rodzajWspomnienia::Neutralne)){
        if(ui->pokazNeutralne->isChecked())
        {
            if(ui->pokazRadosne->isChecked() && ui->pokazSmutne->isChecked()){
                ui->pokazWszystko->setCheckState(Qt::Checked);
                on_pokazWszystko_clicked();
                ui->pokazNeutralne->setCheckState(Qt::Unchecked);
                ui->pokazRadosne->setCheckState(Qt::Unchecked);
                ui->pokazSmutne->setCheckState(Qt::Unchecked);
            } else {
                ui->pokazWszystko->setCheckState(Qt::Unchecked);
                glownaAplikacja->wpiszNeutralne();
            }
        }else if(!ui->pokazRadosne->isChecked() && !ui->pokazSmutne->isChecked()){
            ui->pokazWszystko->setCheckState(Qt::Checked);
            on_pokazWszystko_clicked();
        } else {
            glownaAplikacja->usunFiltr(rodzajWspomnienia::Neutralne);
        }

    }
    else {
        ui->pokazNeutralne->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_pokazRadosne_clicked()
{
    if(glownaAplikacja->czyMoznaFiltrowac(rodzajWspomnienia::Smutne)){
        if(ui->pokazRadosne->isChecked())
        {   if(ui->pokazNeutralne->isChecked() && ui->pokazSmutne->isChecked()){
                ui->pokazWszystko->setCheckState(Qt::Checked);
                on_pokazWszystko_clicked();
                ui->pokazNeutralne->setCheckState(Qt::Unchecked);
                ui->pokazRadosne->setCheckState(Qt::Unchecked);
                ui->pokazSmutne->setCheckState(Qt::Unchecked);
            } else {
                ui->pokazWszystko->setCheckState(Qt::Unchecked);
                glownaAplikacja->wpiszRadosne();
            }
        } else if(!ui->pokazNeutralne->isChecked() && !ui->pokazSmutne->isChecked()){
            ui->pokazWszystko->setCheckState(Qt::Checked);
            on_pokazWszystko_clicked();
        } else {
            glownaAplikacja->usunFiltr(rodzajWspomnienia::Radosne);
        }
    } else{
        ui->pokazRadosne->setCheckState(Qt::Unchecked);
    }
}
void MainWindow::on_wybierzSciezke_clicked()
{
    glownaAplikacja->wybierzSciezke();
    ui->komunikaty->setText("Wybrano sciezke");
}


