#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    setupRemoveTeamComboBox();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::setupRemoveTeamComboBox()
{

}

void AdminWindow::onAddButtonClicked()
{
    string conference = ui->newConference->currentText().toStdString();
    string division = ui->newDivision->currentText().toStdString();
    string stadium = ui->newStadiumName->currentText().toStdString();
    string roof = ui->newRoofType->currentText().toStdString();
    string surface = ui->newSurfaceType->currentText().toStdString();
    string location = ui->newLocation->currentText().toStdString();

    bool emptyTextBox = ui->newTeamName->text().isEmpty();
}
