#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QMainWindow>
#include <QPainter>     //画笔
namespace Ui {
class EndWindow;
}

class EndWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EndWindow(int s,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);     //绘图事件
    ~EndWindow();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::EndWindow *ui;
    int status;
};

#endif // ENDWINDOW_H
