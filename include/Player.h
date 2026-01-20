#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
using namespace sf;

// Enumeration for player states
enum class PlayerState
{
    Idle,
    Running,
    Jumping,
    Attacking
};

// Player class to manage player properties and behaviors
class Player
{
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
    // public variable
    PlayerState currentState;
    PlayerState oldState;
    Animation runAnim;
    Animation idleAnim;
    Animation attackAnim;
    bool isRunning;

    // movement functions
    void moveLeft();
    void moveRight();
    void attack(float deltaTime);
    void handleEvents(Event &event);
    void stateReset();

    // main functions
    void update();
    void draw(RenderWindow &target);
    sf::Vector2f getPosition() const;
};

#endif // PLAYER_H