#include "Game.h"


Game::Game()
: MAX_CIRCLES(20), TIME_TO_SPAWN_CIRCLE(30),
  window(sf::VideoMode(800, 600), "Circle eater", sf::Style::Close | sf::Style::Titlebar)
{
    window.setFramerateLimit(60);
    initVariables();
}


const bool Game::isRunning() const
{
    return window.isOpen();
}


void Game::pollEvents()
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
            break;
        }
    }
}


void Game::update()
{
    pollEvents();
    player.update(window);
    spawnCircle();
}


void Game::render()
{
    // Clear, draw, display
    window.clear();

    player.render(window);
    for (auto c = circles.begin(); c != circles.end(); ++c)
    {
        c->render(window);
    }

    window.display();
}


void Game::initVariables()
{
    endGame = false;
    circleSpawnTimer = TIME_TO_SPAWN_CIRCLE;
}


void Game::spawnCircle()
{
    if (circleSpawnTimer < TIME_TO_SPAWN_CIRCLE)
    {
        ++circleSpawnTimer;
    }
    else if (circles.size() < MAX_CIRCLES)
    {
        circles.push_back(Circle(window));
    }
}
