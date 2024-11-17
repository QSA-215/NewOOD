#include "changeOutlineThicknessCommand.h"

ChangeOutlineThicknessCommand::ChangeOutlineThicknessCommand(float newThickness)
{
	m_newThickness = newThickness;
};

void ChangeOutlineThicknessCommand::Execute(std::vector<std::shared_ptr<DrawDecorator>>& shapes)
{
	ChangeOutlineThicknessVisitor visitor(m_newThickness);
	for (auto& shape : shapes)
		if (shape->IsSelected())
			shape->Accept(visitor);
};