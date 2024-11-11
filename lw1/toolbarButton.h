#pragma once
#include <SFML/Graphics.hpp>
#include "command.h"

class ToolbarButton
{
public:
	ToolbarButton(const sf::Vector2f& position, const sf::Color& color, const std::string& text, std::shared_ptr<Command> command);
	void Draw(sf::RenderWindow& window);
	bool Contains(const sf::Vector2f& point) const;
	void ExecuteCommand(std::vector<std::shared_ptr<DrawDecorator>>& shapes);
private:
	sf::RectangleShape m_button;
	sf::Text m_label;
	std::shared_ptr<Command> m_command;
};