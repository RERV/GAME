/********************************************************************************
** Form generated from reading UI file 'vedioshow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEDIOSHOW_H
#define UI_VEDIOSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VedioShow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *closeVideo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VedioShow)
    {
        if (VedioShow->objectName().isEmpty())
            VedioShow->setObjectName(QStringLiteral("VedioShow"));
        VedioShow->resize(2055, 1206);
        centralwidget = new QWidget(VedioShow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-10, -80, 2051, 1251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        closeVideo = new QPushButton(centralwidget);
        closeVideo->setObjectName(QStringLiteral("closeVideo"));
        closeVideo->setGeometry(QRect(0, 0, 2041, 81));
        closeVideo->setStyleSheet(QLatin1String("background:rgb(0, 0, 0);\n"
"font:rgb(255, 255, 255)\n"
""));
        VedioShow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VedioShow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 2055, 30));
        VedioShow->setMenuBar(menubar);
        statusbar = new QStatusBar(VedioShow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        VedioShow->setStatusBar(statusbar);

        retranslateUi(VedioShow);

        QMetaObject::connectSlotsByName(VedioShow);
    } // setupUi

    void retranslateUi(QMainWindow *VedioShow)
    {
        VedioShow->setWindowTitle(QApplication::translate("VedioShow", "MainWindow", 0));
        closeVideo->setText(QApplication::translate("VedioShow", "quit", 0));
    } // retranslateUi

};

namespace Ui {
    class VedioShow: public Ui_VedioShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEDIOSHOW_H
