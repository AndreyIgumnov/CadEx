#include "helix.h"
#include "math.h"

Helix::Helix(double radius,double step) : Curve()
{
    m_Radius = radius;
    m_Step = step;
}

Helix::~Helix()
{

}

std::vector<double> Helix::getPoint(double angle)
{
    std::vector<double> result = {m_Radius * cos(angle),m_Radius * sin(angle),m_Step * angle / (2 * M_PI)};
    return result;
}

std::vector<double> Helix::getDerivative(double angle)
{
    std::vector<double> result = {-m_Radius * sin(angle),m_Radius * cos(angle),m_Step / (2 * M_PI)};
    return result;
}

std::string Helix::getDescription()
{
    return std::string("3D Helix: Radius = ") + std::to_string(m_Radius) +
           std::string(", Step = ") + std::to_string(m_Step);
}
