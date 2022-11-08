#include "filterwindow.h"
#include "ui_filterwindow.h"


FilterWindow::FilterWindow(QWidget *parent) : QDialog(parent), ui(new Ui::FilterWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    setupStadiumComboBox();
    setupRoofComboBox();
    setupSurfaceComboBox();
    setupLocationComboBox();

    connect(ui->filterButton, SIGNAL(clicked()), parent, SLOT(on_refreshButton_clicked()));
}


void FilterWindow::on_filterButton_clicked()
{
    string conference = ui->conferenceBox->currentText().toStdString();
    string division = ui->divisionBox->currentText().toStdString();
    string stadium = ui->stadiumBox->currentText().toStdString();
    string roof = ui->roofBox->currentText().toStdString();
    string surface = ui->surfaceBox->currentText().toStdString();
    string location = ui->locationBox->currentText().toStdString();

    bool emptyTextBox = ui->teamNameBox->text().isEmpty();
    bool containStr, isCof, isDiv, isStad, isRoof, isSurf, isLoc;

    // Clear the filteredData vector
    filteredData.clear();

    // Loop through teamData vector and add to filteredData vector
    for (int i = 0; i < (int)teamData.size(); i++)
    {
        containStr = emptyTextBox      || QString::fromStdString(teamData[i].getTeamName()).contains(ui->teamNameBox->text(), Qt::CaseInsensitive);
        isCof      = conference == "-" || teamData[i].getConference() == conference;
        isDiv      = division   == "-" || teamData[i].getDivision() == division;
        isStad     = stadium    == "-" || teamData[i].getStadiumName() == stadium;
        isRoof     = roof       == "-" || teamData[i].getRoofType() == roof;
        isSurf     = surface    == "-" || teamData[i].getSurfaceType() == surface;
        isLoc      = location   == "-" || teamData[i].getLocation().find(location) != std::string::npos;
        
        if (containStr && isCof && isDiv && isStad && isRoof && isSurf && isLoc)
        {
            filteredData.push_back(teamData[i]);
        }
    }
}


FilterWindow::~FilterWindow()
{
    delete ui;
}


void FilterWindow::setupStadiumComboBox()
{
    // Loop through teamData vector and add to combo box
    // If the stadium name is not already in the combo box, add it
    for (int i = 0; i < (int)teamData.size(); i++)
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
    for (int i = 0; i < (int)teamData.size(); i++)
    {
        if (ui->surfaceBox->findText(QString::fromStdString(teamData[i].getSurfaceType())) == -1)
        {
            ui->surfaceBox->addItem(QString::fromStdString(teamData[i].getSurfaceType()));
        }
    }
}


void FilterWindow::setupLocationComboBox()
{
    // String array of all states
    string states[] = {"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", 
                       "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", 
                       "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", 
                       "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", 
                       "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming"};

    // Loop through states array and add to combo box
    for (int i = 0; i < 50; i++)
    {
        ui->locationBox->addItem(QString::fromStdString(states[i]));
    }
}
