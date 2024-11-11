#include "mathRectangleDecorator.h"

MathRectangleDecorator::MathRectangleDecorator(std::shared_ptr<Rectangle> rectangle)
{
	m_rectangle = rectangle;
};

double MathRectangleDecorator::GetPerimeter() const
{
	return 2 * (m_rectangle->GetHeight() + m_rectangle->GetWidth());
};

double MathRectangleDecorator::GetArea() const
{
	return m_rectangle->GetHeight() * m_rectangle->GetWidth();
};

std::string MathRectangleDecorator::GetParams() const
{
	return "RECTANGLE: P = " + std::to_string(GetPerimeter()) + "; S = " + std::to_string(GetArea()) + ";\n";
};