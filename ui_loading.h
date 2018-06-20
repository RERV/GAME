/********************************************************************************
** Form generated from reading UI file 'loading.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADING_H
#define UI_LOADING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loading
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *loading)
    {
        if (loading->objectName().isEmpty())
            loading->setObjectName(QStringLiteral("loading"));
        loading->resize(640, 480);
        menubar = new QMenuBar(loading);
        menubar->setObjectName(QStringLiteral("menubar"));
        loading->setMenuBar(menubar);
        centralwidget = new QWidget(loading);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        loading->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(loading);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        loading->setStatusBar(statusbar);

        retranslateUi(loading);

        QMetaObject::connectSlotsByName(loading);
    } // setupUi

    void retranslateUi(QMainWindow *loading)
    {
        loading->setWindowTitle(QApplication::translate("loading", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class loading: public Ui_loading {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADING_H
