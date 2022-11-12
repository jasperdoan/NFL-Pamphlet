#include "adminwindow.h"
#include "ui_adminwindow.h"


// TODO: @snappyappleTheSimple
//     Add a function to check if the user is an admin
//          f the user is an admin, then the admin window will be displayed
//         If the user is not an admin, then the admin window will not be displayed
//     Fix addTeam() function


AdminWindow::AdminWindow(QWidget *parent) : QDialog(parent), ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    setupRemoveTeamComboBox();

    // Refresh the team list upon adding / removing a team
    connect(ui->addNewTeam, SIGNAL(clicked()), parent, SLOT(on_refreshButton_clicked()));
    connect(ui->removeTeam, SIGNAL(clicked()), parent, SLOT(on_refreshButton_clicked()));
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
        if (ui->selectRemoveTeam->findText(QString::fromStdString(teamData[i].getTeamName())) == -1)
        {
            ui->selectRemoveTeam->addItem(QString::fromStdString(teamData[i].getTeamName()));
        }
    }
}


void AdminWindow::on_addNewTeam_clicked()
{
    string teamName = ui->newTeamName->toPlainText().toStdString();
    string stadiumName = ui->newStadiumName->toPlainText().toStdString();
    int capacity = ui->newSeatingCapacity->toPlainText().toInt();
    string location = ui->newLocation->toPlainText().toStdString();
    string conference = ui->newConference->toPlainText().toStdString();
    string division = ui->newDivision->toPlainText().toStdString();
    string surface = ui->newSurfaceType->toPlainText().toStdString();
    string roof = ui->newRoofType->toPlainText().toStdString();
    int year = ui->newOpenDate->toPlainText().toInt();

    bool emptyTextBox = teamName.empty() || stadiumName.empty() || capacity == 0 || location.empty() || 
                        conference.empty() || division.empty() || surface.empty() || roof.empty() || year == 0;

    Conference conf;
    Division div;
    RoofType r;

    if(conference == "National Football Conference") { conf = NFC; }
    else { conf = AFC; }

    switch (division[0])
    {
        case 'N': div = NORTH;
            break;
        case 'S': div = SOUTH;
            break;
        case 'W': div = WEST;
            break;
        case 'E': div = EAST;
            break;
    }

    if(roof == "OPEN") { r = OPEN; }
    else if (roof == "RETRACTABLE") { r = RETRACTABLE; }
    else {r = FIXED; }

    TeamData newTeam(teamName, stadiumName, capacity, location, conf, div, surface, r, year);

    if(!emptyTextBox) { teamData.push_back(newTeam); }

    this->close();
}


void AdminWindow::on_removeTeam_clicked()
{
    string teamName = ui->selectRemoveTeam->currentText().toStdString();

    for (int i = 0; i < (int)teamData.size(); i++)
    {
        if (teamData[i].getTeamName() == teamName)
        {
            teamData.erase(teamData.begin() + i);
        }
    }

    this->close();
}

