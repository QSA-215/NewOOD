#pragma once
#include "drawDecorator.h"

class Command
{
public:
	virtual void Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes) = 0;
	virtual ~Command() = default;
};