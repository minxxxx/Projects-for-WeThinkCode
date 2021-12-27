#include <GL/glew.h>
#include <Game.class.hpp>
#include <iostream>
#include <time.h>

int main(void) {

    srand (time(NULL));

    Game game;
    game.startGame();

    return 0;
}