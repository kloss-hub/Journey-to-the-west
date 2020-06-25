#ifndef ENDWINDOW_H
#define ENDWINDOW_H
#include <QMainWindow>
#include <QPainter>
namespace Ui {
class EndWindow;
}

class EndWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EndWindow(int s,QWidget *parent = nullptr);
    ~EndWindow();
private slots:
    void paintEvent(QPaintEvent *);     //绘图事件
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::EndWindow *ui;
    int status;
};

#endif // ENDWINDOW_H
