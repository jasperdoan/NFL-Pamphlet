#ifndef FILTERWINDOW_H
#define FILTERWINDOW_H

#include <QDialog>
#include <vector>
#include "displaydata.h"

namespace Ui 
{
    class FilterWindow;
}

class FilterWindow : public QDialog, public DisplayData
{
    Q_OBJECT

    private:
        Ui::FilterWindow *ui;

        void setupStadiumComboBox();
        void setupRoofComboBox();
        void setupSurfaceComboBox();
        void setupLocationComboBox();

    private slots:
        void on_filterButton_clicked();

    public:
        explicit FilterWindow(QWidget *parent = nullptr);
        ~FilterWindow();

        void filterData();
};

#endif // FILTERWINDOW_H
