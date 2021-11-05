#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"

class CURVESLIB_EXPORT Ellipse : public Curve
{
public:
    Ellipse(double radX,double radY);
    ~Ellipse();
    std::vector<double> getPoint(double angle) override;
    std::vector<double> getDerivative(double angle) override;
    std::string getDescription() override;
private:
    double m_RadX;
    double m_RadY;
};

#endif // ELLIPSE_H
