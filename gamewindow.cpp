#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    _ptrSubjectApple = new Subject(Subject::APPLE, ":/resources/images/image_apple.jpg");

    _ptrSubjectWidget = new SubjectWidget;
    _ptrSubjectWidget->setSubject(_ptrSubjectApple);

    _ptrTableWidget = new TableWidget;

    ui->layuotSubjectWidget->addWidget(_ptrSubjectWidget);
    ui->layoutTableWidget->addWidget(_ptrTableWidget);
}

GameWindow::~GameWindow()
{
    delete ui;
    delete _ptrSubjectApple;
}

void GameWindow::on_mainMenu_clicked()
{
    emit signalShowMainWindow();
}
