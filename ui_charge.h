/********************************************************************************
** Form generated from reading UI file 'charge.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGE_H
#define UI_CHARGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Charge
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Charge)
    {
        if (Charge->objectName().isEmpty())
            Charge->setObjectName(QStringLiteral("Charge"));
        Charge->resize(640, 480);
        centralwidget = new QWidget(Charge);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 151, 71));
        pushButton->setFlat(true);
        Charge->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Charge);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 30));
        Charge->setMenuBar(menubar);
        statusbar = new QStatusBar(Charge);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Charge->setStatusBar(statusbar);

        retranslateUi(Charge);

        QMetaObject::connectSlotsByName(Charge);
    } // setupUi

    void retranslateUi(QMainWindow *Charge)
    {
        Charge->setWindowTitle(QApplication::translate("Charge", "MainWindow", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Charge: public Ui_Charge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGE_H
