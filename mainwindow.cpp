#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "endwindow.h"

MainWindow::MainWindow(int s,int l,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QMediaPlaylist *playlist=new QMediaPlaylist;
    level=l;
    size=s;
    blocksize=size/15;
    player = new QMediaPlayer;
    ui->setupUi(this);
    int Map1[10][15] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 6, 7, 8, 9},
        {0, 3, 4, 0, 0, 0, 0, 0, 1, 0, 0,10,11,12,13},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14,0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    int Map2[10][15]={
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 7, 8, 9},
        {0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0,10,11,12,13},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 5, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 2, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14,0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    if(l==1){//盘丝洞关卡
        memcpy(Map, Map1, sizeof(Map));
        playlist->addMedia(QUrl("qrc:/sounds/bgm1.mp3"));
        path.push_back(new Point(8*blocksize,0*blocksize));
        path.push_back(new Point(8*blocksize,3*blocksize));
        path.push_back(new Point(4*blocksize,3*blocksize));
        path.push_back(new Point(4*blocksize,7*blocksize));
        path.push_back(new Point(11*blocksize,7*blocksize));
        path.push_back(new Point(11*blocksize,5*blocksize));
        path.push_back(new Point(13*blocksize,5*blocksize));//一定要用new

    }
    else{//火焰山关卡
        memcpy(Map, Map2, sizeof(Map));
        playlist->addMedia(QUrl("qrc:/sounds/bgm2.mp3"));
        path.push_back(new Point(0*blocksize,3*blocksize));
        path.push_back(new Point(2*blocksize,3*blocksize));
        path.push_back(new Point(2*blocksize,7*blocksize));
        path.push_back(new Point(4*blocksize,7*blocksize));
        path.push_back(new Point(4*blocksize,2*blocksize));
        path.push_back(new Point(8*blocksize,2*blocksize));
        path.push_back(new Point(8*blocksize,6*blocksize));
        path.push_back(new Point(11*blocksize,6*blocksize));
        path.push_back(new Point(11*blocksize,4*blocksize));
        path.push_back(new Point(13*blocksize,4*blocksize));
    }
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player = new QMediaPlayer(this);
    player->setPlaylist(playlist);
    player->setVolume(30);
    player->play();
    QTimer *timer2 = new QTimer(this);
    timer2->start(200);
    connect(timer2,SIGNAL(timeout()),this,SLOT(update()));//重画
    QTimer *timer = new QTimer(this);
    timer->start(evil_init_speed);
    connect(timer,SIGNAL(timeout()),this,SLOT(InitEvil()));//创造怪物
    QTimer *timer1 = new QTimer(this);
    timer1->start(100);
    connect(timer1,SIGNAL(timeout()),this,SLOT(InitBullet()));//造子弹
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)//绘图事件
{
    QPainter painter(this);
    if(life>0){
        if(evil_count==38&&Evilvec.empty()){
            EndWindow *e=new EndWindow(1);
            e->show();
            this->close();
            player->stop();
        }//游戏胜利
        if(level==1)//盘丝洞
            painter.drawPixmap(rect(), QPixmap(":/images/psd.jpg"));
        else {//火焰山
            painter.drawPixmap(rect(), QPixmap(":/images/hys.jpg"));
        }
        painter.setRenderHint(QPainter::Antialiasing);    //设置抗锯齿
        DrawMap(painter);        //画出地图
        DrawEvil(painter);       //画出怪物
        DrawEudemon(painter);  //画出守护者
    if(inselect)
        M->draw(painter,blocksize);
    }
    else{
        EndWindow *e=new EndWindow(0);
        e->show();
        this->close();
        player->stop();
    }//游戏失败
}

void MainWindow::mousePressEvent(QMouseEvent *mouse)//鼠标事件
{

    int x=mouse->pos().x()/blocksize;
    int y=mouse->pos().y()/blocksize;//得到鼠标坐标对应的块坐标
    if(Map[y][x]==14){
        pause=!pause;//暂停或继续
    }
    else if(inselect){
        int bx=M->GetX()/blocksize;
        int by=M->GetY()/blocksize;//选择框对应的块坐标
        if(x==bx&&y==by-1&&money>=50){
            money-=50;
            Eudemonvec.append(new MonkeyKing(bx*blocksize,by*blocksize,blocksize*2/3));
            difficulty+=1;//难度增加
        }//孙悟空
        if(x==bx+1&&by==y&&money>=40){
            money-=40;
            Eudemonvec.append(new Pigsy(bx*blocksize,by*blocksize,blocksize*2/3));
            difficulty+=1;//难度增加
        }//猪八戒
        if(x==bx&&y==by+1&&money>=30){
            money-=30;
            Eudemonvec.append(new MonkSha(bx*blocksize,by*blocksize,blocksize*2/3));
            difficulty+=1;//难度增加
        }//沙和尚
        if(x==bx-1&&y==by&&money>=20){
            money-=20;
            Eudemonvec.append(new Gnome(bx*blocksize,by*blocksize,blocksize*2/3));
            difficulty+=1;//难度增加
        }//土地公公
        inselect=false;//选择完毕
        delete M;
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
                M=new Marquee(x*blocksize, y*blocksize,":/images/marquee.PNG",":/images/swk.PNG",":/images/zbj.PNG",":/images/shs.PNG",":/images/tdgg2.png");
                inselect=true;
            }
            else if(mouse->button()==Qt::LeftButton&&money>=Eudemonvec.at(i)->GetUpgradeCost()){//左键表示要升级,并且钱够的情况下
                money-=Eudemonvec.at(i)->GetUpgradeCost();
                Eudemonvec.at(i)->Upgrade();
                difficulty+=1;//升级
            }
            else if(mouse->button()==Qt::RightButton){//右键表示要删除
                Eudemon* Eud=Eudemonvec.at(i);
                Eudemonvec.removeAt(i);
                delete Eud;//释放内存
            }
        }
    }
}

void MainWindow::DrawMap(QPainter& painter)//画地图
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++)
        {
            switch (Map[i][j])
            {
                case 1:{      //进攻路径
                    painter.drawPixmap(j * blocksize, i * blocksize, blocksize, blocksize,QPixmap(":/images/floor.png"));
                    break;
                }
                case 2:{    //唐僧
                    painter.drawPixmap(j * blocksize, i * blocksize, blocksize, blocksize ,QPixmap(":/images/ts.PNG"));
                    break;
                }
                case 3:{    //金钱图标
                    painter.drawPixmap(j * blocksize, i * blocksize, blocksize, blocksize ,QPixmap(":/images/money2.png"));
                    break;
                }
                case 4:{      //金钱数额
                    QFont font("Comic Sans MS", 22);
                    QRectF rect(j * blocksize, i * blocksize, blocksize, blocksize);
                    painter.setFont(font);
                    painter.setPen(QColor(190,130,190));
                    painter.drawText(rect, Qt::AlignHCenter, QString::number(money));//字体水平居中
                    break;
                }
                case 5:{   //生命值图标
                    Drawlife(painter,j,i);
                    break;
                }
                case 6:{
                    painter.drawPixmap(j * blocksize, i * blocksize, blocksize-10, blocksize-10 ,QPixmap(":/images/swk.PNG"));
                    break;
                }
                case 7:{
                    QFont font("Comic Sans MS", 22);
                    QRectF rect(j * blocksize, i * blocksize, blocksize, blocksize);
                    painter.setFont(font);
                    painter.setPen(QColor(190,130,190));
                    painter.drawText(rect, Qt::AlignHCenter, QString::number(50));//孙悟空
                    break;
                }
                case 8:{
                    painter.drawPixmap(j * blocksize, i * blocksize, blocksize, blocksize ,QPixmap(":/images/zbj.PNG"));
                    break;
                }
                case 9:{
                    QFont font("Comic Sans MS", 22);
                    QRectF rect(j * blocksize, i * blocksize, blocksize-10, blocksize-10);
                    painter.setFont(font);
                    painter.setPen(QColor(190,130,190));
                    painter.drawText(rect, Qt::AlignHCenter, QString::number(40));//猪八戒
                    break;
                }
                case 10:{
                    painter.drawPixmap(j * blocksize, i * blocksize, blocksize-10, blocksize ,QPixmap(":/images/shs.PNG"));
                    break;
                }
                case 11:{
                    QFont font("Comic Sans MS", 22);
                    QRectF rect(j * blocksize, i * blocksize, blocksize, blocksize);
                    painter.setFont(font);
                    painter.setPen(QColor(190,130,190));
                    painter.drawText(rect, Qt::AlignHCenter, QString::number(30));//沙和尚
                    break;
                }
                case 12:{
                    painter.drawPixmap(j * blocksize, i * blocksize, blocksize-5, blocksize-5 ,QPixmap(":/images/tdgg2.png"));
                    break;
                }
                case 13:{
                    QFont font("Comic Sans MS", 22);
                    QRectF rect(j * blocksize, i * blocksize, blocksize, blocksize);
                    painter.setFont(font);
                    painter.setPen(QColor(190,130,190));
                    painter.drawText(rect, Qt::AlignHCenter, QString::number(20));//土地公公
                    break;
                }
                case 14:{
                    if(pause){
                        painter.drawPixmap(j * blocksize, i * blocksize, blocksize, blocksize ,QPixmap(":/images/pause.png"));
                    }
                    else {
                        painter.drawPixmap(j * blocksize, i * blocksize, blocksize, blocksize ,QPixmap(":/images/continue.png"));
                    }
                    break;
                }
            }
        }
}

void MainWindow::Drawlife(QPainter & painter,int x,int y)//画出唐僧生命值
{
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

void MainWindow::InitEvil()//产生妖怪
{
    if(!pause){
        if(evil_count<=15){
            Evilvec.append(new Evil(80+difficulty,5+difficulty,5,":/images/yj.PNG",path,blocksize/2));
            evil_count+=1;
        }
        else if (evil_count<=25) {
            Evilvec.append(new Evil(90+difficulty,10+difficulty,10,":/images/sj.PNG",path,blocksize/2));
            evil_count+=1;
        }
        else if (evil_count<=32) {
            Evilvec.append(new Evil(100+difficulty,15+difficulty,15,":/images/xzj.PNG",path,blocksize));
            evil_count+=1;
        }
        else if (evil_count<=37) {
            Evilvec.append(new Evil(100+difficulty,20+difficulty,20,":/images/bgj.PNG",path,blocksize));
            evil_count+=1;
        }
        else{}
    }
}

void MainWindow::InitBullet()//添加子弹
{
    if(!pause){
        for(int i=0;i<Eudemonvec.size();i++)
            Eudemonvec.at(i)->Addbuttle();
    }
}

void MainWindow::DrawEudemon(QPainter& painter)//画出守护者
{//画守护者并确定目标怪物
    for(int i=0;i<Eudemonvec.size();i++){
        Eudemonvec.at(i)->draw(painter,Eudemonvec.at(i)->GetSize(), Eudemonvec.at(i)->GetSize());
        int j=0;
        for(;j<Evilvec.size();j++){
            int x=Evilvec.at(j)->GetX()-Eudemonvec.at(i)->GetX();
            int y=Evilvec.at(j)->GetY()-Eudemonvec.at(i)->GetY();
            int range=Eudemonvec.at(i)->GetRange();
            if(x*x+y*y<=range*range){
                Eudemonvec.at(i)->SetTargetEvil(Evilvec.at(j));
                break;//找到目标怪物
            }
        }
        if(j==Evilvec.size()){
            Eudemonvec.at(i)->SetTargetEvil(nullptr);
        }
        money+=Eudemonvec.at(i)->Attack(painter,pause);//攻击或者生成金钱
    }
}

int MainWindow::hurt(Evil *E)//判断怪物是否伤害到唐僧
{
    if((level==1&&E->GetX()==13*blocksize&&E->GetY()==5*blocksize)||(level==2&&E->GetX()==13*blocksize&&E->GetY()==4*blocksize)){
        life-=E->GetHurt();//
        return 1;
    }
    return 0;

}

void MainWindow::DrawEvil(QPainter& painter)//妖精移动，同时画出妖精
{
    for(int i=0;i<Evilvec.size();i++){
        if(!pause){
            Evilvec.at(i)->move();
        }
        if(hurt(Evilvec.at(i))||Evilvec.at(i)->GetHealth()<=0){
            if(Evilvec.at(i)->GetHealth()<=0){
                money+=Evilvec.at(i)->GetReward();//得到杀死妖精的奖励
            }
            Evil *e=Evilvec.at(i);
            Evilvec.removeAt(i);          //删除伤害到唐僧或者死亡的妖精
            delete e;//释放内存
            i--;
        }
        else
        {
            Evilvec.at(i)->draw(painter,blocksize, blocksize);
        }

    }
}
