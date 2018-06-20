#include "charge.h"
#include "ui_charge.h"
#include"QPainter"
#include"iostream"
using namespace std;
extern string path;
Charge::Charge(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Charge)
{
    ui->setupUi(this);
}

Charge::~Charge()
{
    delete ui;
}
void Charge::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);


    int index=9;
    string thepath=path;
    char indexpath='0'+index;
    thepath+=("picture//");
    thepath+=indexpath;
    thepath+=".jpg";
    const char* path1=thepath.c_str();


    pa->drawPixmap(0,0,1920,1080,QPixmap(path1));
    //this->_game.show(pa);
    pa->end();
    delete pa;
}

void Charge::on_pushButton_clicked()
{
    emit turnToMenu();
    this->hide();
}
