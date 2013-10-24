#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    QButtonGroup *bgroup = new QButtonGroup(this);
    bgroup->addButton(ui->pushButton_1);
    bgroup->addButton(ui->pushButton_2);
    bgroup->addButton(ui->pushButton_3);
    bgroup->addButton(ui->pushButton_4);
    bgroup->addButton(ui->pushButton_5);
    bgroup->addButton(ui->pushButton_6);
    bgroup->addButton(ui->pushButton_7);
    bgroup->addButton(ui->pushButton_8);
    bgroup->addButton(ui->pushButton_9);

    // See which button is clicked
    connect(bgroup, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(analizeButton(QAbstractButton*)));
}

Window::~Window()
{
    delete ui;
}

void Window::analizeButton(QAbstractButton *button)
{
    // get widget id in grid
    int idx = ui->gridLayout->indexOf(button);

    // variables to get grid value
    int row = -1, col = -1, rowspan = -1, colspan = -1;

    // gimme the values! NOW!!
    ui->gridLayout->getItemPosition(idx, &row, &col, &rowspan, &colspan);

    // ok, print them
    qDebug() << "(" << row+1 << "," << col+1 << ")";
}
