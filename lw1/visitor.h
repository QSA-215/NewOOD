#pragma once
#include <SFML/Graphics.hpp>

class DrawCircleDecorator;
class DrawRectangleDecorator;
class DrawTriangleDecorator;
class DrawCompositeShapeDecorator;

class Visitor
{
public:
    virtual void Visit(DrawCircleDecorator& circle) = 0;
    virtual void Visit(DrawRectangleDecorator& rectangle) = 0;
    virtual void Visit(DrawTriangleDecorator& triangle) = 0;
    virtual void Visit(DrawCompositeShapeDecorator& compositeShape) = 0;
    virtual ~Visitor() = default;
};