#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>
#include "circle.h"
#include "ellipse.h"
#include "helix.h"

using namespace std;

vector<Curve *> getRandomCurveList()
{
    mt19937 gen(time(0));
    uniform_int_distribution<int> countDist(1,30);
    int count = countDist(gen);

    vector<Curve *> resultList;
    for (int i = 0 ;i < count; i++)
    {uniform_int_distribution<int> typeDist(0,2);
        int type = typeDist(gen);

        switch (type) {
        case 0:
        {
            uniform_real_distribution<double> radDist(0.0,10000.0);
            double randRadius = radDist(gen);
            resultList.push_back( new Circle(randRadius));
            break;
        }
        case 1:
        {
            uniform_real_distribution<double> radDist(0.0,10000.0);
            double randRadiusX = radDist(gen);
            double randRadiusY = radDist(gen);
            resultList.push_back(new Ellipse(randRadiusX,randRadiusY));
            break;
        }
        case 2:
        {
            uniform_real_distribution<double> radDist(0.0,10000.0);
            double randRadius = radDist(gen);
            double randStep = radDist(gen);
            resultList.push_back(new Helix(randRadius,randStep));
            break;
        }
        default:
            break;
        }
    }
    return  resultList;
}


string vectorToString(vector<double> v)
{
  return string("X = ") + to_string(v[0]) +
         string(", Y = ") + to_string(v[1]) +
         string(", Z = ") + to_string(v[2]);
}

struct compareStruct {
    bool operator() (Circle * c1,Circle * c2) {return c1->getRadius() < c2->getRadius();}
};

int main()
{
    vector<Curve *> theCurveVector = getRandomCurveList();

    cout << "List of random 3d curves contains: " << endl;
    int num = 1;
    for (vector<Curve *>::iterator i = theCurveVector.begin() ;i != theCurveVector.end(); ++i)
    {
     cout << num++ << ") " << (*i)->getDescription() << endl;
    }
     cout << "\nCoordinates of points and derivatives at t = Pi/4: " << endl;
     num = 1;
     for (vector<Curve *>::iterator i = theCurveVector.begin() ;i != theCurveVector.end(); ++i)
     {
        cout << num++ << ") Point: " << vectorToString( (*i)->getPoint(M_PI_4)) << "; " <<  endl <<
                  "Derivative: " << vectorToString( (*i)->getDerivative(M_PI_4)) << endl;
     }
     vector<Circle *> circleVector;

     double totalSumOfRadii = 0;
     for (vector<Curve *>::iterator i = theCurveVector.begin() ;i != theCurveVector.end(); ++i)
     {  Circle * c = dynamic_cast<Circle *>(*i );
        if (c != nullptr)
        {
        circleVector.push_back(c);
        totalSumOfRadii += c->getRadius();
        }
     }
     compareStruct compareObject;
     sort(circleVector.begin(),circleVector.end(),compareObject);
     num = 1;
      cout << "\nThe sorted in ascending order list of circles contains: " << endl;
     for (vector<Circle *>::iterator i = circleVector.begin() ;i != circleVector.end(); ++i)
     {
      cout << num++ << ") " << (*i)->getDescription() << endl;
     }
     cout << "\nTotal sum of circle's radius = " << totalSumOfRadii << endl;
    return 0;
}
