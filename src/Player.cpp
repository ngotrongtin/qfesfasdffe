#include "Player.h"
#include "Common.h"

Player::Player() { // init Player
    this->texture.loadFromFile(PLAYER::PLAYER_SHEETS_LINK); // Load player texture
    this->sprite.setPosition(147.f, 476.f);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(this->idleFrames[0]);
    this->currentState = PlayerState::Idle; 
}

Player::~Player() {
    // Destructor implementation
}

void Player::update() {
}

void Player::draw(RenderWindow& target) {

    if (target.isOpen()) {
        float deltaTime = this->clock.restart().asSeconds();
        this->animationTimer += deltaTime;

        if (this->animationTimer >= this->animationSpeed) {
            this->animationTimer = 0.0f;
            switch(this->currentState) {
                case PlayerState::Idle:
                    this->currentFrame = (this->currentFrame + 1) % this->idleFrames.size();
                    this->sprite.setTextureRect(this->idleFrames[this->currentFrame]);
                    break;
                case PlayerState::Running:
                    this->currentFrame = (this->currentFrame + 1) % this->runningFrames.size();
                    this->sprite.setTextureRect(this->runningFrames[this->currentFrame]);
                    break;
                case PlayerState::Jumping:
                    // Handle jumping frames
                    break;
                case PlayerState::Attacking:
                    // Handle attacking frames
                    break;
            }
        }
        target.draw(sprite);
    }else {
        // Handle the case when the target is not open
        throw std::runtime_error("Render target is not open.");
    }
}

void Player::moveLeft() {
    this->sprite.setOrigin(0.f, 0.f);
    this->sprite.setScale(1.f, 1.f);  // Reset flip
    this->sprite.move(-3.f, 0.f);
}

void Player::moveRight() {
    this->sprite.setScale(-1.f, 1.f);  // Flip horizontally
    this->sprite.setOrigin(this->sprite.getLocalBounds().width + 89, 0.f);
    this->sprite.move(3.f, 0.f);
}