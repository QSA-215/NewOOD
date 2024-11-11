#pragma once
#include "mathDecorator.h"
#include "rectangle.h"

class MathRectangleDecorator : public MathDecorator
{
public:
	MathRectangleDecorator(std::shared_ptr<Rectangle> rectangle);
	double GetPerimeter() const override;
	double GetArea() const override;
	std::string GetParams() const override;

private:
	std::shared_ptr<Rectangle> m_rectangle;
};
