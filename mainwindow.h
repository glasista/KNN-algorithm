#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vec_p.h"
//#include <QMainWindow>
//#include <QMessageBox>
#include <point.h>
#include "vec_p.h"
#include <qcustomplot.h>




namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_actionOtw_rz_Plik_triggered();

    void on_Calculate_clicked();

    void on_update_clicked();

    void on_isPrediction_stateChanged(int arg1);

    void on_AddPoint_clicked();
    void addPredPoint(double x, double y);
    QString getDisMet();
    void on_actionInformacje_triggered();

    void on_actionZapisz_wykres_triggered();

    void on_actionZamknij_triggered();

private:
    point predPoint;
    QMessageBox MsgBox;
    vec_p u;
    Ui::MainWindow *ui;
protected:
    virtual void wheelEvent(QWheelEvent *event);


};

#endif // MAINWINDOW_H
