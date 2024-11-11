#pragma once
#include "triangle.h"

Triangle::Triangle(Point point1, Point point2, Point point3)
{
	m_point1 = point1;
	m_point2 = point2;
	m_point3 = point3;
};

std::vector<Point> Triangle::GetPoints() const
{
	return { m_point1, m_point2, m_point3 };
};

bool Triangle::IsCompositeShape() const
{
	return false;
};