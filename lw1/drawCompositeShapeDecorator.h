#pragma once
#include "drawDecorator.h"

class DrawCompositeShapeDecorator : public DrawDecorator
{
public:
	void MakeFrame();
	void AddShape(std::shared_ptr<DrawDecorator> shape);
	void DeleteShape(std::shared_ptr<DrawDecorator> shape);
	std::vector<std::shared_ptr<DrawDecorator>> GetShapes() const;
	bool IsEmpty() const;

	void Draw(sf::RenderWindow& window) override;
	void Move(const sf::Vector2f& point) override;
	void Select(const bool select) override;

	sf::Vector2f GetPosition() const override;
	sf::Vector2f GetRightDownCorner() const override;
	bool Contains(const sf::Vector2f& point) const override;
	bool IsSelected() const override;
	bool IsCompositeShape() const override;

private:
	std::vector<std::shared_ptr<DrawDecorator>> m_compositeShape;
	sf::RectangleShape m_frame;
	bool m_isSelected = true;
};