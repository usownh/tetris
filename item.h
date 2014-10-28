#ifndef ITEM_H
#define ITEM_H
#include <cube.h>
#include <QDebug>



class item
{
public:
    item();
    enum tetrisType
    {
        tetris_I=0,tetris_J=1,tetris_L=2,tetris_O=3,tetris_T=4,tetris_S=5,tetris_Z=6
    };
    void SetType(tetrisType _type,int rotate);
    tetrisType GetType(){return type;}
    bool CanMoveLeft(int back[4]);
    bool CanMoveRight(int back[4]);
    bool CanMoveDown(int back[4]);
    bool CanRotate(int back[4]);
    void MoveLeft()
    {
        qDebug()<<"x:"<<x;
        x--;
    }
    void MoveRight()
    {
        qDebug()<<"x:"<<x;
        x++;
    }
    void MoveDown()
    {
        qDebug()<<"y:"<<y;
        y++;
    }

    void Rotate()
    {
        rotateIndex++;
        rotateIndex=rotateIndex%4;
        qDebug()<<"rotate index:"<<rotateIndex;
        for(int i=0;i<4;i++) pos[i]=definedStatus[type][rotateIndex][i];
    }
    int pos[4];
    int x,y;
    QColor color;
private:
    int definedStatus[7][4][4];
    tetrisType type;
    int rotateIndex;
};

#endif // ITEM_H
