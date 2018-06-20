/********************************************************************************
** Form generated from reading UI file 'end.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_END_H
#define UI_END_H

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

class Ui_End
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *End)
    {
        if (End->objectName().isEmpty())
            End->setObjectName(QStringLiteral("End"));
        End->resize(1934, 1141);
        centralwidget = new QWidget(End);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(730, 800, 451, 81));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(740, 930, 431, 81));
        pushButton_3->setFlat(true);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(729, 675, 491, 101));
        pushButton_4->setFlat(true);
        End->setCentralWidget(centralwidget);
        menubar = new QMenuBar(End);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1934, 26));
        End->setMenuBar(menubar);
        statusbar = new QStatusBar(End);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        End->setStatusBar(statusbar);

        retranslateUi(End);

        QMetaObject::connectSlotsByName(End);
    } // setupUi

    void retranslateUi(QMainWindow *End)
    {
        End->setWindowTitle(QApplication::translate("End", "MainWindow", 0));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class End: public Ui_End {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_END_H
