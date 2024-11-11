#pragma once
#include "command.h"
#include "drawRectangleDecorator.h"
#include "rectangle.h"

class AddRectangleCommand : public Command
{
public:
	void Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes) override
	{
		shapes.push_back(std::make_shared<DrawRectangleDecorator>(std::make_shared<Rectangle>(Rectangle({ 0, 0 }, 200, 100))));
	};
};