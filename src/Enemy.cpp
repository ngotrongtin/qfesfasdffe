#include "Enemy.h"

Enemy::Enemy(int health, int damage, EnemyType type, EnemyState state, Player &targetPlayer)
    : health(health), damage(damage), type(type), state(state), targetPlayer(targetPlayer)
{
    // create a small colored rectangle texture instead of loading image files
    sf::Color fillColor = sf::Color::White;
    switch (type)
    {
    case EnemyType::ZOMBIE:
        fillColor = sf::Color::Green;
        break;
    case EnemyType::ALIEN:
        fillColor = sf::Color(128, 0, 128); // purple
        break;
    case EnemyType::ROBOT:
        fillColor = sf::Color::Blue;
        break;
    }

    const unsigned int W = 48;
    const unsigned int H = 48;
    sf::Image img;
    img.create(W, H, fillColor);
    texture.loadFromImage(img);
    sprite.setTexture(texture);
    sprite.setOrigin(W / 2.f, H / 2.f);
}