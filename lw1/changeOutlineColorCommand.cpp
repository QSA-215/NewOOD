#include "changeOutlineColorCommand.h"

ChangeOutlineColorCommand::ChangeOutlineColorCommand(sf::Color newColor)
{
	m_newColor = newColor;
};

void ChangeOutlineColorCommand::Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes)
{
	ChangeOutlineColorVisitor visitor(m_newColor);
	for (auto& shape : shapes)
		if (shape->IsSelected())
			shape->Accept(visitor);
};