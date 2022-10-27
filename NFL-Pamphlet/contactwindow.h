#ifndef CONTACTWINDOW_H
#define CONTACTWINDOW_H

#include <QWidget>

namespace Ui {
class ContactWindow;
}

class ContactWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ContactWindow(QWidget *parent = nullptr);
    ~ContactWindow();

private:
    Ui::ContactWindow *ui;
};

#endif // CONTACTWINDOW_H
