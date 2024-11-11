#pragma once
#include "toolbarButton.h"

class Toolbar
{
public:
	void LoadButtons();
	void ButtonClick(const sf::Vector2f& point, std::vector<std::shared_ptr<DrawDecorator>>& shapes);
	void Draw(sf::RenderWindow& window);

private:
	std::vector<ToolbarButton> m_buttons;
};