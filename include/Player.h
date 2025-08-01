#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
private:
    RectangleShape shape;
public:
    Player();
    ~Player();
    Shape& getShape() {
        return this->shape;
    }
};