#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <vector>
#include "displaydata.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog, public DisplayData
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();


private:
    Ui::AdminWindow *ui;

private slots:
    void setupRemoveTeamComboBox();
    void on_addNewTeam_clicked();
    void on_removeTeam_clicked();
};

#endif // ADMINWINDOW_H

