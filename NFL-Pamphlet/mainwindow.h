#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "helpwindow.h"
#include "helpwindow.h"
#include "filterwindow.h"
#include "contactwindow.h"
#include "adminwindow.h"
#include "teamdata.h"

using namespace NFLData;

namespace Ui 
{
    class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

    private:
        Ui::MainWindow *ui;
        
        HelpWindow *helpWindow;
        FilterWindow *filterWindow;
        ContactWindow *contactWindow;
        AdminWindow *adminWindow;

        vector<TeamData> teamData;
        vector<TeamData> filteredTeamData;

        void setupTable();
        void displayTable(vector<TeamData> &);

    private slots:
        void on_filterButton_clicked();

        void on_helpButton_clicked();

        void on_contactButton_clicked();

        void on_loginButton_clicked();

        void on_refreshButton_clicked();

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
};

#endif // MAINWINDOW_H
