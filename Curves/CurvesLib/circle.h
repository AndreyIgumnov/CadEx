#ifndef CIRCLE_H
#define CIRCLE_H

#include "curve.h"

class CURVESLIB_EXPORT Circle : public Curve
{
public:
    Circle(double radius);
    ~Circle();
    std::vector<double> getPoint(double angle) override;
    std::vector<double> getDerivative(double angle) override;
    std::string getDescription() override;

    double getRadius();
private:
    double m_Radius;
};



#endif // CIRCLE_H
