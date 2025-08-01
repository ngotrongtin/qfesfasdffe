#include "Player.h"
Player::Player() {
    // Constructor implementation
    this->shape.setSize(Vector2f(50.0f, 50.0f)); // Set size of the player shape
    this->shape.setFillColor(Color::Green); // Set color of the player shape
}