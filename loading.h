#ifndef LOADING_H
#define LOADING_H

#include <QMainWindow>

namespace Ui {
class loading;
}

class loading : public QMainWindow
{
    Q_OBJECT

public:
    explicit loading(QWidget *parent = 0);
    ~loading();
    void paintEvent(QPaintEvent *e);
private:
    Ui::loading *ui;
};

#endif // LOADING_H
