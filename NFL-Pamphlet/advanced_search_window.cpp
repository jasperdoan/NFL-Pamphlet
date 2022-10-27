#include "advanced_search_window.h"
#include "ui_advanced_search_window.h"

advanced_search_window::advanced_search_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::advanced_search_window)
{
    ui->setupUi(this);
}

advanced_search_window::~advanced_search_window()
{
    delete ui;
}
