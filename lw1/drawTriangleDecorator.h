#pragma once
#include "drawDecorator.h"
#include "triangle.h"

class DrawTriangleDecorator : public DrawDecorator
{
public:
	DrawTriangleDecorator(std::shared_ptr<Triangle> triangle);
	void Draw(sf::RenderWindow& window) override;
	void Move(const sf::Vector2f& point) override;
	void Select(const bool select) override;

	sf::Vector2f GetPosition() const override;
	sf::Vector2f GetRightDownCorner() const override;
	bool Contains(const sf::Vector2f& point) const override;
	bool IsSelected() const override;
	bool IsCompositeShape() const override;

private:
	sf::ConvexShape m_triangle;
	sf::RectangleShape m_frame;
	bool m_isSelected = false;
};