#pragma once
#include "shape.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include "visitor.h"

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

	virtual void Accept(Visitor& visitor) = 0;

	virtual std::shared_ptr<DrawDecorator> Clone() const = 0;

	virtual std::string GetInfo() const = 0;
};