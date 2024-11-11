#define _USE_MATH_DEFINES
#include "mathCircleDecorator.h"

MathCircleDecorator::MathCircleDecorator(std::shared_ptr<Circle> circle)
{
	m_circle = circle;
};

double MathCircleDecorator::GetPerimeter() const
{
	return M_PI * 2 * m_circle->GetRadius();
};

double MathCircleDecorator::GetArea() const
{
	return M_PI * pow(m_circle->GetRadius(), 2);
};

std::string MathCircleDecorator::GetParams() const
{
	return "CIRCLE: P = " + std::to_string(GetPerimeter()) + "; S = " + std::to_string(GetArea()) + ";\n";
};