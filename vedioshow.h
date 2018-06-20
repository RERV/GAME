#ifndef VEDIOSHOW_H
#define VEDIOSHOW_H


#include <QMainWindow>
#include <QUrl>
#include <QMediaPlayer>
#include <QVideoWidget>
#include<QTime>
#include<QTimer>
namespace Ui {
class VedioShow;
}

class VedioShow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VedioShow(QWidget *parent = 0);
    ~VedioShow();

private slots:
    void showvedio();
    void on_closeVideo_clicked();
signals:
    void turnToGame();
private:
    Ui::VedioShow *ui;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QTimer *time;
    bool status;
};

#endif // VEDIOSHOW_H
