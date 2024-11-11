#pragma once
#include "mathDecorator.h"
#include "triangle.h"

class MathTriangleDecorator : public MathDecorator
{
public:
	MathTriangleDecorator(std::shared_ptr<Triangle> triangle);
	double GetPerimeter() const override;
	double GetArea() const override;
	std::string GetParams() const override;

private:
	std::shared_ptr<Triangle> m_triangle;
};