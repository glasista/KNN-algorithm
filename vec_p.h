#ifndef VEC_P_H
#define VEC_P_H

#include"point.h"
#include <fstream>
#include <QMessageBox>
#include <QFileDialog>
using namespace std;

class vec_p
{

public:
    vec_p();

    QVector<QVector<double>> getdata(int* i);
    string Calculate(int* k,const point&xyz,QString name);

    void odczyt_pliku(QString fileName);
    void Calc_Distances(const point& xyz,QString name);
	string MostRepeatedCategory(int* k);
    vector <string> get_cat();

    void addNewPoint(double x, double y ,string cat);
    size_t get_size_cat();
    size_t get_size()
    {
        return all_points.size();
    }
	void set_cat(point &p, string x);
    double maxy(){
        return maxY;
    }
    double maxx(){
        return maxX;
    }
    double minx(){
        return minX;
    }
    double miny(){
        return minY;
    }
    //void newPredPoint(double x, double y);
private:
    //point predPoint;
    QMessageBox Msg;
    vector <point> all_points;
    vector <string> v_cat;
    vector <string>::iterator it,it2;
    double maxX;
    double maxY;
    double minX;
    double minY;
};

#endif // VEC_P_H

