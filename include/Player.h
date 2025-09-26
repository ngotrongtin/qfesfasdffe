#include <SFML/Graphics.hpp>
#include "Animation.h"
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
    bool facingRight;
    // variables
    sf::Clock clock;
    float animationTimer = 0.0f;
    float animationSpeed = 0.15f;
    
public:
    Player();
    ~Player();
    //public variable
    PlayerState currentState;
    PlayerState oldState;
    Animation runAnim;
    Animation idleAnim;
    Animation attackAnim;
    void moveLeft();
    void moveRight();
    void attack();
    void update(Event& event);
    void draw(RenderWindow& target);
};