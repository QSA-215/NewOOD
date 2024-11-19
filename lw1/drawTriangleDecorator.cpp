#include "drawTriangleDecorator.h"

DrawTriangleDecorator::DrawTriangleDecorator(std::shared_ptr<Triangle> triangle)
{
    m_triangle.setPointCount(3);
    for (int i = 0; i < 3; i++)
    {
        m_triangle.setPoint(i, sf::Vector2f(triangle->GetPoints()[i].x, triangle->GetPoints()[i].y));
    }
    m_triangle.setFillColor(sf::Color::Black);
    m_triangle.setOutlineThickness(2);
    m_triangle.setOutlineColor(sf::Color::Red);

    m_frame.setPosition(m_triangle.getGlobalBounds().getPosition());
    m_frame.setSize(sf::Vector2f(m_triangle.getGlobalBounds().width, m_triangle.getGlobalBounds().height));
    m_frame.setFillColor(sf::Color::Transparent);
    m_frame.setOutlineThickness(2);
    m_frame.setOutlineColor(sf::Color::Magenta);
};

void DrawTriangleDecorator::Draw(sf::RenderWindow& window)
{
    window.draw(m_triangle);
    if (m_isSelected)
        window.draw(m_frame);
};

void DrawTriangleDecorator::Move(const sf::Vector2f& point)
{
    m_triangle.move(point);
    m_frame.move(point);
};

void DrawTriangleDecorator::Select(const bool select)
{
    m_isSelected = select;
};

sf::Vector2f DrawTriangleDecorator::GetPosition() const
{
    return m_triangle.getGlobalBounds().getPosition();
};

sf::Vector2f DrawTriangleDecorator::GetRightDownCorner() const
{
    return sf::Vector2f(m_triangle.getGlobalBounds().getPosition().x + m_triangle.getGlobalBounds().width, m_triangle.getGlobalBounds().getPosition().y + m_triangle.getGlobalBounds().height);
};

bool DrawTriangleDecorator::Contains(const sf::Vector2f& point) const
{
    return m_triangle.getGlobalBounds().contains(point);
};

bool DrawTriangleDecorator::IsSelected() const
{
    return m_isSelected;
};

bool DrawTriangleDecorator::IsCompositeShape() const
{
    return false;
};

void DrawTriangleDecorator::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
};

sf::ConvexShape& DrawTriangleDecorator::GetShape()
{
    return m_triangle;
};

std::shared_ptr<DrawDecorator> DrawTriangleDecorator::Clone() const
{
    return std::make_shared<DrawTriangleDecorator>(*this);
};

std::string DrawTriangleDecorator::GetInfo() const
{
    return "triangle " +
        std::to_string(m_triangle.getPoint(0).x) + " " +
        std::to_string(m_triangle.getPoint(0).y) + " " +
        std::to_string(m_triangle.getPoint(1).x) + " " +
        std::to_string(m_triangle.getPoint(1).y) + " " +
        std::to_string(m_triangle.getPoint(2).x) + " " +
        std::to_string(m_triangle.getPoint(2).y) + " " +
        std::to_string(m_triangle.getFillColor().toInteger()) + " " +
        std::to_string(m_triangle.getOutlineThickness()) + " " +
        std::to_string(m_triangle.getOutlineColor().toInteger());
};