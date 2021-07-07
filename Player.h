#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>


class Player
{
public:

                            Player();
    void                    update(const sf::RenderTarget& target);
    void                    render(sf::RenderTarget& target);
    void                    resize(float additionalSize);
    void                    reduceHealth(const int healthPoints);
    void                    gainHealth(const int healthPoints);
    const sf::FloatRect     getGlobalBounds() const;
    const int               getHealth() const;
    const int               getMaxHealth() const;

private:

    sf::RectangleShape      playerShape;
    const float             MIN_PLAYER_SIZE;
    const float             MAX_PLAYER_SIZE;
    const int               MAX_HEALTH;
    int                     health;
    float                   movementSpeed;

    void                    initShape();
    void                    initVariables();
    void                    updateInput();   // Reacting on pressed keys
    void                    checkWindowCollision(const sf::RenderTarget& window);
};


#endif // PLAYER_H
