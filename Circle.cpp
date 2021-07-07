#include "Circle.h"
#include <iostream>


Circle::Circle(const sf::RenderTarget& window, const Type type)
    : circleType(type)
{
    initShape(window);
}


void Circle::render(sf::RenderTarget& target)
{
    target.draw(circleShape);
}


const sf::FloatRect Circle::getGlobalBounds() const
{
    return circleShape.getGlobalBounds();
}


const Circle::Type Circle::getType() const
{
    return circleType;
}


void Circle::initShape(const sf::RenderTarget& window)
{
    circleShape.setRadius(rand() % 10 + 5.f);
    sf::Color color;
    switch (circleType)
    {
    case DEFAULT:
        color = sf::Color(rand() % 200 + 56, rand() % 200 + 56, rand() % 200 + 56);
        break;
    case DAMAGING:
        color = sf::Color(sf::Color::Red);
        circleShape.setOutlineColor(sf::Color(137, 0, 0));
        circleShape.setOutlineThickness(3.f);
        break;
    case HEALING:
        color = sf::Color(sf::Color::Green);
        circleShape.setOutlineColor(sf::Color(0, 137, 59));
        circleShape.setOutlineThickness(3.f);
        break;
    default:
        std::cout << " ! ERROR in Circle::initShape: invalid circle type.\n";
    }

    circleShape.setFillColor(color);
    circleShape.setPosition(
        rand() % (int)(window.getSize().x - circleShape.getRadius() * 2), 
        rand() % (int)(window.getSize().y - circleShape.getRadius() * 2)
    ); 
}