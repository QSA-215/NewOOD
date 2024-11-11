#include "toolbar.h"
#include "commands.h"

void Toolbar::LoadButtons()
{
	m_buttons.push_back(ToolbarButton({ 10, 10 }, sf::Color::Green, "Circle", std::make_shared<AddCircleCommand>()));
	m_buttons.push_back(ToolbarButton({ 70, 10 }, sf::Color::Green, "Rectangle", std::make_shared<AddRectangleCommand>()));
	m_buttons.push_back(ToolbarButton({ 130, 10 }, sf::Color::Green, "Triangle", std::make_shared<AddTriangleCommand>()));
};

void Toolbar::ButtonClick(const sf::Vector2f& point, std::vector<std::shared_ptr<DrawDecorator>>& shapes)
{
    for (auto button : m_buttons)
    {
        if (button.Contains(point))
        {
            button.ExecuteCommand(shapes);
            break;
        }
    }
}

void Toolbar::Draw(sf::RenderWindow& window)
{
    for (auto button : m_buttons)
    {
        button.Draw(window);
    }
}