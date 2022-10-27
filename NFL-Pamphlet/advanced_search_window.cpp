#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("National Football Teams");
    ui->comboBox->addItem("American Football Confrence");

}

MainWindow::~MainWindow()
{
    delete ui;
}

