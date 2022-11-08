#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "teamdata.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();


private:
    Ui::AdminWindow *ui;
    void setupRemoveTeamComboBox();

private slots:
    void on_LoginButton_clicked();
    void onAddButtonClicked();
};

#endif // ADMINWINDOW_H
