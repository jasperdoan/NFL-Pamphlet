#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_filterButton_clicked()
{
    filterWindow = new FilterWindow(this);
    filterWindow->show();
}


void MainWindow::on_helpButton_clicked()
{
    helpWindow = new HelpWindow(this);
    helpWindow->show();
}


void MainWindow::on_contactButton_clicked()
{
    contactWindow = new ContactWindow(this);
    contactWindow->show();
}


void MainWindow::on_loginButton_clicked()
{
    adminWindow = new AdminWindow(this);
    adminWindow->show();
}


void MainWindow::on_refreshButton_clicked()
{

}

