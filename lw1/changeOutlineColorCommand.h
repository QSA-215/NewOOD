#pragma once
#include "command.h"
#include "changeOutlineColorVisitor.h"

class ChangeOutlineColorCommand : public Command
{
public:
	ChangeOutlineColorCommand(sf::Color newColor);
	void Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes) override;

private:
	sf::Color m_newColor;
};