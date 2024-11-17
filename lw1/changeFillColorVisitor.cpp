#include "changeFillColorVisitor.h"

ChangeFillColorVisitor::ChangeFillColorVisitor(sf::Color newColor)
{
	m_newColor = newColor;
};

void ChangeFillColorVisitor::Visit(DrawCircleDecorator& circle)
{
	circle.GetShape().setFillColor(m_newColor);
};

void ChangeFillColorVisitor::Visit(DrawRectangleDecorator& rectangle)
{
	rectangle.GetShape().setFillColor(m_newColor);
};

void ChangeFillColorVisitor::Visit(DrawTriangleDecorator& triangle)
{
	triangle.GetShape().setFillColor(m_newColor);
};

void ChangeFillColorVisitor::Visit(DrawCompositeShapeDecorator& compositeShape)
{
	for (auto& shape : compositeShape.GetShapes())
		shape->Accept(*this);
};