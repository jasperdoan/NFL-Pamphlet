#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "helpwindow.h"
#include "helpwindow.h"
#include "filterwindow.h"
#include "contactwindow.h"
#include "adminwindow.h"
#include "displaydata.h"

namespace Ui 
{
    class MainWindow;
}

class MainWindow : public QWidget, public DisplayData
{
    Q_OBJECT

    private:
        Ui::MainWindow *ui;
        
        HelpWindow *helpWindow;
        FilterWindow *filterWindow;
        ContactWindow *contactWindow;
        AdminWindow *adminWindow;

        void setupTable();
        void displayTable(vector<TeamData> &);

    private slots:
        void on_filterButton_clicked();
        void on_helpButton_clicked();
        void on_contactButton_clicked();
        void on_loginButton_clicked();
        void on_refreshButton_clicked();
<<<<<<< HEAD
<<<<<<< HEAD
//        void on_dropdownBox_clicked();
        void on_dropdownBox_activated();
=======
        void on_dropdownBox_clicked();
>>>>>>> main
=======
        void on_dropdownBox_clicked();
>>>>>>> main

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
};

#endif // MAINWINDOW_H
