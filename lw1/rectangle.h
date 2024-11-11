#pragma once
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(Point position, double width, double height);
    Point GetPosition() const;
    double GetWidth() const;
    double GetHeight() const;
    bool IsCompositeShape() const;

private:
    Point m_position;
    double m_width;
    double m_height;
};