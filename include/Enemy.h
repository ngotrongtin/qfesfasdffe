#include <SFML/Graphics.hpp>
#include "Player.h"
#include <cmath>

using namespace sf;
enum class EnemyType {
    ZOMBIE,
    ALIEN,
    ROBOT
};

enum class EnemyState {
    IDLE,
    MOVING,
    DEAD
};

class Enemy{
private:
    int health;
    int damage;
    EnemyType type;
    EnemyState state;
    Texture texture;
    Sprite sprite;
    Player& targetPlayer; 
public:
    Enemy(int health, int damage, EnemyType type, EnemyState state, Player& targetPlayer);

    void takeDamage(int amount) {
        this->health -= amount;
        if (this->health < 0) this->health = 0;
    }

    int getHealth() const {
        return this->health;
    }

    int getDamage() const {
        return this->damage;
    }

    EnemyType getType() const {
        return this->type;
    }

    EnemyState getState() const {
        return this->state;
    }

    void draw(RenderWindow &target) {
        target.draw(this->sprite);
    }

    void update() {
        // Simple AI: Move towards the player if not dead
        if (this->state != EnemyState::DEAD) {
            Vector2f playerPos = this->targetPlayer.getPosition();
            Vector2f enemyPos = this->sprite.getPosition();
            Vector2f direction = playerPos - enemyPos;
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
            if (length != 0) {
                direction /= length; // Normalize
                this->sprite.move(direction * 0.5f); // Move speed
            }
        }
    }
};
