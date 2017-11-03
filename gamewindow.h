#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>

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
};

#endif // GAMEWINDOW_H
