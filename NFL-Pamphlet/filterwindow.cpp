#include "filterwindow.h"
#include "ui_filterwindow.h"

FilterWindow::FilterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("National Football");
    ui->comboBox->addItem("American Football Confrence");
    setAttribute(Qt::WA_DeleteOnClose);
}

void FilterWindow::on_filterButton_clicked()
{
   filterWindow = new FilterWindow(this);
   filterWindow->show();
}

FilterWindow::~FilterWindow()
{
    delete ui;
}
