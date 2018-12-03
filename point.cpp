#include "point.h"


point::point(double new_x, double new_y/*,char* newCat*/)
    //:Dl(0)
{
    m_nx=new_x;
    m_ny=new_y;
}

double point::calc_distance(const point& WhoIsThis, QString name)
{

    if(name=="cityblock")
    {
        double suma=0;
        suma=abs(this->m_nx-WhoIsThis.m_nx)+abs(this->m_ny-WhoIsThis.m_ny);
        return suma;
    }
    if(name=="canbeer")
    {
        double dis=0;
        dis=abs((m_nx-WhoIsThis.m_nx)/(m_nx+WhoIsThis.m_nx));
        dis+=abs((m_ny-WhoIsThis.m_ny)/(m_ny+WhoIsThis.m_ny));
        return dis;
    }
    if(name=="euklides")
   {
        double dis=0;
        dis=sqrt(pow(this->m_nx-WhoIsThis.m_nx,2)+pow(this->m_ny-WhoIsThis.m_ny,2));
        return dis;
    }
}

int point::category()
{
    return Category;
}

bool point::operator<(const point&x)
{
    return this->distance<x.distance;
}
