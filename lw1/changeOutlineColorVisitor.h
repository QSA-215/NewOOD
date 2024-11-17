#pragma once
#include "visitor.h"
#include "drawDecorators.h"

class ChangeOutlineColorVisitor : public Visitor
{
public:
    ChangeOutlineColorVisitor(sf::Color newColor);
    void Visit(DrawCircleDecorator& circle) override;
    void Visit(DrawRectangleDecorator& rectangle) override;
    void Visit(DrawTriangleDecorator& triangle) override;
    void Visit(DrawCompositeShapeDecorator& compositeShape) override;

private:
    sf::Color m_newColor;
};