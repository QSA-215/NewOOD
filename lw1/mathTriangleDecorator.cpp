#include "mathTriangleDecorator.h"

MathTriangleDecorator::MathTriangleDecorator(std::shared_ptr<Triangle> triangle)
{
	m_triangle = triangle;
};

double MathTriangleDecorator::GetPerimeter() const
{
	double perimeter = 0;
	perimeter += sqrt(pow(m_triangle->GetPoints()[1].x - m_triangle->GetPoints()[0].x, 2) + pow(m_triangle->GetPoints()[1].y - m_triangle->GetPoints()[0].y, 2));
	perimeter += sqrt(pow(m_triangle->GetPoints()[2].x - m_triangle->GetPoints()[1].x, 2) + pow(m_triangle->GetPoints()[2].y - m_triangle->GetPoints()[1].y, 2));
	perimeter += sqrt(pow(m_triangle->GetPoints()[0].x - m_triangle->GetPoints()[2].x, 2) + pow(m_triangle->GetPoints()[0].y - m_triangle->GetPoints()[2].y, 2));
	return perimeter;
};

double MathTriangleDecorator::GetArea() const
{
	const Point p1 = m_triangle->GetPoints()[0];
	const Point p2 = m_triangle->GetPoints()[1];
	const Point p3 = m_triangle->GetPoints()[2];
	double line1 = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
	double line2 = std::sqrt(std::pow(p3.x - p2.x, 2) + std::pow(p3.y - p2.y, 2));
	double line3 = std::sqrt(std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2));
	double semiperimeter = (line1 + line2 + line3) / 2;
	return std::sqrt(semiperimeter * (semiperimeter - line1) * (semiperimeter - line2) * (semiperimeter - line3));
};

std::string MathTriangleDecorator::GetParams() const
{
	return "TRIANGLE: P = " + std::to_string(GetPerimeter()) + "; S = " + std::to_string(GetArea()) + ";\n";
};