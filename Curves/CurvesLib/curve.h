#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include <string>
#include <random>
#include "CurvesLib_global.h"

class Curve
{
public:
virtual std::vector<double> getPoint(double angle) = 0;
virtual std::vector<double> getDerivative(double angle) = 0;
virtual std::string getDescription() = 0;
};




#endif // FIGURE_H
