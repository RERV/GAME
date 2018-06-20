#ifndef CHOOSEGUNDAM_H
#define CHOOSEGUNDAM_H

#include <QMainWindow>
//int _gundamChoose;
namespace Ui {
class ChooseGundam;
}

class ChooseGundam : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseGundam(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    ~ChooseGundam();
signals:
    void gundam();
private slots:
      void on_pushButton_clicked();
      void on_pushButton_2_clicked();
      void on_pushButton_3_clicked();
      void on_pushButton_4_clicked();
private:
    Ui::ChooseGundam *ui;
};

#endif // CHOOSEGUNDAM_H
