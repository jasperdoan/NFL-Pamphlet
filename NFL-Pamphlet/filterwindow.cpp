#include "filterwindow.h"
#include "ui_filterwindow.h"

FilterWindow::FilterWindow(QWidget *parent) : QDialog(parent), ui(new Ui::FilterWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

void FilterWindow::on_filterButton_clicked()
{

}

FilterWindow::~FilterWindow()
{
    delete ui;
}
