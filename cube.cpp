#include "cube.h"

Cube::Cube(QObject *parent) :
    QObject(parent)
{
    w=h=20;
    this->setRect(0,0,w,h);
//    this->setFlag(ItemIsMovable);

}
void Cube::SetColor(QColor color)
{
    pen.setColor(Qt::white);
    gradient=QRadialGradient(10,10,30,10,10);
    gradient.setColorAt(1,Qt::white);
    gradient.setColorAt(0,color);
    brush=QBrush(gradient);
    brush.setStyle(Qt::RadialGradientPattern);
    this->setPen(pen);
    this->setBrush(brush);

}


