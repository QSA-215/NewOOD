#pragma once
#include "shape.h"

class Circle : public Shape
{
public:
    Circle(Point position, double radius);
    Point GetPosition() const;
    double GetRadius() const;
    bool IsCompositeShape() const;

private:
    Point m_position;
    double m_radius;
};