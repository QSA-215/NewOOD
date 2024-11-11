#include "rectangle.h"

Rectangle::Rectangle(Point position, double width, double height)
{
	m_position = position;
	m_width = width;
	m_height = height;
};

Point Rectangle::GetPosition() const
{
	return m_position;
};

double Rectangle::GetWidth() const
{
	return m_width;
};

double Rectangle::GetHeight() const
{
	return m_height;
};

bool Rectangle::IsCompositeShape() const
{
	return false;
};