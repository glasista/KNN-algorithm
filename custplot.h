#ifndef CUSTPLOT_H
#define CUSTPLOT_H

#include <QWidget>
#include <mainwindow.h>
#include <point.h>

class CustPlot : public QCustomPlot
{

public:
    CustPlot();
    void addPoint(point &wzor);
    MainWindow::ui ui;
};

#endif // CUSTPLOT_H
