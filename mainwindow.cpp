#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _ptrGameWindow(nullptr)
{
    ui->setupUi(this);

    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _ptrGameWindow;
}

void MainWindow::on_exit_clicked()
{
    destroyGameWindow();
    this->close();
}

void MainWindow::on_newGame_clicked()
{
    createGameWindow();
    this->hide();
}

void MainWindow::slotCloseGameWindow()
{
    destroyGameWindow();
    this->show();
}

void MainWindow::createGameWindow()
{
    destroyGameWindow();

    _ptrGameWindow = new GameWindow;
    connect(_ptrGameWindow,
            SIGNAL(signalShowMainWindow()),
            this,
            SLOT(show()));
    connect(_ptrGameWindow,
            SIGNAL(signalCloseGameWindow()),
            this,
            SLOT(slotCloseGameWindow()));
    _ptrGameWindow->show();
}

void MainWindow::destroyGameWindow()
{
    if(_ptrGameWindow != nullptr)
    {
        disconnect(_ptrGameWindow,
                   SIGNAL(signalShowMainWindow()),
                   this,
                   SLOT(show()));
        disconnect(_ptrGameWindow,
                   SIGNAL(signalCloseGameWindow()),
                   this,
                   SLOT(slotCloseGameWindow()));
        delete _ptrGameWindow;
        _ptrGameWindow = nullptr;
    }
}
