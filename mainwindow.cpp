#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _ptrGameWindow(nullptr)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::WindowMinMaxButtonsHint, false);

    _ptrGameWindow = new GameWindow;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_clicked()
{
    this->close();
}

void MainWindow::on_newGame_clicked()
{
    _ptrGameWindow->show();
    this->hide();
}
