#include "Animation.h"

Animation::Animation(const std::vector<AnimationFrame>& frames, float switchTime, sf::Sprite& sprite)
    : frames(frames),
      switchTime(switchTime),
      sprite(&sprite)
{
    this->totalTime = 0.f;
    this->currentFrame = 0;
    this->currentRect = this->frames[this->currentFrame];
    if (this->frames.empty())
    {
        throw std::runtime_error("Failed to load animation frames");
    }
}

Animation::Animation(){}

void Animation::update(float deltaTime, bool facingRight, int flipFixPix)
{
    if (this->frames.empty())
         return;

    this->totalTime += deltaTime;

    if (this->totalTime >= this->switchTime)
    {
        this->totalTime -= this->switchTime;
        this->currentFrame = (this->currentFrame + 1) % this->frames.size();
    }

    const AnimationFrame &f = this->frames[this->currentFrame];
    this->currentRect = f;
    //this->sprite.setTextureRect(this->currentRect);
    if (facingRight)
    {
        this->sprite->setScale(-1,1);
    }
    else
    {
        this->sprite->setScale(1,1);
    }
}

const sf::IntRect &Animation::getCurrentRect() const
{
    return this->currentRect;
}