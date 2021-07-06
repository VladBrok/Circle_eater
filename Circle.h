#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML\Graphics.hpp>


class Circle
{
public:

                       Circle(const sf::RenderTarget& window);
    void               update();
    void               render(sf::RenderTarget& target);

private:

    sf::CircleShape    circleShape;
    
    void               initShape(const sf::RenderTarget& window);
};


#endif // CIRCLE_H
