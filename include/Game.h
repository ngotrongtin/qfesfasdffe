#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;
class Game {
private:
    RenderWindow window;
    Event event;
    VideoMode videoMode;
    Player player;
public:
    Game();
    ~Game();

    void initialize();
    bool isRunning() const {
        return window.isOpen();
    }   
    void draw();
    void update();
    void render();
};