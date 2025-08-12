#include <SFML/Graphics.hpp>

using namespace sf;

enum class PlayerState {
    Idle,
    Running,
    Jumping,
    Attacking
};

class Player {
private:
    // instances
    Texture texture;
    Sprite sprite;
    // variables
    int frameWidth = 64;
    int frameHeight = 64;
    std::vector<sf::IntRect> idleFrames = {
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

    std::vector<sf::IntRect> runningFrames = {
        {0, 260, 177, 97},
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
        {2112, 264, 177, 101}};
    sf::Clock clock;
    int currentFrame = 0;
    float animationTimer = 0.0f;
    float animationSpeed = 0.15f;
    
public:
    Player();
    ~Player();
    //public variable
    PlayerState currentState;
    void moveLeft();
    void moveRight();
    void update();
    void draw(RenderWindow& target);
};