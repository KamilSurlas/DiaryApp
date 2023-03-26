/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QStackedWidget *stackedWidget;
    QWidget *strStartowa;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QToolButton *doGory;
    QToolButton *naDol;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QTextEdit *wpisPoprzedni;
    QTextEdit *wpisAktualny;
    QTextEdit *wpisNastepny;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *pokazWszystko;
    QCheckBox *pokazSmutne;
    QCheckBox *pokazNeutralne;
    QCheckBox *pokazRadosne;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *zakonczPrzycisk;
    QLineEdit *szukajWpisu;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *edytujWpis;
    QPushButton *dodajNowyWpis;
    QPushButton *usunWpis;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *wybierzSciezke;
    QLineEdit *sciezkaBackup;
    QPushButton *zapiszBackup;
    QPushButton *wczytajBackup;
    QLabel *komunikaty;
    QWidget *strEdycja;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *wpisEdycja;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QDateTimeEdit *dataEdycja;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *zapiszEdycja;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *anulujEdycja;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(920, 695);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setFocusPolicy(Qt::StrongFocus);
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        strStartowa = new QWidget();
        strStartowa->setObjectName(QString::fromUtf8("strStartowa"));
        verticalLayout_7 = new QVBoxLayout(strStartowa);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(35, 160, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_3->addItem(verticalSpacer_2);

        doGory = new QToolButton(strStartowa);
        doGory->setObjectName(QString::fromUtf8("doGory"));
        sizePolicy.setHeightForWidth(doGory->sizePolicy().hasHeightForWidth());
        doGory->setSizePolicy(sizePolicy);
        doGory->setArrowType(Qt::UpArrow);

        verticalLayout_3->addWidget(doGory);

        naDol = new QToolButton(strStartowa);
        naDol->setObjectName(QString::fromUtf8("naDol"));
        sizePolicy.setHeightForWidth(naDol->sizePolicy().hasHeightForWidth());
        naDol->setSizePolicy(sizePolicy);
        naDol->setFocusPolicy(Qt::ClickFocus);
        naDol->setArrowType(Qt::DownArrow);

        verticalLayout_3->addWidget(naDol);

        verticalSpacer = new QSpacerItem(35, 160, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        wpisPoprzedni = new QTextEdit(strStartowa);
        wpisPoprzedni->setObjectName(QString::fromUtf8("wpisPoprzedni"));
        wpisPoprzedni->setReadOnly(true);

        verticalLayout->addWidget(wpisPoprzedni);

        wpisAktualny = new QTextEdit(strStartowa);
        wpisAktualny->setObjectName(QString::fromUtf8("wpisAktualny"));
        wpisAktualny->setReadOnly(true);

        verticalLayout->addWidget(wpisAktualny);

        wpisNastepny = new QTextEdit(strStartowa);
        wpisNastepny->setObjectName(QString::fromUtf8("wpisNastepny"));
        wpisNastepny->setReadOnly(true);

        verticalLayout->addWidget(wpisNastepny);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pokazWszystko = new QCheckBox(strStartowa);
        pokazWszystko->setObjectName(QString::fromUtf8("pokazWszystko"));
        sizePolicy.setHeightForWidth(pokazWszystko->sizePolicy().hasHeightForWidth());
        pokazWszystko->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(pokazWszystko);

        pokazSmutne = new QCheckBox(strStartowa);
        pokazSmutne->setObjectName(QString::fromUtf8("pokazSmutne"));
        sizePolicy.setHeightForWidth(pokazSmutne->sizePolicy().hasHeightForWidth());
        pokazSmutne->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(pokazSmutne);

        pokazNeutralne = new QCheckBox(strStartowa);
        pokazNeutralne->setObjectName(QString::fromUtf8("pokazNeutralne"));
        sizePolicy.setHeightForWidth(pokazNeutralne->sizePolicy().hasHeightForWidth());
        pokazNeutralne->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(pokazNeutralne);

        pokazRadosne = new QCheckBox(strStartowa);
        pokazRadosne->setObjectName(QString::fromUtf8("pokazRadosne"));
        sizePolicy.setHeightForWidth(pokazRadosne->sizePolicy().hasHeightForWidth());
        pokazRadosne->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(pokazRadosne);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_7->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_7->addItem(verticalSpacer_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        zakonczPrzycisk = new QPushButton(strStartowa);
        zakonczPrzycisk->setObjectName(QString::fromUtf8("zakonczPrzycisk"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(zakonczPrzycisk->sizePolicy().hasHeightForWidth());
        zakonczPrzycisk->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(zakonczPrzycisk);

        szukajWpisu = new QLineEdit(strStartowa);
        szukajWpisu->setObjectName(QString::fromUtf8("szukajWpisu"));
        sizePolicy.setHeightForWidth(szukajWpisu->sizePolicy().hasHeightForWidth());
        szukajWpisu->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        szukajWpisu->setFont(font);
        szukajWpisu->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(szukajWpisu);

        horizontalLayout_7->setStretch(1, 30);
        horizontalLayout_7->setStretch(2, 30);

        verticalLayout_7->addLayout(horizontalLayout_7);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        edytujWpis = new QPushButton(strStartowa);
        edytujWpis->setObjectName(QString::fromUtf8("edytujWpis"));
        edytujWpis->setEnabled(false);
        sizePolicy.setHeightForWidth(edytujWpis->sizePolicy().hasHeightForWidth());
        edytujWpis->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(edytujWpis);

        dodajNowyWpis = new QPushButton(strStartowa);
        dodajNowyWpis->setObjectName(QString::fromUtf8("dodajNowyWpis"));
        sizePolicy.setHeightForWidth(dodajNowyWpis->sizePolicy().hasHeightForWidth());
        dodajNowyWpis->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(dodajNowyWpis);

        usunWpis = new QPushButton(strStartowa);
        usunWpis->setObjectName(QString::fromUtf8("usunWpis"));
        sizePolicy.setHeightForWidth(usunWpis->sizePolicy().hasHeightForWidth());
        usunWpis->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(usunWpis);

        horizontalLayout->setStretch(0, 40);
        horizontalLayout->setStretch(1, 30);
        horizontalLayout->setStretch(2, 30);
        horizontalLayout->setStretch(3, 30);

        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_7->addLayout(verticalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        wybierzSciezke = new QPushButton(strStartowa);
        wybierzSciezke->setObjectName(QString::fromUtf8("wybierzSciezke"));

        horizontalLayout_5->addWidget(wybierzSciezke);

        sciezkaBackup = new QLineEdit(strStartowa);
        sciezkaBackup->setObjectName(QString::fromUtf8("sciezkaBackup"));

        horizontalLayout_5->addWidget(sciezkaBackup);

        zapiszBackup = new QPushButton(strStartowa);
        zapiszBackup->setObjectName(QString::fromUtf8("zapiszBackup"));
        sizePolicy.setHeightForWidth(zapiszBackup->sizePolicy().hasHeightForWidth());
        zapiszBackup->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(zapiszBackup);

        wczytajBackup = new QPushButton(strStartowa);
        wczytajBackup->setObjectName(QString::fromUtf8("wczytajBackup"));
        sizePolicy.setHeightForWidth(wczytajBackup->sizePolicy().hasHeightForWidth());
        wczytajBackup->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(wczytajBackup);


        verticalLayout_7->addLayout(horizontalLayout_5);

        komunikaty = new QLabel(strStartowa);
        komunikaty->setObjectName(QString::fromUtf8("komunikaty"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka Subheading")});
        font1.setPointSize(12);
        komunikaty->setFont(font1);
        komunikaty->setFocusPolicy(Qt::NoFocus);
        komunikaty->setLayoutDirection(Qt::LeftToRight);
        komunikaty->setTextFormat(Qt::PlainText);
        komunikaty->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(komunikaty);

        stackedWidget->addWidget(strStartowa);
        strEdycja = new QWidget();
        strEdycja->setObjectName(QString::fromUtf8("strEdycja"));
        verticalLayout_6 = new QVBoxLayout(strEdycja);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        wpisEdycja = new QTextEdit(strEdycja);
        wpisEdycja->setObjectName(QString::fromUtf8("wpisEdycja"));

        verticalLayout_4->addWidget(wpisEdycja);

        verticalSpacer_5 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        dataEdycja = new QDateTimeEdit(strEdycja);
        dataEdycja->setObjectName(QString::fromUtf8("dataEdycja"));
        sizePolicy.setHeightForWidth(dataEdycja->sizePolicy().hasHeightForWidth());
        dataEdycja->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(dataEdycja);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        zapiszEdycja = new QPushButton(strEdycja);
        zapiszEdycja->setObjectName(QString::fromUtf8("zapiszEdycja"));
        sizePolicy.setHeightForWidth(zapiszEdycja->sizePolicy().hasHeightForWidth());
        zapiszEdycja->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(zapiszEdycja);

        horizontalSpacer_3 = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        anulujEdycja = new QPushButton(strEdycja);
        anulujEdycja->setObjectName(QString::fromUtf8("anulujEdycja"));
        sizePolicy.setHeightForWidth(anulujEdycja->sizePolicy().hasHeightForWidth());
        anulujEdycja->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(anulujEdycja);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalLayout_4->setStretch(0, 200);
        verticalLayout_4->setStretch(1, 10);
        verticalLayout_4->setStretch(2, 30);

        verticalLayout_6->addLayout(verticalLayout_4);

        stackedWidget->addWidget(strEdycja);

        verticalLayout_5->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 920, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        doGory->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        naDol->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pokazWszystko->setText(QCoreApplication::translate("MainWindow", "WSZYSTKO", nullptr));
        pokazSmutne->setText(QCoreApplication::translate("MainWindow", "WPISY SMUTNE", nullptr));
        pokazNeutralne->setText(QCoreApplication::translate("MainWindow", "WPISY NEUTRALNE", nullptr));
        pokazRadosne->setText(QCoreApplication::translate("MainWindow", "WPISY RADOSNE", nullptr));
        zakonczPrzycisk->setText(QCoreApplication::translate("MainWindow", "ZAKO\305\203CZ SZUKANIE", nullptr));
        edytujWpis->setText(QCoreApplication::translate("MainWindow", "EDYTUJ WPIS AKTUALNY", nullptr));
        dodajNowyWpis->setText(QCoreApplication::translate("MainWindow", "DODAJ NOWY WPIS", nullptr));
        usunWpis->setText(QCoreApplication::translate("MainWindow", "USU\305\203 WPIS AKTUALNY", nullptr));
        wybierzSciezke->setText(QCoreApplication::translate("MainWindow", "WYBIERZ SCIEZKE", nullptr));
        zapiszBackup->setText(QCoreApplication::translate("MainWindow", "ZAPISZ BACKUP", nullptr));
        wczytajBackup->setText(QCoreApplication::translate("MainWindow", "WCZYTAJ BACKUP", nullptr));
        komunikaty->setText(QString());
        zapiszEdycja->setText(QCoreApplication::translate("MainWindow", "ZAPISZ I WR\303\223\304\206", nullptr));
        anulujEdycja->setText(QCoreApplication::translate("MainWindow", "ANULUJ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
