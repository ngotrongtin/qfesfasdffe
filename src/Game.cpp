#include "Game.h"
Game::Game() {
    // Constructor implementation
    this->videoMode = VideoMode(this->DEFAULT_VIDEO_MODE_WIDTH, this->DEFAULT_VIDEO_MODE_HEIGHT); // Set default video mode
    this->window.create(this->videoMode, "SFML Game", sf::Style::Default);
    this->window.setFramerateLimit(GAME::DEFAULT_FRAME_RATE_LIMIT); // Set frame rate limit
    if (!this->backgroundTexture.loadFromFile(GAME::GAME_BACKGROUND_IMAGE_LINK)) {
        throw std::runtime_error("Failed to load background texture.");
    }
    this->backgroundSprite.setTexture(this->backgroundTexture);
    this->backgroundSprite.setTextureRect(IntRect(0, 0, this->videoMode.width, this->videoMode.height)); // Set background sprite size
}

Game::~Game() {
    // Destructor implementation
}

void Game::initialize() {
    this->player = Player(); 
}

void Game::update() {
    this->player.update(); // Update player state
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == Event::Closed) {
            this->window.close(); // Close the window on close event
        }
        if (this->event.type == Event::KeyPressed) {
            if (this->event.key.code == Keyboard::Left) {
                this->player.moveLeft(); // Move player left
                this->player.currentState = PlayerState::Running; // Set player state to running
            } else if (this->event.key.code == Keyboard::Right) {
                this->player.moveRight(); // Move player right
                this->player.currentState = PlayerState::Running; // Set player state to running
            }
        }else{
            this->player.currentState = PlayerState::Idle; // Set player state to idle
        }
        // Handle other events here
    }
}
void Game::draw() {
    this->window.draw(this->backgroundSprite); // Draw the background
    this->player.draw(this->window); // Draw the player
    //this->window.clear(sf::Color(100, 100, 100)); // nền xám để test alpha
}
void Game::render() {
    this->window.clear(); // Clear the window
    this->draw(); // Call the draw function
    this->window.display(); // Display the rendered frame
    // Render code
}
