#pragma once
#include "command.h"
#include "application.h"

class UndoCommand : public Command
{
	void Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes) override;
};