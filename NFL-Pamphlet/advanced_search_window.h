#ifndef ADVANCED_SEARCH_WINDOW_H
#define ADVANCED_SEARCH_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AdvancedSearchWindow; }
QT_END_NAMESPACE

class AdvancedSearchWindow : public QMainWindow
{
    Q_OBJECT

public:
    AdvancedSearchWindow(QWidget *parent = nullptr);
    ~AdvancedSearchWindow();

private:
    Ui::AdvancedSearchWindow *ui;
};
#endif
