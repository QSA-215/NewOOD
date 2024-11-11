#include "drawCompositeShapeDecorator.h"

void DrawCompositeShapeDecorator::MakeFrame()
{
    m_frame.setPosition(GetPosition());
    m_frame.setSize(sf::Vector2f(GetRightDownCorner().x - GetPosition().x, GetRightDownCorner().y - GetPosition().y));
    m_frame.setFillColor(sf::Color::Transparent);
    m_frame.setOutlineThickness(2);
    m_frame.setOutlineColor(sf::Color::Green);
};

void DrawCompositeShapeDecorator::AddShape(std::shared_ptr<DrawDecorator> shape)
{
    m_compositeShape.push_back(shape);
};

void DrawCompositeShapeDecorator::DeleteShape(std::shared_ptr<DrawDecorator> shape)
{
    m_compositeShape.erase(std::remove(m_compositeShape.begin(), m_compositeShape.end(), shape), m_compositeShape.end());
};

std::vector<std::shared_ptr<DrawDecorator>> DrawCompositeShapeDecorator::GetShapes() const
{
    return m_compositeShape;
};

bool DrawCompositeShapeDecorator::IsEmpty() const
{
    return m_compositeShape.empty();
};

void DrawCompositeShapeDecorator::Draw(sf::RenderWindow& window)
{
    for (auto shape : m_compositeShape)
        shape->Draw(window);
    if (m_isSelected)
        window.draw(m_frame);
};

void DrawCompositeShapeDecorator::Move(const sf::Vector2f& point)
{
    for (auto shape : m_compositeShape)
        shape->Move(point);
    m_frame.move(point);
};

void DrawCompositeShapeDecorator::Select(const bool select)
{
    m_isSelected = select;
};

sf::Vector2f DrawCompositeShapeDecorator::GetPosition() const
{
    if (!m_compositeShape.empty())
    {
        float minX = m_compositeShape[0]->GetPosition().x;
        float minY = m_compositeShape[0]->GetPosition().y;
        for (auto shape : m_compositeShape)
        {
            if (shape->GetPosition().x < minX)
                minX = shape->GetPosition().x;
            if (shape->GetPosition().y < minY)
                minY = shape->GetPosition().y;
        }
        return sf::Vector2f(minX, minY);
    }
    return sf::Vector2f(0, 0);
};

sf::Vector2f DrawCompositeShapeDecorator::GetRightDownCorner() const
{
    if (!m_compositeShape.empty())
    {
        float maxX = m_compositeShape[0]->GetRightDownCorner().x;
        float maxY = m_compositeShape[0]->GetRightDownCorner().y;
        for (auto shape : m_compositeShape)
        {
            if (shape->GetRightDownCorner().x > maxX)
                maxX = shape->GetRightDownCorner().x;
            if (shape->GetRightDownCorner().y > maxY)
                maxY = shape->GetRightDownCorner().y;
        }
        return sf::Vector2f(maxX, maxY);
    }
    return sf::Vector2f(0, 0);
};

bool DrawCompositeShapeDecorator::Contains(const sf::Vector2f& point) const
{
    for (auto shape : m_compositeShape)
        if (shape->Contains(point))
            return true;
    return false;
};

bool DrawCompositeShapeDecorator::IsSelected() const
{
    return m_isSelected;
};

bool DrawCompositeShapeDecorator::IsCompositeShape() const
{
    return true;
};