#pragma once
#include "command.h"
#include "drawCircleDecorator.h"
#include "circle.h"

class AddCircleCommand : public Command
{
public:
	void Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes) override
	{
		shapes.push_back(std::make_shared<DrawCircleDecorator>(std::make_shared<Circle>(Circle({ 0, 0 }, 50))));
	};
};