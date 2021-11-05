#ifndef HELIX_H
#define HELIX_H

#include "curve.h"

class CURVESLIB_EXPORT Helix : public Curve
{
public:
    Helix(double radius,double step);
    ~Helix();
    std::vector<double> getPoint(double angle) override;
    std::vector<double> getDerivative(double angle) override;
    std::string getDescription() override;
private:
    double m_Radius;
    double m_Step;
};

#endif // HELIX_H
