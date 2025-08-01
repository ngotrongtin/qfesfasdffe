#include <SFML/Graphics.hpp>
using namespace sf;

class Player {
private:
    RectangleShape shape;
public:
    Player();
    ~Player();

    void update();
    void render(RenderWindow &window);
};