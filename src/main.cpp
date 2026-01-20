#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Game.h"
int main()
{
    Game game;
    game.initialize();
    Music music;
    if (!music.openFromFile("../assets/sounds/background.ogg"))
    {
        throw std::runtime_error("Failed to load background music.");
        return -1;
    }
    music.setLoop(true); 
    music.setVolume(50); 
    music.play();        
    while (game.isRunning())
    {
        game.update();
        game.render();
    }
    return 0;
}
