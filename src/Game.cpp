#include "Game.h"
Game::Game() {
    // Constructor implementation
    this->videoMode = VideoMode(this->DEFAULT_VIDEO_MODE_WIDTH, this->DEFAULT_VIDEO_MODE_HEIGHT); // Set default video mode
    this->window.create(this->videoMode, "SFML Game", sf::Style::Default);
    this->window.setFramerateLimit(GAME::DEFAULT_FRAME_RATE_LIMIT); // Set frame rate limit
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
    this->player.draw(this->window); // Draw the player
    //this->window.clear(sf::Color(100, 100, 100)); // nền xám để test alpha
}
void Game::render() {
    this->window.clear(); // Clear the window
    this->draw(); // Call the draw function
    this->window.display(); // Display the rendered frame
    // Render code
}
