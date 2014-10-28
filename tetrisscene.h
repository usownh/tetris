#ifndef TETRISSCENE_H
#define TETRISSCENE_H

#include <QGraphicsScene>
#include <cube.h>
#include <item.h>
#include <QTime>
#include <cstdlib>
#include <QDebug>
#include <QTimer>

class TetrisScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit TetrisScene(QObject *parent = 0);
    void Update();
    void NewItem();
    void AddToBack();
    void CheckToEraseLine();
    int GetScore(){return score;}
    void SetLevel(int _level);
    void LevelUp();
    int GetLevel(){return level;}
    void SetHeight(int h){height=h;}
    
signals:
    void GameOver();
public slots:
    void Start();
    void MoveDown();
    void Rotate();
    void Moveleft();
    void MoveRight();
    void Stop();

private:
    int map[21];
    Cube back[20][10];
    item element;
    QTimer timer;
    int score;
    int interval;
    int level;
    int height;
//    int eraseLine[20];
};

#endif // TETRISSCENE_H
