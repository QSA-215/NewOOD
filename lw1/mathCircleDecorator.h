#pragma once
#include "mathDecorator.h"
#include "circle.h"

class MathCircleDecorator : public MathDecorator
{
public:
	MathCircleDecorator(std::shared_ptr<Circle> circle);
	double GetPerimeter() const override;
	double GetArea() const override;
	std::string GetParams() const override;

private:
	std::shared_ptr<Circle> m_circle;
};