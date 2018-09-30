#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <handler.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc = new myScene;
    this->ui->graphicsView->setScene(sc);
    connect(this->ui->btn_start,SIGNAL(clicked(bool)),this->sc,SLOT(startGame()));
    connect(this->ui->btn_pause,SIGNAL(clicked(bool)),this->sc,SLOT(pauseGame()));
    connect(this->ui->btn_close,SIGNAL(clicked(bool)),this->sc,SLOT(stopGame()));
    this->score = 0;
    handler * hand = handler::getInstance();
    connect(hand,SIGNAL(beatMouse()),this,SLOT(updateScore()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this,"要走了吗？","再玩一会呗","先不玩了","再玩一会");
    if(ret ==1)
    {
        event->ignore();
    }
}
void MainWindow::updateScore()
{
    this->score+=10;
    this->ui->lcdNumber->display(this->score);
}
