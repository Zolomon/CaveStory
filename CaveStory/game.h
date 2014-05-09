#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>

struct SDL_Window;

struct Game {
    Game();
   ~Game();
private:
    void eventLoop();
    void update();
    void draw();

    SDL_Window* window_;
};

#endif // GAME_H_