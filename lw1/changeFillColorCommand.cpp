#include "changeFillColorCommand.h"

ChangeFillColorCommand::ChangeFillColorCommand(sf::Color newColor)
{
	m_newColor = newColor;
};

void ChangeFillColorCommand::Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes)
{
	ChangeFillColorVisitor visitor(m_newColor);
	for (auto& shape : shapes)
		if (shape->IsSelected())
			shape->Accept(visitor);
};