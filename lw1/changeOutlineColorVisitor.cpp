#include "changeOutlineColorVisitor.h"

ChangeOutlineColorVisitor::ChangeOutlineColorVisitor(sf::Color newColor)
{
	m_newColor = newColor;
};

void ChangeOutlineColorVisitor::Visit(DrawCircleDecorator& circle)
{
	circle.GetShape().setOutlineColor(m_newColor);
};

void ChangeOutlineColorVisitor::Visit(DrawRectangleDecorator& rectangle)
{
	rectangle.GetShape().setOutlineColor(m_newColor);
};

void ChangeOutlineColorVisitor::Visit(DrawTriangleDecorator& triangle)
{
	triangle.GetShape().setOutlineColor(m_newColor);
};

void ChangeOutlineColorVisitor::Visit(DrawCompositeShapeDecorator& compositeShape)
{
	for (auto& shape : compositeShape.GetShapes())
		shape->Accept(*this);
};