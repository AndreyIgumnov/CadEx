#include "circle.h"
#include "math.h"

Circle::Circle(double radius) : Curve()
{
    m_Radius = radius;
}

Circle::~Circle()
{

}

std::vector<double> Circle::getPoint(double angle)
{
    std::vector<double> result = {m_Radius * cos(angle),m_Radius * sin(angle),0.0};
    return result;
}

std::vector<double> Circle::getDerivative(double angle)
{
    std::vector<double> result = { -m_Radius * sin(angle),m_Radius * cos(angle),0.0};
    return result;
}

std::string Circle::getDescription()
{
    return std::string("Circle: Radius = ") + std::to_string(m_Radius);
}

double Circle::getRadius()
{
    return m_Radius;
}
