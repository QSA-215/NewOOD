#pragma once
#include "drawDecorator.h"
#include "circle.h"

class DrawCircleDecorator : public DrawDecorator
{
public:
	DrawCircleDecorator(std::shared_ptr<Circle> circle);
	void Draw(sf::RenderWindow& window) override;
	void Move(const sf::Vector2f& point) override;
	void Select(const bool select) override;

	sf::Vector2f GetPosition() const override;
	sf::Vector2f GetRightDownCorner() const override;
	bool Contains(const sf::Vector2f& point) const override;
	bool IsSelected() const override;
	bool IsCompositeShape() const override;

	void Accept(Visitor& visitor) override;
	sf::CircleShape& GetShape();

private:
	sf::CircleShape m_circle;
	sf::RectangleShape m_frame;
	bool m_isSelected = false;
};