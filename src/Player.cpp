#include "Player.h"
#include "Common.h"
Player::Player() { // init Player
    this->texture.loadFromFile(PLAYER::PLAYER_SHEETS_LINK); // Load player texture
    this->sprite.setPosition(100.f, 100.f);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(this->frames[0]);
}

Player::~Player() {
    // Destructor implementation
}

void Player::draw(RenderWindow& target) {

    if (target.isOpen()) {
        float deltaTime = this->clock.restart().asSeconds();
        this->animationTimer += deltaTime;

        if (this->animationTimer >= this->animationSpeed) {
            this->animationTimer = 0.0f;
            this->currentFrame = (this->currentFrame + 1) % this->frames.size();
            sprite.setTextureRect(this->frames[this->currentFrame]);
        }
        target.draw(sprite);
    }else {
        // Handle the case when the target is not open
        throw std::runtime_error("Render target is not open.");
    }
}