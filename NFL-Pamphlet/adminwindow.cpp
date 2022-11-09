#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

AdminWindow::~AdminWindow()
{
    delete ui;
}
