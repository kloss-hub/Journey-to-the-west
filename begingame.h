#ifndef BEGINGAME_H
#define BEGINGAME_H

#include <QMainWindow>
#include <QPainter>     //画笔
#include <QMediaPlayer>
namespace Ui {
class Begingame;
}

class Begingame : public QMainWindow
{
    Q_OBJECT

public:
    explicit Begingame(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);     //绘图事件
    ~Begingame();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Begingame *ui;
    QMediaPlayer * player;
};

#endif // BEGINGAME_H
