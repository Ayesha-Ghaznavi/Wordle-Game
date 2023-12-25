#pragma once
#include <SFML/Graphics.hpp>

class consolebuttons
{
public:
    enum ButtonType
    {
        Letter, Enter, Delete, Reset
    };
    ButtonType GetButtonType();
    sf::String GetText();

    void SetColour(sf::Color fillColour);
    void DrawObject(sf::RenderWindow& window);

    bool MouseCollides(sf::Mouse mouse, sf::RenderWindow& window);

    consolebuttons(sf::Vector2f size, sf::Vector2f pos, sf::Color fillColour, sf::Text oText, ButtonType type);

private:
    ButtonType buttonType;
    sf::RectangleShape rectShape;
    sf::Text text;
};

sf::String consolebuttons::GetText()
{
    return text.getString();
}

consolebuttons::ButtonType consolebuttons::GetButtonType()
{
    return buttonType;
}

void consolebuttons::SetColour(sf::Color fillColour)
{
    rectShape.setFillColor(fillColour);
}

bool consolebuttons::MouseCollides(sf::Mouse mouse, sf::RenderWindow& window)
{
    sf::FloatRect fRect = rectShape.getGlobalBounds();
    sf::Vector2i mousePosition = mouse.getPosition(window);

    if ((mousePosition.x >= fRect.left &&
        mousePosition.x <= fRect.left + fRect.width) &&
        (mousePosition.y >= fRect.top &&
            mousePosition.y <= fRect.top + fRect.height))
        return true;
    else return false;
}

void consolebuttons::DrawObject(sf::RenderWindow& window)
{
    window.draw(rectShape);
    window.draw(text);
}

consolebuttons::consolebuttons(sf::Vector2f size, sf::Vector2f pos, sf::Color fillColour, sf::Text oText, ButtonType type)
{
    rectShape = sf::RectangleShape(size);
    rectShape.setPosition(pos);
    rectShape.setFillColor(fillColour);
    text = oText;

    // Center text
    text.setPosition(pos);
    float difX = (rectShape.getGlobalBounds().width - text.getGlobalBounds().width) / 8;
    float difY = (rectShape.getGlobalBounds().height - text.getGlobalBounds().height) / 8;
    text.move(difX, difY);

    buttonType = type;
}
