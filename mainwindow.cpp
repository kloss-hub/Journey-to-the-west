#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
MainWindow::MainWindow(int s,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    size=s;
    blocksize=size/15;
    ui->setupUi(this);
    path.push_back(new Point(8*blocksize,0*blocksize));
    path.push_back(new Point(8*blocksize,3*blocksize));
    path.push_back(new Point(2*blocksize,3*blocksize));
    path.push_back(new Point(2*blocksize,7*blocksize));
    path.push_back(new Point(11*blocksize,7*blocksize));
    path.push_back(new Point(11*blocksize,5*blocksize));
    path.push_back(new Point(13*blocksize,5*blocksize));//一定要用new
    QTimer *timer2 = new QTimer(this);
    timer2->start(200);
    connect(timer2,SIGNAL(timeout()),this,SLOT(drawagin()));//重画
    QTimer *timer = new QTimer(this);
    timer->start(evil_init_speed);
    connect(timer,SIGNAL(timeout()),this,SLOT(InitEvil()));//创造怪物
    QTimer *timer1 = new QTimer(this);
    timer1->start(1000);
    connect(timer1,SIGNAL(timeout()),this,SLOT(InitBullet()));//造子弹

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(life>0){
        painter.drawPixmap(rect(), QPixmap(":/images/bg4.jpg"));
        painter.setRenderHint(QPainter::Antialiasing);    //设置抗锯齿
        DrawMapArr(painter);        //画出地图
        DrawEvil(painter);       //画出怪物
        DrawEudemon(painter);  //画出守护者
    if(inselect)
        M->draw(painter,blocksize);
    }
    else{
        painter.drawPixmap(rect(), QPixmap(":/images/game_over.jpg"));
    }
}

void MainWindow::mousePressEvent(QMouseEvent *mouse)
{
    int Map[10][15] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 3, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    int x=mouse->pos().x()/blocksize;
    int y=mouse->pos().y()/blocksize;//得到鼠标坐标对应的块坐标
    if(inselect){
        int bx=M->GetX()/blocksize;
        int by=M->GetY()/blocksize;//选择框对应的块坐标
        if(x==bx&&y==by-1){
            if(money>=50){
                money-=50;
                Eudemonvec.append(new MonkeyKing(bx*blocksize,by*blocksize,blocksize*3/4));//类型兼容
            }
        }
        if(x==bx+1&&by==y){
            if(money>=40){
                money-=40;
                Eudemonvec.append(new Pigsy(bx*blocksize,by*blocksize,blocksize*3/4));//类型兼容
            }
        }

        inselect=false;//选择完毕

    }//在选择界面
    else{
        bool exit=false; //判断点击的位置是否已经有守护者
        if(Map[y][x]==0)//别反了
        {//合法点击区域
            int i=0;
            for(;i<Eudemonvec.size();i++){
                if(Eudemonvec.at(i)->GetX()/blocksize==x&&Eudemonvec.at(i)->GetY()/blocksize==y){//已经有守护者
                    exit=true;
                    break;
                }
            }
            if(!exit){//需要画出选择框
                M=new Marquee(x*blocksize, y*blocksize,":/images/marquee.PNG",":/images/swk.PNG",":/images/zbj.PNG",":/images/shs.PNG",":/images/tdgg.PNG");
                inselect=true;
            }
            else if(mouse->button()==Qt::LeftButton&&money>=Eudemonvec.at(i)->GetUpgradeCost()){//左键表示要升级,并且钱够的情况下
                money-=Eudemonvec.at(i)->GetUpgradeCost();
                Eudemonvec.at(i)->Upgrade();
            }
            else if(mouse->button()==Qt::RightButton){//右键表示要删除
                Eudemonvec.removeAt(i);
            }

            }
        }

}


void MainWindow::DrawMapArr(QPainter& painter)//画地图
{
    int Map[10][15] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 3, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++)
        {
            switch (Map[i][j])
            {
                case 1:{      //地板
                    painter.drawPixmap(j * blocksize, i * blocksize, blocksize, blocksize,QPixmap(":/images/floor.png"));
                    break;
                }
                case 2:{    //唐僧
                    painter.drawPixmap(j * blocksize, i * blocksize, blocksize, blocksize ,QPixmap(":/images/ts.PNG"));
                    break;
                }
                case 3:{
                    painter.drawPixmap(j * blocksize, i * blocksize, blocksize, blocksize ,QPixmap(":/images/money.PNG"));
                    break;
                }
                case 4:{
                    QFont font("Comic Sans MS", 22);
                    QRectF rect(j * blocksize, i * blocksize, blocksize, blocksize);
                    painter.setFont(font);
                    painter.setPen(QColor(190,130,190));
                    painter.drawText(rect, Qt::AlignHCenter, QString::number(money));//字体水平居中
                    break;
                }
//                    QFont serifFont("Times", 10, QFont::Bold);
                case 5:{
                    Drawlife(painter,j,i);
                    break;
                }
            }
        }
}


void MainWindow::Drawlife(QPainter & painter,int x,int y){
    if(life<20)
        painter.drawPixmap(x * blocksize, y * blocksize+blocksize/2, blocksize, blocksize/2,QPixmap(":/images/20.PNG"));
    else if(life<40)
        painter.drawPixmap(x * blocksize, y * blocksize+blocksize/2, blocksize, blocksize/2,QPixmap(":/images/40.PNG"));
    else if(life<60)
        painter.drawPixmap(x * blocksize, y * blocksize+blocksize/2, blocksize, blocksize/2,QPixmap(":/images/60.PNG"));
    else if(life<80)
        painter.drawPixmap(x * blocksize, y * blocksize+blocksize/2, blocksize, blocksize/2,QPixmap(":/images/80.PNG"));
    else
        painter.drawPixmap(x * blocksize, y * blocksize+blocksize/2, blocksize, blocksize/2,QPixmap(":/images/100.PNG"));
}
void MainWindow::InitEvil(){
    if(evil_count<=15){
        Evilvec.append(new Evil(10,10,":/images/yj.PNG",path,blocksize/2));
        evil_count+=1;
    }
    else if (evil_count<=25) {
        Evilvec.append(new Evil(20,20,":/images/sj.PNG",path,blocksize/2));
        evil_count+=1;
    }
    else if (evil_count<=32) {
        Evilvec.append(new Evil(30,30,":/images/xzj.PNG",path,blocksize));
        evil_count+=1;
    }
    else if (evil_count<=37) {
        Evilvec.append(new Evil(50,50,":/images/bgj.PNG",path,blocksize));
        evil_count+=1;
    }
    else{}
}
void MainWindow::InitBullet(){
//    for(int i=0;i<Eudemonvec.size();i++){
//        Eudemonvec.at(i)->Addbuttle();
//    }
}//添加子弹



void MainWindow::drawagin(){
    update();
}
void MainWindow::DrawEudemon(QPainter& painter){//画守护者并确定目标怪物
    for(int i=0;i<Eudemonvec.size();i++){
        Eudemonvec.at(i)->draw(painter,Eudemonvec.at(i)->GetSize(), Eudemonvec.at(i)->GetSize());
        for(int j=0;j<Evilvec.size();j++){
            int x=Evilvec.at(j)->GetX()-Eudemonvec.at(i)->GetX();
            int y=Evilvec.at(j)->GetY()-Eudemonvec.at(i)->GetY();
            int range=Eudemonvec.at(i)->GetRange();
            if(x*x+y*y<=range*range){
                Eudemonvec.at(i)->SetTargetEvil(Evilvec.at(j));
                break;//找到目标怪物
            }
        }
        Eudemonvec.at(i)->Attack(painter);//攻击
    }
}
int MainWindow::hurt(Evil *E)
{
    if(E->GetX()==13*blocksize&&E->GetY()==5*blocksize){
        life-=E->GetHurt();//
        return 1;
    }
    return 0;

}
void MainWindow::DrawEvil(QPainter& painter)
{//妖精移动，同时画出妖精
    for(int i=0;i<Evilvec.size();i++){
        Evilvec.at(i)->move();
        if(hurt(Evilvec.at(i))||Evilvec.at(i)->GetHealth()<=0){
            if(Evilvec.at(i)->GetHealth()<=0){
                money+=Evilvec.at(i)->GetReward();//得到杀死妖精的奖励
            }
            Evilvec.removeAt(i);          //删除伤害到唐僧或者死亡的妖精
            i--;
        }
        else
        {
            Evilvec.at(i)->draw(painter,blocksize, blocksize);
            painter.save();
            painter.setPen(QPen(1));
            painter.setBrush(QBrush(Qt::red));
            painter.drawRect(Evilvec.at(i)->GetX()-20,Evilvec.at(i)->GetY()-10,Evilvec.at(i)->GetHealth(),5);
            painter.restore();
        }

    }
}
