#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
class Game {
private:
    RenderWindow window;
    Event event;
    VideoMode videoMode;
public:
    Game();
    ~Game();

    void initialize();
    bool isRunning() const {
        return window.isOpen();
    }   
    void update();
    void render();
};