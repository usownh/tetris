#ifndef CUBE_H
#define CUBE_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <QGradient>

class Cube : public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Cube(QObject *parent = 0);
    void SetColor(QColor color);
signals:
    
public slots:
private:
    QBrush brush;
    QPen pen;
    QRadialGradient gradient;
    int w,h;
};

#endif // CUBE_H
