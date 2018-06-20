/********************************************************************************
** Form generated from reading UI file 'choosegundam.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEGUNDAM_H
#define UI_CHOOSEGUNDAM_H

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

class Ui_ChooseGundam
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChooseGundam)
    {
        if (ChooseGundam->objectName().isEmpty())
            ChooseGundam->setObjectName(QStringLiteral("ChooseGundam"));
        ChooseGundam->resize(1821, 943);
        centralwidget = new QWidget(ChooseGundam);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 560, 191, 181));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(680, 560, 181, 181));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(1090, 560, 171, 181));
        pushButton_3->setFlat(true);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1470, 560, 161, 181));
        pushButton_4->setFlat(true);
        ChooseGundam->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChooseGundam);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1821, 30));
        ChooseGundam->setMenuBar(menubar);
        statusbar = new QStatusBar(ChooseGundam);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ChooseGundam->setStatusBar(statusbar);

        retranslateUi(ChooseGundam);

        QMetaObject::connectSlotsByName(ChooseGundam);
    } // setupUi

    void retranslateUi(QMainWindow *ChooseGundam)
    {
        ChooseGundam->setWindowTitle(QApplication::translate("ChooseGundam", "MainWindow", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChooseGundam: public Ui_ChooseGundam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEGUNDAM_H
