#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QMediaPlayer>

#include "subjectapple.h"
#include "subjectwidget.h"
#include "tablewidget.h"
#include "inventory.h"

#include "database.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{    
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);

    void saveInventory();

    ~GameWindow();

signals:
    void signalShowMainWindow();

private slots:
    void on_mainMenu_clicked();
    void playAppleBite();

private:
    Ui::GameWindow *ui;

    SubjectApple *_ptrSubjectApple;
    SubjectWidget *_ptrSubjectWidget;

    TableWidget *_ptrTableWidget;

    Inventory *_ptrInventory;

    const int TABLE_ROWS = 3;
    const int TABLE_COLUMNS = 3;
};

#endif // GAMEWINDOW_H
