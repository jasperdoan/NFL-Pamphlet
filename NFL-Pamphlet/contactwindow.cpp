#include "contactwindow.h"
#include "ui_contactwindow.h"

ContactWindow::ContactWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactWindow)
{
    ui->setupUi(this);
}

ContactWindow::~ContactWindow()
{
    delete ui;
}