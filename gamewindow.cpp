#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    _ptrSubjectApple = new Subject(Subject::APPLE, ":/resources/images/image_apple.jpg");

    _ptrSubjectWidget = new SubjectWidget(this);
    _ptrSubjectWidget->setSubject(_ptrSubjectApple);
    ui->layuotSubjectWidget->addWidget(_ptrSubjectWidget);

    _ptrTableWidget = new TableWidget(TABLE_ROWS,
                                      TABLE_COLUMNS,
                                      this);
    ui->layoutTableWidget->addWidget(_ptrTableWidget);

    _ptrInventory = new Inventory(TABLE_ROWS,
                                  TABLE_COLUMNS,
                                  this);

    connect(_ptrTableWidget,
            SIGNAL(insertSubject(int,int,Subject,int)),
            _ptrInventory,
            SLOT(addSubjectOfInventoryCell(int,int,Subject,int)));
    connect(_ptrTableWidget,
            SIGNAL(removeSubject(int,int,int)),
            _ptrInventory,
            SLOT(deleteSubjectInInventoryCell(int,int,int)));
    connect(_ptrTableWidget,
            SIGNAL(signalMoveSubject(int,int,int,int)),
            _ptrInventory,
            SLOT(moveSubjectInInventory(int,int,int,int)));

    connect(_ptrInventory,
            SIGNAL(signalUpdateInventoryCell(int,int,InventoryCell)),
            _ptrTableWidget,
            SLOT(addItem(int,int,InventoryCell)));
    connect(_ptrInventory,
            SIGNAL(signalUpdateValueInInventoryCell(int,int,int)),
            _ptrTableWidget,
            SLOT(slotUpdateValueInCell(int,int,int)));
    connect(_ptrInventory,
            SIGNAL(inventoryCellIsEmpty(int,int)),
            _ptrTableWidget,
            SLOT(removeItem(int,int)));
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
