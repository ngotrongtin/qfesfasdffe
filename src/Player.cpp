#include "Player.h"
#include "Common.h"
#include <iostream>

Player::Player()
{
    this->texture.loadFromFile(PLAYER::PLAYER_SHEETS_LINK); // Load player texture
    this->facingRight = false;                              // Mặc định là quay sang phải
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(147.f, 547.f);
    this->idleAnim = Animation(
        {{11, 63, 160, 114},
         {203, 64, 158, 112},
         {395, 60, 165, 120},
         {587, 60, 164, 120},
         {780, 60, 165, 121},
         {972, 60, 165, 121},
         {1164, 60, 165, 121},
         {1355, 59, 165, 121},
         {1548, 60, 165, 121},
         {1741, 60, 172, 126},
         {1932, 64, 165, 117},
         {2124, 64, 165, 117},
         {2315, 63, 165, 117},
         {2507, 63, 165, 117}},
        0.15f,
        this->sprite);
    this->runAnim = Animation(
        {{0, 260, 177, 97},
         {191, 255, 177, 101},
         {384, 252, 177, 113},
         {576, 256, 177, 109},
         {768, 260, 177, 105},
         {944, 263, 192, 101},
         {1152, 260, 177, 101},
         {1344, 256, 177, 105},
         {1535, 251, 177, 109},
         {1728, 256, 177, 105},
         {1920, 260, 177, 105},
         {2112, 264, 177, 101}},
        0.15f,
        this->sprite);

    this->attackAnim = Animation(
        {{1635, 456, 165, 105},
         {2006, 395, 277, 169},
         {2395, 396, 277, 169},
         {2852, 436, 213, 129},
         {3077, 399, 363, 173},
         {3451, 375, 302, 169},
         {3812, 408, 293, 163},
         {4228, 443, 235, 121},
         {4638, 440, 225, 125},
         {4992, 440, 266, 129}},
        0.15f,
        this->sprite);
    this->sprite.setTextureRect(this->idleAnim.getCurrentRect());
    this->sprite.setOrigin(this->sprite.getLocalBounds().width - 40, this->sprite.getLocalBounds().height / 2);
    this->currentState = PlayerState::Idle;
    this->oldState = PlayerState::Idle;
}

Player::~Player()
{
    // Destructor implementation
}

// handle instant events
void Player::handleEvents(Event &event)
{
    this->oldState = this->currentState;

    if (event.type == Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case Keyboard::H:
            this->currentState = PlayerState::Attacking;
            break;
        case Keyboard::Space:
            this->currentState = PlayerState::Jumping;
            break;
        }
    }
    else if (event.type == Event::KeyReleased)
    {
        this->currentState = PlayerState::Idle;
    }
}

void Player::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->currentState = PlayerState::Running;
        this->moveRight();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->currentState = PlayerState::Running;
        this->moveLeft();
    }
    else
    {
        this->currentState = PlayerState::Idle;
    }
}

void Player::draw(RenderWindow &target)
{
    if (target.isOpen())
    {
        // animation selecting
        float deltaTime = this->clock.restart().asSeconds();
        switch (this->currentState)
        {
        case PlayerState::Idle:
            this->idleAnim.update(deltaTime, this->facingRight); // Update idle animation
            this->sprite.setTextureRect(this->idleAnim.getCurrentRect());
            break;
        case PlayerState::Running:
            this->runAnim.update(deltaTime, this->facingRight); // Update running animation
            this->sprite.setTextureRect(this->runAnim.getCurrentRect());
            break;
        case PlayerState::Jumping:
            // Handle jumping frames
            break;
        case PlayerState::Attacking:
            this->attack(deltaTime); // Update attacking animation
            break;
        }
        target.draw(this->sprite);
    }
    else
    {
        // Handle the case when the target is not open
        throw std::runtime_error("Render target is not open.");
    }
}

void Player::moveLeft()
{
    this->facingRight = false;
    this->sprite.move(-5.f, 0.f);
}

void Player::moveRight()
{
    this->facingRight = true;
    this->sprite.move(5.f, 0.f);
}

void Player::attack(float deltaTime)
{
    if (this->attackAnim.currentFrame < this->attackAnim.frames.size() - 1)
    {
        this->attackAnim.update(deltaTime, this->facingRight);
        this->sprite.setTextureRect(this->attackAnim.getCurrentRect());
    }
    else
    {
        // If attack animation is done -> reset to Idle
        this->attackAnim.currentFrame = 0;
        this->currentState = PlayerState::Idle;
    }
}
