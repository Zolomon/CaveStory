#include "game.h"
//#include <SDL.h>

namespace {
    const int kScreenWidth = 640;
    const int kScreenHeight = 480;
    const int kBitsPerPixel = 32;
    const int kFramesPerSec = 60;
}

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window_ = SDL_CreateWindow("Cave Story", 
        100, 100, 
        kScreenWidth, 
        kScreenHeight, 
        SDL_WINDOW_SHOWN);

    eventLoop();
}

Game::~Game() {
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

void Game::update() {
}

void Game::draw() {

}

void Game::eventLoop() {
    SDL_Event event;
    bool running = true;
    while(running) {
        const int start_time_ms = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
            default:
                break;
            }
        }

        update();
        draw();
        const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
        SDL_Delay(1000 /*ms*/ / kFramesPerSec /*fps/* - elapsed_time_ms /*ms*/);
    }
}

