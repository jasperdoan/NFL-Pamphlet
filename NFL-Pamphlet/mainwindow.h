#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "helpwindow.h"
#include "helpwindow.h"
#include "filterwindow.h"
#include "contactwindow.h"
#include "adminwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_filterButton_clicked();

    void on_helpButton_clicked();

    void on_contactButton_clicked();

    void on_loginButton_clicked();

    void on_refreshButton_clicked();

private:
    Ui::MainWindow *ui;
    
    HelpWindow *helpWindow;
    FilterWindow *filterWindow;
    ContactWindow *contactWindow;
    AdminWindow *adminWindow;
};

#endif // MAINWINDOW_H
