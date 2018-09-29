#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc = new myScene;
    this->ui->graphicsView->setScene(sc);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_close_clicked()
{
   this->close();
}
