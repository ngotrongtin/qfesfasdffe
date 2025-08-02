#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
private:
    // instances
    Texture texture;
    Sprite sprite;
    // variables
    int frameWidth = 64;
    int frameHeight = 64;
    std::vector<sf::IntRect> frames = {
        {11, 63, 160, 114},
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
        {2507, 63, 165, 117}
    };
    sf::Clock clock;
    int currentFrame = 0;
    float animationTimer = 0.0f;
    float animationSpeed = 0.15f;
public:
    Player();
    ~Player();
    void draw(RenderWindow& target);
};