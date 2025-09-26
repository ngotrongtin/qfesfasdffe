#include<algorithm>
#include<SFML/Graphics.hpp>
#include "TutorialConfig.h"
#include "Game.h"
int main() {
    Game game;
    Music music;
    if(!music.openFromFile("../assets/sounds/background.ogg")){
        throw std::runtime_error("Failed to load background music.");
        return -1;
    }
    music.setLoop(true);   // Lặp lại vô hạn
    music.setVolume(50);   // Âm lượng (0-100)
    music.play();          // Bắt đầu phát nhạc
    while (game.isRunning()) {

        game.update();
        game.render();
    }
    return 0;
}

