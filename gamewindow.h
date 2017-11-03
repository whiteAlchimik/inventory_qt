#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "subjectwidget.h"
#include "tablewidget.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{    
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

signals:
    void signalShowMainWindow();

private slots:
    void on_mainMenu_clicked();

private:
    Ui::GameWindow *ui;

    Subject *_ptrSubjectApple;
    SubjectWidget *_ptrSubjectWidget;

    TableWidget *_ptrTableWidget;
};

#endif // GAMEWINDOW_H
