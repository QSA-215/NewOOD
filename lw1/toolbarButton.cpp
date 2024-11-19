#include "toolbarButton.h"

const float BUTTON_WIDTH = 50;
const float BUTTON_HEIGHT = 50;
const int BUTTON_FONT_SIZE = 18;

ToolbarButton::ToolbarButton(const sf::Vector2f& position, const sf::Color& color, const std::string& text, std::shared_ptr<Command> command)
{
    m_button.setSize({ BUTTON_WIDTH, BUTTON_HEIGHT });
    m_button.setPosition(position);
    m_button.setFillColor(color);

    sf::Font font;
    if (!font.loadFromFile("ArialRegular.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }

    m_label.setFont(font);
    m_label.setString(text);
    m_label.setCharacterSize(BUTTON_FONT_SIZE);
    m_label.setFillColor(sf::Color::Black);
    m_label.setPosition(position.x + 10, position.y + 10);
    m_command = command;
};

void ToolbarButton::Draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    //window.draw(m_label);
};

bool ToolbarButton::Contains(const sf::Vector2f& point) const
{
    return m_button.getGlobalBounds().contains(point);
};

void ToolbarButton::ExecuteCommand(std::vector<std::shared_ptr<DrawDecorator>>& shapes)
{
    if (m_command)
        m_command->Execute(shapes);
};