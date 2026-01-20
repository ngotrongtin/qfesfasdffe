#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Common.h"
#include "Enemy.h"
using namespace sf;

// Main Game class
class Game
{
private:
    // instances
    RenderWindow window;
    Event event;
    VideoMode videoMode;
    Player player;
    Sprite backgroundSprite;
    Texture backgroundTexture;
    Enemy enemy;
    // variables
    const int DEFAULT_VIDEO_MODE_WIDTH = 800;
    const int DEFAULT_VIDEO_MODE_HEIGHT = 634;

public:
    Game();
    ~Game();
    void initialize();
    bool isRunning() const
    {
        return window.isOpen();
    }
    void draw();
    void update();
    void render();
};