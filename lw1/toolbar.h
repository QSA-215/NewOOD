#pragma once
#include "toolbarButton.h"
#include "caretaker.h"

class Toolbar
{
public:
	void LoadButtons();
	void ButtonClick(const sf::Vector2f& point, std::vector<std::shared_ptr<DrawDecorator>>& shapes, Caretaker& caretaker);
	void Draw(sf::RenderWindow& window);

private:
	std::vector<ToolbarButton> m_buttons;
};