#include "Game.h"
Game::Game()
{
    // Constructor implementation
    this->videoMode = VideoMode(this->DEFAULT_VIDEO_MODE_WIDTH, this->DEFAULT_VIDEO_MODE_HEIGHT); // Set default video mode
    this->window.create(this->videoMode, GAME::WINDOW_TITLE, sf::Style::Default);
    this->window.setFramerateLimit(GAME::DEFAULT_FRAME_RATE_LIMIT); // Set frame rate limit
    if (!this->backgroundTexture.loadFromFile(GAME::GAME_BACKGROUND_IMAGE_LINK))
    {
        throw std::runtime_error("Failed to load background texture.");
    }
    this->backgroundSprite.setTexture(this->backgroundTexture);
    this->backgroundSprite.setTextureRect(IntRect(0, 0, this->videoMode.width, this->videoMode.height)); // Set background sprite size
}

Game::~Game()
{
    // Destructor implementation
}

void Game::initialize()
{
    this->player = Player();
}

void Game::update()
{
    // if there are events, process them
    while (this->window.pollEvent(this->event))
    {
        if (this->event.type == sf::Event::Closed)
        {
            this->window.close();
        }

        this->player.handleEvents(this->event); 
    }
    // if no events, just update the player
    this->player.update();
}

void Game::draw()
{
    this->window.draw(this->backgroundSprite); // Draw the background
    this->player.draw(this->window);           // Draw the player
}

void Game::render()
{
    this->window.clear();   // Clear the window
    this->draw();           // Call the draw function
    this->window.display(); // Display the rendered frame
    // Render code
}
