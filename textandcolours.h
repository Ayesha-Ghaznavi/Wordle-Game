#pragma once
#include <SFML/Graphics.hpp>

class textandcolours
{
public:
	void SetColour(sf::Color fillColour);
	void SetText(sf::String string);
	void DrawObject(sf::RenderWindow& window);

	textandcolours(sf::Vector2f size, sf::Vector2f pos, sf::Color fillColour, sf::Text oText);

private:
	sf::RectangleShape rectShape;
	sf::Text text;
};

void textandcolours::SetText(sf::String string)
{
	text.setString(string);
}

void textandcolours::SetColour(sf::Color fillColour)
{
	rectShape.setFillColor(fillColour);
}

void textandcolours::DrawObject(sf::RenderWindow& window)
{
	window.draw(rectShape);
	window.draw(text);
}

textandcolours::textandcolours(sf::Vector2f size, sf::Vector2f pos, sf::Color fillColour, sf::Text oText)
{
	rectShape = sf::RectangleShape(size);
	rectShape.setPosition(pos);
	rectShape.setFillColor(fillColour);
	text = oText;

	// Center text
	text.setPosition(pos);
	float difX = (rectShape.getGlobalBounds().width - text.getGlobalBounds().width) / 4;
	float difY = (rectShape.getGlobalBounds().height - text.getGlobalBounds().height) / 6;
	text.move(difX, difY);
}
