#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "wpis.h"
#include <QMainWindow>
#include <exception>
#include <QFileDialog>
#include "QDebug"
#include <QKeyEvent>
#include <QFile>
#include <QWheelEvent>
#include <QTextCursor>
#include <QTextDocument>
#include "nowewpisy.h"
#include "program.h"
#include "algorithm"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class Program;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,Program *program = nullptr);
    ~MainWindow();

private slots:
    void on_dodajNowyWpis_clicked();
    void on_doGory_clicked();
    void on_naDol_clicked();

    void on_usunWpis_clicked();

    void on_edytujWpis_clicked();

    void on_zapiszEdycja_clicked();

    void on_anulujEdycja_clicked();

    void on_szukajWpisu_selectionChanged();

    void on_szukajWpisu_textChanged();

   void on_zakonczPrzycisk_clicked();

    void on_dodanoWpis_OK();
    void on_usunietoWpis_OK();
    void on_edytowanoWpis_OK();
    void on_wpisyWczytane_OK();
    void on_wpisyWczytane_FAIL();
    void on_zapisanoWpisy_OK();
    void on_dodanoWpis_FAIL();
    void on_filtrSmutne_OK();
    void on_filtrNeutralne_OK();
    void on_filtrRadosne_OK();
    void on_wczytajBackup_clicked();
    void on_wybranoSciezke_OK(QString sciezka);
    void on_zapiszBackup_clicked();

    void on_pokazWszystko_clicked();
    void on_wypiszWpisy_OK(QString wpisAktualny,QString wpisPoprzedni,QString wpisNastepny);
    void on_pokazSmutne_clicked();

    void on_pokazNeutralne_clicked();

    void on_pokazRadosne_clicked();
    void on_wybierzSciezke_clicked();

private:
    bool czySzukac = false;
    void wheelEvent(QWheelEvent *event) override;
    void szukajWPamietniku();
    void keyPressEvent(QKeyEvent* przycisk) override;
    Ui::MainWindow *ui;
    Program *glownaAplikacja = nullptr;
};
#endif // MAINWINDOW_H
