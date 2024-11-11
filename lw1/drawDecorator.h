#pragma once
#include <SFML/Graphics.hpp>
#include "shape.h"
#include <memory>

class DrawDecorator : public Shape
{
public:
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void Move(const sf::Vector2f& point) = 0;
	virtual void Select(const bool select) = 0;

	virtual sf::Vector2f GetPosition() const = 0;
	virtual sf::Vector2f GetRightDownCorner() const = 0;
	virtual bool Contains(const sf::Vector2f& point) const = 0;
	virtual bool IsSelected() const = 0;
	virtual bool IsCompositeShape() const = 0;
};