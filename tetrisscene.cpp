#include "tetrisscene.h"
#include <windows.h>

TetrisScene::TetrisScene(QObject *parent) :
    QGraphicsScene(parent)
{
    qsrand(QTime::currentTime().msec());
    this->addLine(0,0,0,400);
    this->addLine(200,0,200,400);
    this->addLine(0,400,200,400);
    for(int j=0;j<20;j++)
            map[j]=0b100000000001;
    map[20]=0b111111111111;
    for(int i=0;i<20;i++)
        for(int j=0;j<10;j++)
        {
            back[i][j].setPos(20*j,20*i);
            back[i][j].SetColor(Qt::darkGray);
            back[i][j].setVisible(false);
            this->addItem(&back[i][j]);
        }
//    for(int i=0;i<20;i++)
//        eraseLine[i]=-1;
    connect(&timer,SIGNAL(timeout()),this,SLOT(MoveDown()));
}
void TetrisScene::NewItem()
{
    int n = qrand()%7;
    int r = qrand()%4;
    element.SetType(item::tetrisType(n),r);
    int m = qrand()%7;
    switch(m)
    {
    case 0:element.color=Qt::red;break;
    case 1:element.color=Qt::blue;break;
    case 2:element.color=Qt::green;break;
    case 3:element.color=Qt::yellow;break;
    case 4:element.color=Qt::cyan;break;
    case 5:element.color=Qt::magenta;break;
    case 6:element.color=Qt::darkYellow;break;
    }
    element.x=4;
    element.y=0;
}
void TetrisScene::Start()
{
    score=0;
    this->NewItem();
    for(int j=0;j<20;j++)
    {
        if(j>=20-height)
        {
            int n=0;
            while(n==0)
                n= qrand()%0b1111111111;
            n=n<<1;
            map[j]=n+0b100000000001;
        }
        else map[j]=0b100000000001;
    }
    this->Update();
    timer.setInterval(interval);
    timer.start();
}
void TetrisScene::Stop()
{
    timer.stop();
}
void TetrisScene::SetLevel(int _level)
{
    level=_level;
    interval=100*(10-level)+50;
}

void TetrisScene::MoveDown()
{
    int _back[4];
    for(int i=0;i<4;i++)
    {
        _back[i]=map[element.y+i+1];
    }
    if(element.CanMoveDown(_back))       element.MoveDown();
    else this->AddToBack();
    this->Update();
}

void TetrisScene::Rotate()
{
    int _back[4];
    for(int i=0;i<4;i++)
    {
        _back[i]=map[element.y+i];
    }
    qDebug()<<element.CanRotate(_back);
    if(element.CanRotate(_back))element.Rotate();
    this->Update();
}

void TetrisScene::Moveleft()
{
    int _back[4];
    for(int i=0;i<4;i++)
    {
        _back[i]=map[element.y+i];
    }
    qDebug()<<element.CanMoveLeft(_back);
    if(element.CanMoveLeft(_back)) element.MoveLeft();
    this->Update();
}

void TetrisScene::MoveRight()
{
    int _back[4];
    for(int i=0;i<4;i++)
    {
        _back[i]=map[element.y+i];
    }
    qDebug()<<element.CanMoveRight(_back);
    if(element.CanMoveRight(_back)) element.MoveRight();
    this->Update();
}
void TetrisScene::AddToBack()
{
    int pos;
    for(int i=0;i<4;i++)
    {
        pos=element.pos[i]>>element.x;
        qDebug()<<"pos:"<<pos;
        qDebug()<<"map:"<<map[i+element.y];
        map[i+element.y]=map[i+element.y]|pos;

    }
    this->NewItem();
    int _back[4];
    for(int i=0;i<4;i++)
    {
        _back[i]=map[element.y+i+1];
    }
    if(!element.CanMoveDown(_back))
    {
        emit GameOver();
        this->Stop();
    }
}

void TetrisScene::Update()
{
    int tmp;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<10;j++)
        {
            tmp=map[i]>>(j+1)&1;
            if(tmp==1)
            {
                back[i][9-j].SetColor(Qt::darkGray);
                back[i][9-j].setVisible(true);
            }
            else
            {
                back[i][9-j].setVisible(false);
            }
        }
    }
    int pos;
    for(int i=0;i<4;i++)
    {
        pos=element.pos[i]>>element.x;
//        qDebug()<<pos;
        for(int j=0;j<4;j++)
        {
            tmp=pos>>(10-element.x-j)&1;
//            qDebug()<<i+element.y<<element.x+j;
            if(tmp==1)
            {
                back[i+element.y][element.x+j].setVisible(true);
                back[i+element.y][element.x+j].SetColor(element.color);
            }
        }
    }
    this->CheckToEraseLine();

}

void TetrisScene::CheckToEraseLine()
{
    int n=0;
    for(int i=19;i>0;i--)
    {
//        qDebug()<<"check:"<<i<<map[i];
        if(map[i]==map[20])
        {
            n++;
            for(int j=i-1;j>0;j--)
            {
                map[j+1]=map[j];
            }
            map[0]=0b100000000001;
            i++;
        }
    }
    switch(n)
    {
    case 1:score+=100;break;
    case 2:score+=200;break;
    case 3:score+=500;break;
    case 4:score+=1000;break;
    default:break;
    }
    if(score/10000>level) LevelUp();
}
void TetrisScene::LevelUp()
{
    this->SetLevel(level+1);
    qDebug()<<"level up!!!!";
    timer.stop();
    timer.setInterval(interval);
    timer.start();
}
