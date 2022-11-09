#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <vector>
#include "displaydata.h"

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

private slots:
    void on_LoginButton_clicked();
    void setupRemoveTeamComboBox();
    void onAddButtonClicked();
    void onRemoveButtonClicked();
};

#endif // ADMINWINDOW_H

