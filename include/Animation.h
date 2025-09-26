#include <vector>
#include <SFML/Graphics.hpp>

struct AnimationFrame{
    float x;
    float y;
    float width;
    float height;
    // Cho phép tự convert sang sf::IntRect
    operator sf::IntRect() const {
        return sf::IntRect(
            static_cast<int>(x),
            static_cast<int>(y),
            static_cast<int>(width),
            static_cast<int>(height)
        );
    }
};

class Animation{
    private:
        sf::Sprite* sprite;
        float switchTime; // Time to switch between frames
        float totalTime; // Time since the last frame switch
        sf::IntRect currentRect;
    public:
        std::vector<AnimationFrame> frames;
        int currentFrame; 
        Animation();
        Animation(const std::vector<AnimationFrame>& frames, float switchTime,sf::Sprite& sprite);
        void update(float deltaTime, bool facingRight, int flipFixPix = 0); // Update the animation frame based on time and direction
        const sf::IntRect& getCurrentRect() const; // Get the current texture rectangle
};