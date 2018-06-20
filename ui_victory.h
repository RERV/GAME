/********************************************************************************
** Form generated from reading UI file 'victory.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VICTORY_H
#define UI_VICTORY_H

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

class Ui_Victory
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Victory)
    {
        if (Victory->objectName().isEmpty())
            Victory->setObjectName(QStringLiteral("Victory"));
        Victory->resize(1259, 597);
        centralwidget = new QWidget(Victory);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 80, 311, 131));
        pushButton->setFlat(true);
        Victory->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Victory);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1259, 30));
        Victory->setMenuBar(menubar);
        statusbar = new QStatusBar(Victory);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Victory->setStatusBar(statusbar);

        retranslateUi(Victory);

        QMetaObject::connectSlotsByName(Victory);
    } // setupUi

    void retranslateUi(QMainWindow *Victory)
    {
        Victory->setWindowTitle(QApplication::translate("Victory", "MainWindow", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Victory: public Ui_Victory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VICTORY_H
