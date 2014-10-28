#include "item.h"

item::item()
{
    definedStatus[tetris_I][0][0]=0b10000000000;
    definedStatus[tetris_I][0][1]=0b10000000000;
    definedStatus[tetris_I][0][2]=0b10000000000;
    definedStatus[tetris_I][0][3]=0b10000000000;

    definedStatus[tetris_I][1][0]=0b00000000000;
    definedStatus[tetris_I][1][1]=0b00000000000;
    definedStatus[tetris_I][1][2]=0b00000000000;
    definedStatus[tetris_I][1][3]=0b11110000000;

    definedStatus[tetris_I][2][0]=0b10000000000;
    definedStatus[tetris_I][2][1]=0b10000000000;
    definedStatus[tetris_I][2][2]=0b10000000000;
    definedStatus[tetris_I][2][3]=0b10000000000;

    definedStatus[tetris_I][3][0]=0b00000000000;
    definedStatus[tetris_I][3][1]=0b00000000000;
    definedStatus[tetris_I][3][2]=0b00000000000;
    definedStatus[tetris_I][3][3]=0b11110000000;

    definedStatus[tetris_J][0][0]=0b00000000000;
    definedStatus[tetris_J][0][1]=0b01000000000;
    definedStatus[tetris_J][0][2]=0b01000000000;
    definedStatus[tetris_J][0][3]=0b11000000000;

    definedStatus[tetris_J][1][0]=0b00000000000;
    definedStatus[tetris_J][1][1]=0b00000000000;
    definedStatus[tetris_J][1][2]=0b10000000000;
    definedStatus[tetris_J][1][3]=0b11100000000;

    definedStatus[tetris_J][2][0]=0b00000000000;
    definedStatus[tetris_J][2][1]=0b11000000000;
    definedStatus[tetris_J][2][2]=0b10000000000;
    definedStatus[tetris_J][2][3]=0b10000000000;

    definedStatus[tetris_J][3][0]=0b00000000000;
    definedStatus[tetris_J][3][1]=0b00000000000;
    definedStatus[tetris_J][3][2]=0b11100000000;
    definedStatus[tetris_J][3][3]=0b00100000000;

    definedStatus[tetris_L][0][0]=0b00000000000;
    definedStatus[tetris_L][0][1]=0b10000000000;
    definedStatus[tetris_L][0][2]=0b10000000000;
    definedStatus[tetris_L][0][3]=0b11000000000;

    definedStatus[tetris_L][1][0]=0b00000000000;
    definedStatus[tetris_L][1][1]=0b00000000000;
    definedStatus[tetris_L][1][2]=0b11100000000;
    definedStatus[tetris_L][1][3]=0b10000000000;

    definedStatus[tetris_L][2][0]=0b00000000000;
    definedStatus[tetris_L][2][1]=0b11000000000;
    definedStatus[tetris_L][2][2]=0b01000000000;
    definedStatus[tetris_L][2][3]=0b01000000000;

    definedStatus[tetris_L][3][0]=0b00000000000;
    definedStatus[tetris_L][3][1]=0b00000000000;
    definedStatus[tetris_L][3][2]=0b00100000000;
    definedStatus[tetris_L][3][3]=0b11100000000;

    for(int i=0;i<4;i++)
    {
        definedStatus[tetris_O][i][0]=0b00000000000;
        definedStatus[tetris_O][i][1]=0b00000000000;
        definedStatus[tetris_O][i][2]=0b11000000000;
        definedStatus[tetris_O][i][3]=0b11000000000;
    }

    definedStatus[tetris_T][0][0]=0b00000000000;
    definedStatus[tetris_T][0][1]=0b00000000000;
    definedStatus[tetris_T][0][2]=0b11100000000;
    definedStatus[tetris_T][0][3]=0b01000000000;

    definedStatus[tetris_T][1][0]=0b00000000000;
    definedStatus[tetris_T][1][1]=0b01000000000;
    definedStatus[tetris_T][1][2]=0b11000000000;
    definedStatus[tetris_T][1][3]=0b01000000000;

    definedStatus[tetris_T][2][0]=0b00000000000;
    definedStatus[tetris_T][2][1]=0b00000000000;
    definedStatus[tetris_T][2][2]=0b01000000000;
    definedStatus[tetris_T][2][3]=0b11100000000;

    definedStatus[tetris_T][3][0]=0b00000000000;
    definedStatus[tetris_T][3][1]=0b10000000000;
    definedStatus[tetris_T][3][2]=0b11000000000;
    definedStatus[tetris_T][3][3]=0b10000000000;

    definedStatus[tetris_S][0][0]=0b00000000000;
    definedStatus[tetris_S][0][1]=0b10000000000;
    definedStatus[tetris_S][0][2]=0b11000000000;
    definedStatus[tetris_S][0][3]=0b01000000000;

    definedStatus[tetris_S][1][0]=0b00000000000;
    definedStatus[tetris_S][1][1]=0b00000000000;
    definedStatus[tetris_S][1][2]=0b01100000000;
    definedStatus[tetris_S][1][3]=0b11000000000;

    definedStatus[tetris_S][2][0]=0b00000000000;
    definedStatus[tetris_S][2][1]=0b10000000000;
    definedStatus[tetris_S][2][2]=0b11000000000;
    definedStatus[tetris_S][2][3]=0b01000000000;

    definedStatus[tetris_S][3][0]=0b00000000000;
    definedStatus[tetris_S][3][1]=0b00000000000;
    definedStatus[tetris_S][3][2]=0b01100000000;
    definedStatus[tetris_S][3][3]=0b11000000000;

    definedStatus[tetris_Z][0][0]=0b00000000000;
    definedStatus[tetris_Z][0][1]=0b01000000000;
    definedStatus[tetris_Z][0][2]=0b11000000000;
    definedStatus[tetris_Z][0][3]=0b10000000000;

    definedStatus[tetris_Z][1][0]=0b00000000000;
    definedStatus[tetris_Z][1][1]=0b00000000000;
    definedStatus[tetris_Z][1][2]=0b11000000000;
    definedStatus[tetris_Z][1][3]=0b01100000000;

    definedStatus[tetris_Z][2][0]=0b00000000000;
    definedStatus[tetris_Z][2][1]=0b01000000000;
    definedStatus[tetris_Z][2][2]=0b11000000000;
    definedStatus[tetris_Z][2][3]=0b10000000000;

    definedStatus[tetris_Z][3][0]=0b00000000000;
    definedStatus[tetris_Z][3][1]=0b00000000000;
    definedStatus[tetris_Z][3][2]=0b11000000000;
    definedStatus[tetris_Z][3][3]=0b01100000000;

    rotateIndex=0;
    x=y=0;
    color=Qt::red;
}
void item::SetType(tetrisType _type,int rotate)
{
    type=_type;
    rotate=rotate%4;
    for(int i=0;i<4;i++) pos[i]=definedStatus[type][rotate][i];
    rotateIndex=rotate;
}
bool item::CanMoveLeft(int back[])
{
    int tmp;
    if(x<=0) return false;
    for(int i=0;i<4;i++)
    {
        tmp=(pos[i]>>x-1)^back[i];
        if(tmp!=((pos[i]>>x-1)|back[i])) return false;
    }
    return true;
}
bool item::CanMoveRight(int back[])
{
    int tmp;
    for(int i=0;i<4;i++)
    {
        tmp=(pos[i]>>x+1)^back[i];
        if(tmp!=((pos[i]>>x+1)|back[i])) return false;
    }
    return true;
}
bool item::CanMoveDown(int back[])
{
    int tmp;
    for(int i=0;i<4;i++)
    {
        tmp=(pos[i]>>x)^back[i];
        if(tmp!=((pos[i]>>x)|back[i])) return false;
    }
    return true;
}
bool item::CanRotate(int back[])
{
    int tmp;
    int pos[4];
    for(int i=0;i<4;i++)
    {
        pos[i]=definedStatus[type][(rotateIndex+1)%4][i];

        qDebug()<<x;
        qDebug()<<i<<"pos:"<<(pos[i]>>x)<<" back:"<<back[i];
        tmp=(pos[i]>>x)^back[i];
        if(tmp!=((pos[i]>>x)|back[i])) return false;
    }
    return true;
}
