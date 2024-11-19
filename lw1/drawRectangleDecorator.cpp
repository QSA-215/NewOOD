#include "drawRectangleDecorator.h"

DrawRectangleDecorator::DrawRectangleDecorator(std::shared_ptr<Rectangle> rectangle)
{
    m_rectangle.setPosition(rectangle->GetPosition().x, rectangle->GetPosition().y);
    m_rectangle.setSize(sf::Vector2f(rectangle->GetWidth(), rectangle->GetHeight()));
    m_rectangle.setFillColor(sf::Color::Black);
    m_rectangle.setOutlineThickness(2);
    m_rectangle.setOutlineColor(sf::Color::Red);

    m_frame.setPosition(m_rectangle.getGlobalBounds().getPosition());
    m_frame.setSize(sf::Vector2f(m_rectangle.getGlobalBounds().width, m_rectangle.getGlobalBounds().height));
    m_frame.setFillColor(sf::Color::Transparent);
    m_frame.setOutlineThickness(2);
    m_frame.setOutlineColor(sf::Color::Magenta);
};

void DrawRectangleDecorator::Draw(sf::RenderWindow& window)
{
    window.draw(m_rectangle);
    if (m_isSelected)
        window.draw(m_frame);
};

void DrawRectangleDecorator::Move(const sf::Vector2f& point)
{
    m_rectangle.move(point);
    m_frame.move(point);
};

void DrawRectangleDecorator::Select(const bool select)
{
    m_isSelected = select;
};

sf::Vector2f DrawRectangleDecorator::GetPosition() const
{
    return m_rectangle.getGlobalBounds().getPosition();
};

sf::Vector2f DrawRectangleDecorator::GetRightDownCorner() const
{
    return sf::Vector2f(m_rectangle.getGlobalBounds().getPosition().x + m_rectangle.getGlobalBounds().width, m_rectangle.getGlobalBounds().getPosition().y + m_rectangle.getGlobalBounds().height);
};

bool DrawRectangleDecorator::Contains(const sf::Vector2f& point) const
{
    return m_rectangle.getGlobalBounds().contains(point);
};

bool DrawRectangleDecorator::IsSelected() const
{
    return m_isSelected;
};

bool DrawRectangleDecorator::IsCompositeShape() const
{
    return false;
};

void DrawRectangleDecorator::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
};

sf::RectangleShape& DrawRectangleDecorator::GetShape()
{
    return m_rectangle;
};

std::shared_ptr<DrawDecorator> DrawRectangleDecorator::Clone() const
{
    return std::make_shared<DrawRectangleDecorator>(*this);
};

std::string DrawRectangleDecorator::GetInfo() const
{
    return "rectangle " +
        std::to_string(m_rectangle.getPosition().x) + " " +
        std::to_string(m_rectangle.getPosition().y) + " " +
        std::to_string(m_rectangle.getSize().x) + " " +
        std::to_string(m_rectangle.getSize().y) + " " +
        std::to_string(m_rectangle.getFillColor().toInteger()) + " " +
        std::to_string(m_rectangle.getOutlineThickness()) + " " +
        std::to_string(m_rectangle.getOutlineColor().toInteger());
};