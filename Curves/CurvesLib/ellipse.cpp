#include "ellipse.h"
#include "math.h"

Ellipse::Ellipse(double radX,double radY) : Curve()
{
m_RadX = radX;
m_RadY = radY;
}

Ellipse::~Ellipse()
{

}

std::vector<double> Ellipse::getPoint(double angle)
{
    std::vector<double> result = {m_RadX * cos(angle),m_RadY * sin(angle),0.0};
    return result;
}

std::vector<double> Ellipse::getDerivative(double angle)
{
    std::vector<double> result = {-m_RadX * sin(angle),m_RadY * cos(angle),0.0};
    return result;
}

std::string Ellipse::getDescription()
{
     return std::string("Ellipse: X radius = ") + std::to_string(m_RadX) +
            std::string(", Y radius = ") + std::to_string(m_RadY);
}
