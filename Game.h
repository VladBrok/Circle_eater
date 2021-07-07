#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Circle.h"
#include <list>


class Game
{
public:

                         Game();
    const bool           isRunning() const;
    const bool           isOver() const;
    void                 pollEvents();
    void                 update();
    void                 render();

private:

    sf::RenderWindow     window;
    sf::Event            event;
    bool                 gameOver;

    Player               player;
    int                  points;

    std::list<Circle>    circles;
    const int            MAX_CIRCLES;
    const int            TIME_TO_SPAWN_CIRCLE;
    int                  circleSpawnTimer;

    sf::Font             font;
    sf::Text             guiText;
    sf::Text             gameOverText;

    void                 initVariables();
    void                 initText();
    void                 spawnCircle();
    void                 processEntitiesCollision();
    void                 updatePlayer();

    void                 updateGui();
    void                 renderGui(sf::RenderTarget& target);
    const Circle::Type   getRandCircleType() const;
};


#endif // GAME_H
