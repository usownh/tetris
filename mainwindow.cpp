#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new TetrisScene;
    ui->graphicsView->setRenderHint(QPainter::Antialiasing,true);  //开抗锯齿
    scene->setSceneRect(0,0,200,390);
    ui->graphicsView->setScene(scene);
    ui->centralWidget->setFocusPolicy(Qt::StrongFocus);
    ui->pushButtonStop->setDisabled(true);
    connect(scene,SIGNAL(GameOver()),ui->pushButtonStop,SLOT(click()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *pressEvent)
{
    switch(pressEvent->key())
    {
    case Qt::Key_Up:scene->Rotate();break;
    case Qt::Key_Down:scene->MoveDown();break;
    case Qt::Key_Left:scene->Moveleft();break;
    case Qt::Key_Right:scene->MoveRight();break;
    }
    ui->label_Score->setText(QString().setNum(scene->GetScore()));
    ui->spinBox->setValue(scene->GetLevel());
}


void MainWindow::on_pushButtonStart_clicked()
{
    ui->spinBox->setDisabled(true);
    ui->spinBoxHeight->setDisabled(true);
    ui->pushButtonStart->setDisabled(true);
    ui->pushButtonStop->setEnabled(true);
    ui->label_Score->setText("0");
    scene->SetLevel(ui->spinBox->value());
    scene->SetHeight(ui->spinBoxHeight->value());
    scene->Start();
    ui->centralWidget->setFocus();
}

void MainWindow::on_pushButtonStop_clicked()
{
    ui->spinBox->setEnabled(true);
    ui->spinBoxHeight->setEnabled(true);
    ui->pushButtonStart->setEnabled(true);
    ui->pushButtonStop->setDisabled(true);
    scene->Stop();
    this->GameOver();
}

void MainWindow::GameOver()
{
    QString tmp;
    tmp="your score is "+ui->label_Score->text();
    QMessageBox::information(this,"Game Over!",tmp,QMessageBox::Ok);
}
