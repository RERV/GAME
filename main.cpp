#include "mw1.h"
#include "mainwindow.h"
#include "vedioshow.h"
#include "end.h"
#include "choosegundam.h"
#include <QApplication>
#include"iostream"
#include"string"
#include"startshow.h"
#include"loading.h"
#include"victory.h"
#include"charge.h"
using namespace std;
string path="C:\\QTMap\\";
int _gundamChoose;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MW1 game;
    End end;
    loading load;
    load.showFullScreen();
    VedioShow vedio;
    ChooseGundam choosegundam;
    StartShow start;
    Charge charge;
    start.showFullScreen();
    Victory victory;

    QObject::connect(&start,SIGNAL(turnToVedio()),&choosegundam,SLOT(showFullScreen()));
    QObject::connect(&choosegundam,SIGNAL(gundam()),&vedio,SLOT(showvedio()));

    MW1 game;
    QObject::connect(&start,SIGNAL(quit()),&load,SLOT(close()));
    QObject::connect(&start,SIGNAL(quit()),&game,SLOT(close()));

    QObject::connect(&game,SIGNAL(victory()),&victory,SLOT(showFullScreen()));
    QObject::connect(&victory,SIGNAL(turnToMenu()),&start,SLOT(showFullScreen()));

    QObject::connect(&vedio,SIGNAL(turnToGame()),&game,SLOT(newgame()));
    QObject::connect(&vedio,SIGNAL(turnToGame()),&game,SLOT(showFullScreen()));

    QObject::connect(&start,SIGNAL(turnToCharge()),&charge,SLOT(showFullScreen()));
    QObject::connect(&charge,SIGNAL(turnToMenu()),&start,SLOT(showFullScreen()));

    QObject::connect(&start,SIGNAL(oldgame()),&game,SLOT(oldgame()));
    QObject::connect(&start,SIGNAL(oldgame()),&game,SLOT(showFullScreen()));

    QObject::connect(&game,SIGNAL(turnToMenu()),&start,SLOT(showFullScreen()));
    QObject::connect(&game,SIGNAL(turnToMenu()),&game,SLOT(end()));
    QObject::connect(&game,SIGNAL(turnToEnd()),&end,SLOT(showFullScreen()));
    QObject::connect(&end,SIGNAL(turnToMenu()),&start,SLOT(showFullScreen()));
    QObject::connect(&end,SIGNAL(turnToGame()),&game,SLOT(newgame()));
    QObject::connect(&end,SIGNAL(turnToGame()),&game,SLOT(showFullScreen()));

    return a.exec();
}
