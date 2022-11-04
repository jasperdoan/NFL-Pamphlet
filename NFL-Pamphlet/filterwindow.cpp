#include "filterwindow.h"
#include "ui_filterwindow.h"


FilterWindow::FilterWindow(QWidget *parent) : QDialog(parent), ui(new Ui::FilterWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    setupDivisionComboBox();
    setupStadiumComboBox();
    setupRoofComboBox();
    setupSurfaceComboBox();
}


void FilterWindow::on_filterButton_clicked()
{

}


FilterWindow::~FilterWindow()
{
    delete ui;
}


void FilterWindow::setupDivisionComboBox()
{   
    // Loop through enum and add to combo box
    for (int i = 0; i < 4; i++)
    {
        ui->divisionBox->addItem(QString::fromStdString((const string[]){"North", "South", "East", "West"}[i]));
    }
}


void FilterWindow::setupStadiumComboBox()
{
    // Loop through teamData vector and add to combo box
    // If the stadium name is not already in the combo box, add it
    for (int i = 0; i < teamData.size(); i++)
    {
        if (ui->stadiumBox->findText(QString::fromStdString(teamData[i].getStadiumName())) == -1)
        {
            ui->stadiumBox->addItem(QString::fromStdString(teamData[i].getStadiumName()));
        }
    }
}


void FilterWindow::setupRoofComboBox()
{
    // Loop through enum and add to combo box
    for (int i = 0; i < 3; i++)
    {
        ui->roofBox->addItem(QString::fromStdString((const string[]){"Open", "Retractable", "Fixed"}[i]));
    }
}


void FilterWindow::setupSurfaceComboBox()
{
    // Loop through teamData vector and add to combo box
    // If the surface type is not already in the combo box, add it
    for (int i = 0; i < teamData.size(); i++)
    {
        if (ui->surfaceBox->findText(QString::fromStdString(teamData[i].getSurfaceType())) == -1)
        {
            ui->surfaceBox->addItem(QString::fromStdString(teamData[i].getSurfaceType()));
        }
    }
}
