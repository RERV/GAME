/********************************************************************************
** Form generated from reading UI file 'startshow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTSHOW_H
#define UI_STARTSHOW_H

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

class Ui_StartShow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartShow)
    {
        if (StartShow->objectName().isEmpty())
            StartShow->setObjectName(QStringLiteral("StartShow"));
        StartShow->resize(1891, 1198);
        centralwidget = new QWidget(StartShow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1230, 620, 611, 81));
        pushButton->setStyleSheet(QLatin1String("font: 75 9pt \"Segoe UI\";\n"
"font: 87 9pt \"Arial Black\";\n"
"color: rgb(0,0, 255)"));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1230, 720, 611, 91));
        pushButton_2->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(1240, 840, 601, 81));
        pushButton_3->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));
        pushButton_3->setFlat(true);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1260, 950, 581, 81));
        pushButton_4->setFlat(true);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 20, 191, 101));
        pushButton_5->setFlat(true);
        StartShow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartShow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1891, 30));
        StartShow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartShow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        StartShow->setStatusBar(statusbar);

        retranslateUi(StartShow);

        QMetaObject::connectSlotsByName(StartShow);
    } // setupUi

    void retranslateUi(QMainWindow *StartShow)
    {
        StartShow->setWindowTitle(QApplication::translate("StartShow", "MainWindow", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StartShow: public Ui_StartShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTSHOW_H
