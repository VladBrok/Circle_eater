#include "Game.h"
#include <iostream>
#include <sstream>


Game::Game()
    : MAX_CIRCLES(10), TIME_TO_SPAWN_CIRCLE(20),
      window(sf::VideoMode(800, 600), "Circle eater", sf::Style::Close | sf::Style::Titlebar)
{
    window.setFramerateLimit(60);
    initVariables();
    initText();
}


const bool Game::isRunning() const
{
    return window.isOpen();
}


const bool Game::isOver() const
{
    return gameOver;
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

    if (!gameOver)
    {
        updatePlayer();
        updateGui();
        spawnCircle();
        processEntitiesCollision();
    }
}


void Game::render()
{
    // Clear, draw, display
    window.clear();

    player.render(window);
    renderGui(window);
    for (auto c = circles.begin(); c != circles.end(); ++c)
    {
        c->render(window);
    }

    if (gameOver)
    {
        window.draw(gameOverText);
    }

    window.display();
}


void Game::initVariables()
{
    gameOver          = false;
    circleSpawnTimer  = TIME_TO_SPAWN_CIRCLE;
    points            = 0;
}


void Game::initText()
{
    std::string path = "Fonts\\PixellettersFull.ttf";
    if (!font.loadFromFile(path))
    {
        std::cout << " ! ERROR in Game::initText: could not load " + path;
    }
    guiText.setFont(font);
    guiText.setCharacterSize(28);
    guiText.setPosition(10.f, 10.f);

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(60);
    gameOverText.setString("GAME OVER");
    gameOverText.setPosition(
        (window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2),
        (window.getSize().y / 2 - gameOverText.getGlobalBounds().height)
    );
    gameOverText.setColor(sf::Color::Red);
}


void Game::spawnCircle()
{
    if (circleSpawnTimer < TIME_TO_SPAWN_CIRCLE)
    {
        ++circleSpawnTimer;
    }
    else if (circles.size() < MAX_CIRCLES)
    {
        circles.push_back(Circle( window, getRandCircleType() ));
        circleSpawnTimer = 0;
    }
}


void Game::processEntitiesCollision()
{
    auto circle = circles.begin();
    while (circle != circles.end())
    {
        if (player.getGlobalBounds().intersects(circle->getGlobalBounds()))
        {
            if (points % 20 == 0)
            {
                player.resize(3.f);
            }

            switch (circle->getType())
            {
            case Circle::DEFAULT:
                ++points;
                break;
            case Circle::DAMAGING:
                player.reduceHealth(1);
                break;
            case Circle::HEALING:
                player.gainHealth(1);
                break;
            default:
                std::cout << " ! ERROR in Game::processEntitiesCollision: invalid circle type.\n";
            }

            circle = circles.erase(circle);
        }
        else
        {
            ++circle;
        }
    }
    
}


void Game::updatePlayer()
{
    player.update(window);

    if (player.getHealth() == 0)
    {
        gameOver = true;
    }
}


void Game::updateGui()
{
    std::stringstream msg;
    msg << " - Points: " << points << '\n' <<
           " - Health: " << player.getHealth() << " / " << player.getMaxHealth();
    guiText.setString(msg.str());
}


void Game::renderGui(sf::RenderTarget& target)
{
    target.draw(guiText);
}


const Circle::Type Game::getRandCircleType() const
{
    Circle::Type type = Circle::DEFAULT;
    int number = rand() % 100 + 1;

    if (number <= 80 && number >= 70)
    {
        type = Circle::HEALING;
    }
    else if (number <= 100 && number > 80)
    {
        type = Circle::DAMAGING;
    }

    return type;
}