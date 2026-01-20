#include "Game.h"
Game::Game() : player(), enemy(100, 10, EnemyType::ZOMBIE, EnemyState::IDLE, this->player)
{
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

Game::~Game(){}

void Game::initialize()
{
    
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
    this->enemy.update();
}

void Game::draw()
{
    this->window.draw(this->backgroundSprite); // Draw the background
    this->player.draw(this->window);           // Draw the player
    this->enemy.draw(this->window);            // Draw the enemy
}

void Game::render()
{
    this->window.clear();   // Clear the window
    this->draw();           // Call the draw function
    this->window.display(); // Display the rendered frame
}
