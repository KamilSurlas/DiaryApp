/********************************************************************************
** Form generated from reading UI file 'nowewpisy.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOWEWPISY_H
#define UI_NOWEWPISY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_noweWpisy
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *nowyWpis;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *wpisSmutny;
    QCheckBox *wpisNeutralny;
    QCheckBox *wpisRadosny;
    QHBoxLayout *horizontalLayout_2;
    QDateTimeEdit *ustawDATE_GODZINE;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *dodajWpis;
    QPushButton *przyciskAnuluj;

    void setupUi(QDialog *noweWpisy)
    {
        if (noweWpisy->objectName().isEmpty())
            noweWpisy->setObjectName(QString::fromUtf8("noweWpisy"));
        noweWpisy->resize(1012, 826);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(noweWpisy->sizePolicy().hasHeightForWidth());
        noweWpisy->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(noweWpisy);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(noweWpisy);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tahoma")});
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        nowyWpis = new QTextEdit(noweWpisy);
        nowyWpis->setObjectName(QString::fromUtf8("nowyWpis"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nowyWpis->sizePolicy().hasHeightForWidth());
        nowyWpis->setSizePolicy(sizePolicy1);
        nowyWpis->setMinimumSize(QSize(0, 0));
        nowyWpis->setMaximumSize(QSize(16000, 16000));

        verticalLayout->addWidget(nowyWpis);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        wpisSmutny = new QCheckBox(noweWpisy);
        wpisSmutny->setObjectName(QString::fromUtf8("wpisSmutny"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wpisSmutny->sizePolicy().hasHeightForWidth());
        wpisSmutny->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(wpisSmutny);

        wpisNeutralny = new QCheckBox(noweWpisy);
        wpisNeutralny->setObjectName(QString::fromUtf8("wpisNeutralny"));
        sizePolicy2.setHeightForWidth(wpisNeutralny->sizePolicy().hasHeightForWidth());
        wpisNeutralny->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(wpisNeutralny);

        wpisRadosny = new QCheckBox(noweWpisy);
        wpisRadosny->setObjectName(QString::fromUtf8("wpisRadosny"));
        sizePolicy2.setHeightForWidth(wpisRadosny->sizePolicy().hasHeightForWidth());
        wpisRadosny->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(wpisRadosny);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ustawDATE_GODZINE = new QDateTimeEdit(noweWpisy);
        ustawDATE_GODZINE->setObjectName(QString::fromUtf8("ustawDATE_GODZINE"));
        sizePolicy2.setHeightForWidth(ustawDATE_GODZINE->sizePolicy().hasHeightForWidth());
        ustawDATE_GODZINE->setSizePolicy(sizePolicy2);
        ustawDATE_GODZINE->setCurrentSection(QDateTimeEdit::YearSection);
        ustawDATE_GODZINE->setCalendarPopup(false);

        horizontalLayout_2->addWidget(ustawDATE_GODZINE);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        dodajWpis = new QPushButton(noweWpisy);
        dodajWpis->setObjectName(QString::fromUtf8("dodajWpis"));
        sizePolicy2.setHeightForWidth(dodajWpis->sizePolicy().hasHeightForWidth());
        dodajWpis->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(dodajWpis);

        przyciskAnuluj = new QPushButton(noweWpisy);
        przyciskAnuluj->setObjectName(QString::fromUtf8("przyciskAnuluj"));
        sizePolicy2.setHeightForWidth(przyciskAnuluj->sizePolicy().hasHeightForWidth());
        przyciskAnuluj->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(przyciskAnuluj);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2->setStretch(0, 30);
        horizontalLayout_2->setStretch(1, 70);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(1, 200);
        verticalLayout->setStretch(3, 30);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(noweWpisy);

        QMetaObject::connectSlotsByName(noweWpisy);
    } // setupUi

    void retranslateUi(QDialog *noweWpisy)
    {
        noweWpisy->setWindowTitle(QCoreApplication::translate("noweWpisy", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("noweWpisy", "DODAJ NOWY WPIS:", nullptr));
        wpisSmutny->setText(QCoreApplication::translate("noweWpisy", "WPIS SMUTNY", nullptr));
        wpisNeutralny->setText(QCoreApplication::translate("noweWpisy", "WPIS NEUTRALNY", nullptr));
        wpisRadosny->setText(QCoreApplication::translate("noweWpisy", "WPIS RADOSNY", nullptr));
        ustawDATE_GODZINE->setDisplayFormat(QCoreApplication::translate("noweWpisy", "yyyy-MM-dd HH:mm", nullptr));
        dodajWpis->setText(QCoreApplication::translate("noweWpisy", "DODAJ WPIS", nullptr));
        przyciskAnuluj->setText(QCoreApplication::translate("noweWpisy", "ANULUJ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class noweWpisy: public Ui_noweWpisy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOWEWPISY_H
