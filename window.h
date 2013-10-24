#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QDebug>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);
    ~Window();

private slots:
    void analizeButton(QAbstractButton *button);
    
private:
    Ui::Window *ui;
};

#endif // WINDOW_H
