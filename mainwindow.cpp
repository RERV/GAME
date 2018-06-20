#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string.h"
#include "icon.h"
#include <QTimer>
#include <map>
#include <iostream>
#include <windows.h>
extern string path;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
  //  pa->drawPixmap(0,0,960,540,QPixmap("C:\\QTMap\\picture\\2.jpg"));
    int index=4;
    string thepath=path;
    char indexpath='0'+index;
    thepath+=("picture//");
    thepath+=indexpath;
    thepath+=".jpg";
    const char* path1=thepath.c_str();


    pa->drawPixmap(0,0,1920,1080,QPixmap(path1));

    pa->end();
    delete pa;
}

void MainWindow::on_pushButton_clicked()
{

}

