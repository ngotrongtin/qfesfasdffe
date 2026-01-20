#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <SFML/Graphics.hpp>

// Structure to hold individual animation frame data
struct AnimationFrame
{
    float x;
    float y;
    float width;
    float height;
    operator sf::IntRect() const
    {
        return sf::IntRect(
            static_cast<int>(x),
            static_cast<int>(y),
            static_cast<int>(width),
            static_cast<int>(height));
    }
};

// Animation class to manage a sequence of frames
class Animation
{
private:
    sf::Sprite *sprite;
    float switchTime; // Time to switch between frames
    float totalTime;  // Time since the last frame switch
    sf::IntRect currentRect;

public:
    std::vector<AnimationFrame> frames;
    int currentFrame;
    Animation();
    Animation(const std::vector<AnimationFrame> &frames, float switchTime, sf::Sprite &sprite);
    void update(float deltaTime, bool facingRight = true); // Update the animation frame based on time and direction
    const sf::IntRect &getCurrentRect() const;      // Get the current texture rectangle
};

#endif // ANIMATION_H