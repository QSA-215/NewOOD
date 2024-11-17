#include "toolbar.h"
#include "commands.h"

void Toolbar::LoadButtons()
{
	m_buttons.push_back(ToolbarButton({ 10, 10 }, sf::Color::Black, "Circle", std::make_shared<AddCircleCommand>()));
	m_buttons.push_back(ToolbarButton({ 70, 10 }, sf::Color::Black, "Rectangle", std::make_shared<AddRectangleCommand>()));
	m_buttons.push_back(ToolbarButton({ 130, 10 }, sf::Color::Black, "Triangle", std::make_shared<AddTriangleCommand>()));
    m_buttons.push_back(ToolbarButton({ 190, 10 }, sf::Color::Red, "Fill Red", std::make_shared<ChangeFillColorCommand>(sf::Color::Red)));
    m_buttons.push_back(ToolbarButton({ 250, 10 }, sf::Color::Green, "Fill Green", std::make_shared<ChangeFillColorCommand>(sf::Color::Green)));
    m_buttons.push_back(ToolbarButton({ 310, 10 }, sf::Color::Blue, "Fill Blue", std::make_shared<ChangeFillColorCommand>(sf::Color::Blue)));
    m_buttons.push_back(ToolbarButton({ 370, 10 }, sf::Color::Red, "Thic Red", std::make_shared<ChangeOutlineColorCommand>(sf::Color::Red)));
    m_buttons.push_back(ToolbarButton({ 430, 10 }, sf::Color::Green, "Thic Green", std::make_shared<ChangeOutlineColorCommand>(sf::Color::Green)));
    m_buttons.push_back(ToolbarButton({ 490, 10 }, sf::Color::Blue, "Thic Blue", std::make_shared<ChangeOutlineColorCommand>(sf::Color::Blue)));
    m_buttons.push_back(ToolbarButton({ 550, 10 }, sf::Color::Black, "Thic 1", std::make_shared<ChangeOutlineThicknessCommand>(1)));
    m_buttons.push_back(ToolbarButton({ 610, 10 }, sf::Color::Black, "Thic 3", std::make_shared<ChangeOutlineThicknessCommand>(3)));
    m_buttons.push_back(ToolbarButton({ 670, 10 }, sf::Color::Black, "Thic 5", std::make_shared<ChangeOutlineThicknessCommand>(5)));
    m_buttons.push_back(ToolbarButton({ 730, 10 }, sf::Color::Yellow, "Undo", std::make_shared<UndoCommand>()));
};

void Toolbar::ButtonClick(const sf::Vector2f& point, std::vector<std::shared_ptr<DrawDecorator>>& shapes, Caretaker& caretaker)
{
    for (int i = 0; i < m_buttons.size(); i++)
    {
        if (m_buttons[i].Contains(point))
        {
            if (i != 12)
                caretaker.Save(std::make_shared<Memento>(shapes));
            m_buttons[i].ExecuteCommand(shapes);
            break;
        }
    }
}

void Toolbar::Draw(sf::RenderWindow& window)
{
    for (auto button : m_buttons)
    {
        button.Draw(window);
    }
}