#include "Player.h"
#include <cassert>


Player::Player()
    : MIN_PLAYER_SIZE(50.f), MAX_PLAYER_SIZE(200.f), MAX_HEALTH(10)
{
    initShape();
    initVariables();
}


void Player::update(const sf::RenderTarget& target)
{
    updateInput();
    checkWindowCollision(target);
}


void Player::render(sf::RenderTarget& target)
{
    target.draw(playerShape);
}


void Player::resize(const float additionalSize)
{
    if (playerShape.getSize().x + additionalSize <= MAX_PLAYER_SIZE &&
        playerShape.getSize().x + additionalSize >= MIN_PLAYER_SIZE)
    {
        playerShape.setSize(
            sf::Vector2f(
                playerShape.getSize().x + additionalSize, playerShape.getSize().y + additionalSize
                )
        );
    }
}


void Player::reduceHealth(const int healthPoints)
{
    assert(healthPoints >= 0);

    health -= healthPoints;
    if (health < 0)
    {
        health = 0;
    }
}


void Player::gainHealth(const int healthPoints)
{
    assert(healthPoints >= 0);

    health += healthPoints;
    if (health > MAX_HEALTH)
    {
        health = MAX_HEALTH;
    }
}


const sf::FloatRect Player::getGlobalBounds() const
{
    return playerShape.getGlobalBounds();
}


const int Player::getHealth() const
{
    return health;
}


const int Player::getMaxHealth() const
{
    return MAX_HEALTH;
}


void Player::initShape()
{
    playerShape.setSize(sf::Vector2f(MIN_PLAYER_SIZE, MIN_PLAYER_SIZE));
    playerShape.setFillColor(sf::Color::Green);
}


void Player::initVariables()
{
    movementSpeed = 6.f;
    health = MAX_HEALTH;
}


void Player::updateInput()
{
    // Moving left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        playerShape.move(-movementSpeed, 0.f);
    }

    // Moving right
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        playerShape.move(movementSpeed, 0.f);
    }

    // Moving up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        playerShape.move(0.f, -movementSpeed);
    }

    // Moving down
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        playerShape.move(0.f, movementSpeed);
    }
}


void Player::checkWindowCollision(const sf::RenderTarget& window)
{
    // Left collision
    if (playerShape.getGlobalBounds().left < 0.f)
    {
        playerShape.setPosition(0.f, playerShape.getGlobalBounds().top);
    }

    // Top collision
    if (playerShape.getGlobalBounds().top < 0.f)
    {
        playerShape.setPosition(playerShape.getGlobalBounds().left, 0.f);
    }

    // Right collision
    if (playerShape.getGlobalBounds().left + playerShape.getGlobalBounds().width > window.getSize().x)
    {
        playerShape.setPosition(window.getSize().x - playerShape.getGlobalBounds().width, playerShape.getGlobalBounds().top);
    }

    // Bottom collision
    if (playerShape.getGlobalBounds().top + playerShape.getGlobalBounds().height > window.getSize().y)
    {
        playerShape.setPosition(playerShape.getGlobalBounds().left, window.getSize().y - playerShape.getGlobalBounds().height);
    }
}