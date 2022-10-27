#ifndef ADVANCED_SEARCH_WINDOW_H
#define ADVANCED_SEARCH_WINDOW_H

#include <QMainWindow>

namespace Ui {
class advanced_search_window;
}

class advanced_search_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit advanced_search_window(QWidget *parent = nullptr);
    ~advanced_search_window();

private:
    Ui::advanced_search_window *ui;
};

#endif // ADVANCED_SEARCH_WINDOW_H
