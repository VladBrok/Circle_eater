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
    void                 pollEvents();
    void                 update();
    void                 render();

private:

    sf::RenderWindow     window;
    sf::Event            event;
    bool                 endGame;
    Player               player;
    std::list<Circle>    circles;
    const int            MAX_CIRCLES;
    const int            TIME_TO_SPAWN_CIRCLE;
    int                  circleSpawnTimer;

    void                 initVariables();
    void                 spawnCircle();
};


#endif // GAME_H
