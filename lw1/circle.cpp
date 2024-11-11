#pragma once
#include "circle.h"

Circle::Circle(Point position, double radius)
{
	m_position = position;
	m_radius = radius;
};

Point Circle::GetPosition() const
{
	return m_position;
};

double Circle::GetRadius() const
{
	return m_radius;
};

bool Circle::IsCompositeShape() const
{
	return false;
};