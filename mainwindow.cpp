#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    connect(ui->widget, SIGNAL(plotClick(QMouseEvent*)), this, SLOT(plotClick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_actionOtw_rz_Plik_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Otwórz..."),"/home/",tr("Pliki txt (*.txt)"));
    u.odczyt_pliku(fileName);
   // vector <string> categories=u.get_cat();
}
void MainWindow::on_Calculate_clicked()
{

    string cat;
    QString Qcat;


    int k=ui->spinBox->value();
    if (u.get_size()!=0)
	{
        QString name=getDisMet();
        cat = u.Calculate(&k, predPoint,name);
        Qcat=QString::fromStdString(cat);
        QString status = QString("Punkt (%1 , %2 ) przydzielono do: ").arg(predPoint.getx()).arg(predPoint.gety())+Qcat;
        QMessageBox::information(this,"Wynik obliczeń",status,QMessageBox::Ok);
        u.addNewPoint(predPoint.gety(),predPoint.getx(),cat);


	}
	else
    {
        MsgBox.setText("Najpierw podaj dane.");
        MsgBox.exec();
    }

	
}

void MainWindow::on_update_clicked()
{
    ui->widget->clearGraphs();
    size_t ile=u.get_size_cat();
    if(ile>0)
    {
//        initializer_list cos<QCPScatterStyle::ssCross,QCPScatterStyle::ssCrossCircle,QCPScatterStyle::ssCrossSquare,QCPScatterStyle::ssPlus,QCPScatterStyle::ssDisc,
//                    QCPScatterStyle::ssTriangle,QCPScatterStyle::ssTriangleInverted,QCPScatterStyle::ssPlusSquare,QCPScatterStyle::ssPlusCircle>;
        vector <QCPScatterStyle::ScatterShape>QCPSStyle ({QCPScatterStyle::ssCross,QCPScatterStyle::ssCrossCircle,QCPScatterStyle::ssCrossSquare,QCPScatterStyle::ssPlus,QCPScatterStyle::ssDisc,
                                             QCPScatterStyle::ssTriangle,QCPScatterStyle::ssTriangleInverted,QCPScatterStyle::ssPlusSquare,QCPScatterStyle::ssPlusCircle});

        ui->widget->yAxis->setRange(u.minx()-10,u.maxx()+20);
        ui->widget->xAxis->setRange(u.miny()-10,u.maxy()+20);
        QVector<QVector<double>>dane;
        //addPredPoint(predPoint.getx(),predPoint.gety());
        for(int i=0;i<ile;i++)
        {

            QVector<QVector<double>>dane=u.getdata(&i);
            ui->widget->addGraph(ui->widget->yAxis, ui->widget->xAxis);

            ui->widget->graph(ui->widget->graphCount()-1)->setLineStyle(QCPGraph::lsNone);
            ui->widget->graph(ui->widget->graphCount()-1)->setScatterStyle(QCPScatterStyle(QCPSStyle[i],10));
            int r=rand()%255;
            int g=rand()%255;
            int b=rand()%255;
            ui->widget->graph(ui->widget->graphCount()-1)->setPen(QPen(QColor(r,g,b))); //(QColor::setCmykF(i,3*i/10,2*i+2/12,i/3));
            ui->widget->graph(ui->widget->graphCount()-1)->setData(dane[1],dane[0]);
            ui->widget->graph(ui->widget->graphCount()-1)->addToLegend();
            ui->widget->replot();

        }
    }
    else
    {
        MsgBox.setText("Najpierw podaj dane.");
        MsgBox.exec();
    }
}


QString MainWindow::getDisMet()
{
    if(ui->euklides->isChecked()==true) return ui->euklides->objectName();
    if(ui->cityblock->isChecked()==true) return ui->cityblock->objectName();
    if(ui->canbeer->isChecked()==true) return ui->canbeer->objectName();
    return ui->euklides->objectName();
}

void MainWindow::on_isPrediction_stateChanged(int arg1)
{
	ui->categoryEdit->setDisabled(arg1);
}

void MainWindow::addPredPoint(double x, double y)
{
    predPoint=point(x,y);
    ui->widget->addGraph(ui->widget->yAxis, ui->widget->xAxis);
    ui->widget->graph(ui->widget->graphCount()-1)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(ui->widget->graphCount()-1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar,10));
    ui->widget->graph(ui->widget->graphCount()-1)->addData(predPoint.gety(),predPoint.getx());
    ui->widget->graph(ui->widget->graphCount()-1)->setName("Prognozowane dane");
    ui->widget->graph(ui->widget->graphCount()-1)->addToLegend();
    ui->widget->replot();
}

void MainWindow::on_AddPoint_clicked()
{
    if(ui->isPrediction->checkState())
    {
        switch(QMessageBox::warning(this,tr("Uwaga!"),tr("Poprzednie dane X i Y punktu podanego do prognozowania zostaną zastąpione. "
                       "Aby nie utracić poprzednich danych kliknij oblicz. ( Wynik działania algorytmu zostanie dodany do danych treningowych) \n Czy chcesz kontynuować?"),QMessageBox::Apply|QMessageBox::Abort,QMessageBox::Abort))
        {
        case QMessageBox::Apply:
                addPredPoint(ui->XspinBox->value(),ui->YspinBox->value());
                break;

        default: break;
        }
    }
    else
        u.addNewPoint(ui->YspinBox->value(),ui->XspinBox->value(),ui->categoryEdit->text().toStdString());
}


void MainWindow::on_actionInformacje_triggered()
{
    QMessageBox::information(this,"O programie", "Program przydziela punkt do jednej z kategorii za pomocą algorytmu K-Nearest Neighbor(KNN). "
                                                 "Korzystając przy tym z danych treningowych pobieranych z pliku tekstowego oraz dodanych ręcznie za pomocą programu."
                                                 "Możliwy jest wybór sposobu obliczania miar odległości pomiędzy punktami. \n\n"
                                                 "Copyright by Rafał Ruszała in 2017\n"
                                                 "Licencja GNU GPL 3",QMessageBox::Ok);
}

void MainWindow::on_actionZapisz_wykres_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Zapisz ...","/home/","Plik JGP(*.jpg");
    ui->widget->saveJpg( fileName,  0, 0, 1.0, -1  );
}

void MainWindow::on_actionZamknij_triggered()
{
    close();
}


void MainWindow::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0)
    {
        //ui->widget->yAxis->scaleRange(e);
    }
}
