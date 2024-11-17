#include "ChangeOutlineThicknessVisitor.h"

ChangeOutlineThicknessVisitor::ChangeOutlineThicknessVisitor(float newOutlineThickness)
{
	m_newOutlineThickness = newOutlineThickness;
};

void ChangeOutlineThicknessVisitor::Visit(DrawCircleDecorator& circle)
{
	circle.GetShape().setOutlineThickness(m_newOutlineThickness);
};

void ChangeOutlineThicknessVisitor::Visit(DrawRectangleDecorator& rectangle)
{
	rectangle.GetShape().setOutlineThickness(m_newOutlineThickness);
};

void ChangeOutlineThicknessVisitor::Visit(DrawTriangleDecorator& triangle)
{
	triangle.GetShape().setOutlineThickness(m_newOutlineThickness);
};

void ChangeOutlineThicknessVisitor::Visit(DrawCompositeShapeDecorator& compositeShape)
{
	for (auto& shape : compositeShape.GetShapes())
		shape->Accept(*this);
};