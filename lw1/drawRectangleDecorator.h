#pragma once
#include "drawDecorator.h"
#include "rectangle.h"

class DrawRectangleDecorator : public DrawDecorator
{
public:
	DrawRectangleDecorator(std::shared_ptr<Rectangle> rectangle);
	void Draw(sf::RenderWindow& window) override;
	void Move(const sf::Vector2f& point) override;
	void Select(const bool select) override;

	sf::Vector2f GetPosition() const override;
	sf::Vector2f GetRightDownCorner() const override;
	bool Contains(const sf::Vector2f& point) const override;
	bool IsSelected() const override;
	bool IsCompositeShape() const override;

private:
	sf::RectangleShape m_rectangle;
	sf::RectangleShape m_frame;
	bool m_isSelected = false;
};