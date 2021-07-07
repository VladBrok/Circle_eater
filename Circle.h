#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML\Graphics.hpp>


class Circle
{
public:
    enum Type
    {
        DEFAULT,
        DAMAGING,
        HEALING,
        NUMBER_OF_TYPES
    };

                            Circle(const sf::RenderTarget& window, const Type type);
    void                    render(sf::RenderTarget& target);
    const sf::FloatRect     getGlobalBounds() const;
    const Type              getType() const;

private:

    sf::CircleShape         circleShape;
    Type                    circleType;

    void                    initShape(const sf::RenderTarget& window);
};


#endif // CIRCLE_H
