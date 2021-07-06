#include "Player.h"


Player::Player()
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


void Player::initShape()
{
    playerShape.setSize(sf::Vector2f(50.f, 50.f));
    playerShape.setFillColor(sf::Color::Green);
}


void Player::initVariables()
{
    movementSpeed = 10.f;
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