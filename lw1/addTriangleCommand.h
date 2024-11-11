#pragma once
#include "command.h"
#include "drawTriangleDecorator.h"
#include "Triangle.h"

class AddTriangleCommand : public Command
{
public:
	void Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes) override
	{
		shapes.push_back(std::make_shared<DrawTriangleDecorator>(std::make_shared<Triangle>(Triangle({ 0, 200 }, { 75, 0 }, { 150, 200 }))));
	};
};