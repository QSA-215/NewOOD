#include "drawCircleDecorator.h"

DrawCircleDecorator::DrawCircleDecorator(std::shared_ptr<Circle> circle)
{
	m_circle.setPosition(circle->GetPosition().x, circle->GetPosition().y);
	m_circle.setRadius(circle->GetRadius());
    m_circle.setFillColor(sf::Color::Black);
    m_circle.setOutlineThickness(2);
    m_circle.setOutlineColor(sf::Color::Red);

    m_frame.setPosition(m_circle.getGlobalBounds().getPosition());
    m_frame.setSize(sf::Vector2f(m_circle.getGlobalBounds().width, m_circle.getGlobalBounds().height));
    m_frame.setFillColor(sf::Color::Transparent);
    m_frame.setOutlineThickness(2);
    m_frame.setOutlineColor(sf::Color::Magenta);
};

void DrawCircleDecorator::Draw(sf::RenderWindow& window)
{
    window.draw(m_circle);
    if (m_isSelected)
        window.draw(m_frame);
};

void DrawCircleDecorator::Move(const sf::Vector2f& point)
{
    m_circle.move(point);
    m_frame.move(point);
};

void DrawCircleDecorator::Select(const bool select)
{
    m_isSelected = select;
};

sf::Vector2f DrawCircleDecorator::GetPosition() const
{
    return m_circle.getGlobalBounds().getPosition();
};

sf::Vector2f DrawCircleDecorator::GetRightDownCorner() const
{
    return sf::Vector2f(m_circle.getGlobalBounds().getPosition().x + m_circle.getGlobalBounds().width, m_circle.getGlobalBounds().getPosition().y + m_circle.getGlobalBounds().height);
};

bool DrawCircleDecorator::Contains(const sf::Vector2f& point) const
{
    return m_circle.getGlobalBounds().contains(point);
};

bool DrawCircleDecorator::IsSelected() const
{
    return m_isSelected;
};

bool DrawCircleDecorator::IsCompositeShape() const
{
    return false;
};