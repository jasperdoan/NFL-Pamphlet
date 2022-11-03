#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

HelpWindow::~HelpWindow()
{
    delete ui;
}
