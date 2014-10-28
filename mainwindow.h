#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cube.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <tetrisscene.h>
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//public slots:
    void keyPressEvent(QKeyEvent *pressEvent);
    
private slots:

    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

    void GameOver();

private:
    Ui::MainWindow *ui;
    TetrisScene *scene;
};

#endif // MAINWINDOW_H
