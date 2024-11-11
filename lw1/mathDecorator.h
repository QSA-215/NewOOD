#pragma once
#include "shape.h"
#include <memory>
#include <cmath>
#include <string>

class MathDecorator : public Shape
{
public:
	virtual double GetPerimeter() const = 0;
	virtual double GetArea() const = 0;
	virtual std::string GetParams() const = 0;
};