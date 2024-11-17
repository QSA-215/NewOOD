#pragma once
#include "visitor.h"
#include "drawDecorators.h"

class ChangeOutlineThicknessVisitor : public Visitor
{
public:
    ChangeOutlineThicknessVisitor(float newOutlineThickness);
    void Visit(DrawCircleDecorator& circle) override;
    void Visit(DrawRectangleDecorator& rectangle) override;
    void Visit(DrawTriangleDecorator& triangle) override;
    void Visit(DrawCompositeShapeDecorator& compositeShape) override;

private:
    float m_newOutlineThickness;
};