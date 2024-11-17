#pragma once
#include "command.h"
#include "changeFillColorVisitor.h"

class ChangeFillColorCommand : public Command
{
public:
	ChangeFillColorCommand(sf::Color newColor);
	void Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes) override;

private:
	sf::Color m_newColor;
};