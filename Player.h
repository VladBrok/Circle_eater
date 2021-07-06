#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>


class Player
{
public:

                            Player();
    void                    update(const sf::RenderTarget& target);
    void                    render(sf::RenderTarget& target);

private:

    sf::RectangleShape      playerShape;
    float                   movementSpeed;

    void                    initShape();
    void                    initVariables();
    void                    updateInput();   // Reacting on pressed keys
    void                    checkWindowCollision(const sf::RenderTarget& window);
};


#endif // PLAYER_H
