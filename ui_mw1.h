/********************************************************************************
** Form generated from reading UI file 'mw1.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MW1_H
#define UI_MW1_H

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

class Ui_MW1
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MW1)
    {
        if (MW1->objectName().isEmpty())
            MW1->setObjectName(QStringLiteral("MW1"));
        MW1->resize(1877, 1012);
        centralwidget = new QWidget(MW1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1610, 60, 231, 61));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1620, 240, 241, 51));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(1630, 150, 221, 61));
        pushButton_3->setFlat(true);
        MW1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MW1);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1877, 30));
        MW1->setMenuBar(menubar);
        statusbar = new QStatusBar(MW1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MW1->setStatusBar(statusbar);

        retranslateUi(MW1);

        QMetaObject::connectSlotsByName(MW1);
    } // setupUi

    void retranslateUi(QMainWindow *MW1)
    {
        MW1->setWindowTitle(QApplication::translate("MW1", "MainWindow", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MW1: public Ui_MW1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MW1_H
