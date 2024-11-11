#pragma once
#include "shape.h"
#include <vector>

class Triangle : public Shape
{
public:
    Triangle(Point point1, Point point2, Point point3);
    std::vector<Point> GetPoints() const;
    bool IsCompositeShape() const;

private:
    Point m_point1;
    Point m_point2;
    Point m_point3;
};