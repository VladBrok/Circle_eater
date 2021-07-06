#include "Circle.h"


Circle::Circle(const sf::RenderTarget& window)
{
    initShape(window);
}


void Circle::update()
{
}


void Circle::render(sf::RenderTarget& target)
{
    target.draw(circleShape);
}


void Circle::initShape(const sf::RenderTarget& window)
{
    circleShape.setRadius(rand() % 10 + 5.f);
    circleShape.setFillColor(sf::Color(rand() % 200 + 56, rand() % 200 + 56, rand() % 200 + 56));
    circleShape.setPosition(
        rand() % (int)(window.getSize().x - circleShape.getRadius() * 2), 
        rand() % (int)(window.getSize().y - circleShape.getRadius() * 2)
    ); 
}