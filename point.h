#ifndef POINT_H
#define POINT_H

#include <vector>
#include <string>
#include <QString>
using namespace std;


class point
{
public:
    point(){};
    point(double new_x, double new_y/*, char* newCat*/);
    void SetDistance(double dis)
    {
        distance=dis;
    }

    void SetCat(int x)
    {
        Category=x;
    }
    double getx()
    {
        return m_nx;
    }
    double gety()
    {
        return m_ny;
    }


    double calc_distance(const point& XYZ,QString name);
    int category();
    bool operator<(const point&x);
    //sort(all_points.begin(),all_points.end());
private:
    double m_nx;
    double m_ny;
    int Category;
    double distance;
    int RankMinDist;

};

#endif // POINT_H
