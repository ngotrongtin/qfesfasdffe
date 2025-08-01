#include "Game.h"
Game::Game() {
    // Constructor implementation
    this->videoMode = VideoMode(800, 600); // Set default video mode
    this->window.create(this->videoMode, "SFML Game", sf::Style::Default);
    this->window.setFramerateLimit(60); // Set frame rate limit
}

Game::~Game() {
    // Destructor implementation
}

void Game::initialize() {
    this->player = Player(); 
}

void Game::update() {
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == Event::Closed) {
            this->window.close(); // Close the window on close event
        }
        // Handle other events here
    }
}
void Game::draw() {
    this->window.draw(this->player.getShape());
}
void Game::render() {
    this->window.clear(); // Clear the window
    this->draw(); // Call the draw function
    this->window.display(); // Display the rendered frame
    // Render code
}
