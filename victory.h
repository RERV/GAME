#ifndef VICTORY_H
#define VICTORY_H

#include <QMainWindow>

namespace Ui {
class Victory;
}

class Victory : public QMainWindow
{
    Q_OBJECT

public:
    explicit Victory(QWidget *parent = 0);
    ~Victory();
    void paintEvent(QPaintEvent *e);
signals:
    void turnToMenu();
private slots:

      void on_pushButton_clicked();

private:
    Ui::Victory *ui;
};

#endif // VICTORY_H
