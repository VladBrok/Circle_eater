#include "Game.h"
#include <ctime>

int main()
{
    srand(time(0));

    Game game;
    while (game.isRunning())
    {
        game.pollEvents();
        game.update();
        game.render();
    }

    return 0;
}
