#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H
#include <QMainWindow>
#include <QPainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
   public:
    MainWindow(QWidget* parent = 0);
    virtual ~MainWindow();
    virtual void paintEvent(QPaintEvent* event);

   private:
    Ui::MainWindow* ui;
};

#endif