#pragma once
#include "command.h"
#include "changeOutlineThicknessVisitor.h"

class ChangeOutlineThicknessCommand : public Command
{
public:
	ChangeOutlineThicknessCommand(float newThickness);
	void Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes) override;

private:
	float m_newThickness;
};