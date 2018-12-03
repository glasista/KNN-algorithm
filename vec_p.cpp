#include "vec_p.h"

vec_p::vec_p()
{
    minX=100;
    minY=100;
    maxX=5;
    maxY=5;
}
void vec_p()
{

}

string vec_p::Calculate(int* k,const point& xyz,QString name)
{
	if (v_cat.size()>0)
	{
        Calc_Distances(xyz,name);
		sort(all_points.begin(),all_points.end());
        return MostRepeatedCategory(k);
    }
    else return "Błąd";
//    else
//        QMessageBox::warning(Msg,"Błąd","Błąd obliczeń",QMessageBox::Ok);
}


void vec_p::odczyt_pliku(QString fileName)  
{
    all_points=vector <point>();
    v_cat=vector <string>();
    
    double first, second;
    string line,cat;
    wstring name;
    name = fileName.toStdWString();
    fstream plik;
   
	plik.open(name,ios::in);
	if(plik.is_open() )
		while (!plik.eof())
		{
			cat = "";
			getline(plik, line);
			char* txt = new char[line.size() + 1];
			strcpy(txt, line.c_str());
			first = strtof(txt, &txt);
            second = strtof(txt, &txt);
			
			line = line.substr(line.find(txt, 1),line.size()-line.find(txt, 1));
			for (int i = 0; i < line.size(); i++)
			{
				if (line[i]==' '|| line[i] > 96 && line[i] < 123 || line[i] > 64 && line[i] < 91 ) 
				{
					if(i!=0 && line[i] != ' ')
					cat=cat+ line[i];
				}
			}
            addNewPoint(first,second,cat);
		}
    plik.close();
}

void vec_p::Calc_Distances(const point&xyz,QString name)
{
	for (int i = 0; i<all_points.size(); i++)
	{
        all_points[i].SetDistance(all_points[i].calc_distance(xyz,name));
	}
}

string vec_p::MostRepeatedCategory(int* k)
{
    vector<int> count(0,0);
	count.resize(v_cat.size());
	int x = 0;
    for (int i = 0; i<*k; i++)
	{
        it = v_cat.begin();
        advance(it, all_points[i].category());

        for (it2 = v_cat.begin(); it2 < v_cat.end(); it2++)
		{
			if (*it == *it2)
			{
				x = distance(v_cat.begin(), it2);
				count[x]++;
			}
		}
	}
	x = distance(count.begin(), max_element(count.begin(), count.end()));
    it=v_cat.begin()+x;
    return *it;
}

size_t vec_p::get_size_cat()
{
    return v_cat.size();
}

QVector<QVector<double>> vec_p::getdata(int* j)
{

    QVector<double>x;
    QVector<double>y;

    for(int i=0;i<all_points.size();i++)
    {
        if(all_points[i].category()==*j)
        {
            x.push_back(all_points[i].getx());
            y.push_back(all_points[i].gety());
        }
    }

    QVector<QVector<double>> data(2);
    data[0]=x;
    data[1]=y;
    return data;
}

vector <string> vec_p::get_cat()
{
    return v_cat;
}


void vec_p::set_cat(point & p, string x)
{
	p.SetCat(find(v_cat.begin(), v_cat.end(), x) - v_cat.begin());
}


void vec_p::addNewPoint(double x,double y,string cat)
{
    if(cat!="")
        {
        if (v_cat.size() != 0)
        {
            it = find(v_cat.begin(), v_cat.end(), cat);
            if (it == v_cat.end() && cat != "")
                v_cat.push_back(cat);
        }
        else
        {
            v_cat.push_back(cat);
        }
        it = find(v_cat.begin(), v_cat.end(), cat);
        if (it != v_cat.end())
        {
            if(maxY<y)maxY=y;
            if(maxX<x)maxX=x;
            if(minX>x)minX=x;
            if(minY>y)minY=y;
            point p(y,x);
            all_points.push_back(p);
            all_points[all_points.size() - 1].SetCat(distance(v_cat.begin(),it));
        }
    }
    else
    {
        Msg.setWindowTitle("BŁĄD. Brak danych");
        Msg.setText("Brak kategorii, punkt niedodany") ;
        Msg.setWindowTitle("Błąd. Brakujące dane w pliku.");

    }
}
