#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    setupRemoveTeamComboBox();
    connect(ui->addNewTeam, SIGNAL(clicked()), parent, SLOT(onAddButtonClicked()));
    connect(ui->removeTeam, SIGNAL(clicked()), parent, SLOT(onRemoveButtonClicked()));
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

void AdminWindow::on_LoginButton_clicked()
{

}

void AdminWindow::onAddButtonClicked()
{
    string teamName = ui->newTeamName->toPlainText().toStdString();
    string stadiumName = ui->newStadiumName->toPlainText().toStdString();
    int capacity = ui->newSeatingCapacity->toPlainText().toInt();
    string location = ui->newLocation->toPlainText().toStdString();
    Conference conference = ui->newConference->toPlainText();
    Division division = ui->newDivision->toPlainText();
    string surface = ui->newSurfaceType->toPlainText().toStdString();
    RoofType roof = ui->newRoofType->toPlainText();
    int year = ui->newOpenDate->toPlainText().toInt();

    bool emptyTextBox = ui->newTeamName->toPlainText().isEmpty();

    if(emptyTextBox)
    { }
    else {
    teamData.push_back(teamName, stadiumName, capacity, location, conference, division, surface, roof, year);
    }
}

void AdminWindow::onRemoveButtonClicked()
{

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
