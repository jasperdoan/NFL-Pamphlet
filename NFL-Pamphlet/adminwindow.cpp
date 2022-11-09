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
    // Loop through teamData vector and add to combo box
    // If the stadium name is not already in the combo box, add it
    for (int i = 0; i < (int)teamData.size(); i++)
    {
        if (ui->selectRemoveTeam->findText(QString::fromStdString(teamData[i].getStadiumName())) == -1)
        {
            ui->selectRemoveTeam->addItem(QString::fromStdString(teamData[i].getStadiumName()));
        }
    }
}

void AdminWindow::onAddButtonClicked()
{
    string teamName = ui->newTeamName->currentText().toStdString();
    string stadiumName = ui->newStadiumName->currentText().toStdString();
    int capacity = ui->newCapacity->currentText().toStdString();
    string location = ui->newLocation->currentText().toStdString();
    Conference conference = ui->newConference->currentText().toStdString();
    Division division = ui->newDivision->currentText().toStdString();
    string surface = ui->newSurfaceType->currentText().toStdString();
    RoofType roof = ui->newRoofType->currentText().toStdString();
    int year = ui->newOpenDate->currentText().toStdString();

    bool emptyTextBox = ui->newTeamName->text().isEmpty();

    TeamData.push_back(string teamName, string stadiumName, int capacity, string location, Conference conference, Division division, string surface, RoofType roof, int year);
}
/*
            string teamName;
            string stadiumName;
            int capacity;
            string location;
            Conference conference;
            Division division;
            string surfaceType;
            RoofType roofType;
            int yearOpened;
*/
