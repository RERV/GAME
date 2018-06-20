#include "victory.h"
#include "ui_victory.h"
#include"string"
#include<QPainter>
using namespace std;
extern string path;
Victory::Victory(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Victory)
{
    ui->setupUi(this);
}

Victory::~Victory()
{
    delete ui;
}
void Victory::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);


    int index=3;
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

void Victory::on_pushButton_clicked()
{
    this->close();
    emit turnToMenu();
}
