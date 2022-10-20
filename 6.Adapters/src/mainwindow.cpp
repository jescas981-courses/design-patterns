#include <mainwindow.h>
#include <cmath>
#include <memory>
#include <Geometry.h>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {}



void MainWindow::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    std::vector<std::shared_ptr<VectorObject>> vectorObjects{
        std::make_shared<VectorRectangle>(50, 50, 300, 300),
        std::make_shared<VectorRectangle>(125, 125, 150, 150)};
    for (auto& o : vectorObjects) {
        for (auto& l : *o) {
            LineToPointCachingAdapter lpo{l};
            for (auto i = lpo.begin(); i != lpo.end(); ++i) {
                painter.drawPoint(QPoint{i->x, i->y});
            }
        }
    }
}