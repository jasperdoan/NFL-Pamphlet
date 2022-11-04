#ifndef FILTERWINDOW_H
#define FILTERWINDOW_H

#include <QDialog>

namespace Ui {
class FilterWindow;
}

class FilterWindow : public QDialog
{
    Q_OBJECT
    
    private:
        Ui::FilterWindow *ui;
        FilterWindow *filterWindow;

    private slots:
        void on_filterButton_clicked();

    public:
        explicit FilterWindow(QWidget *parent = nullptr);
        ~FilterWindow();
};

#endif // FILTERWINDOW_H
