#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/game.h"

int main(int argc, char** argv){
  // setup
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  if (win == nullptr){
    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr){
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  Game game (renderer);

  int fps = 1000 / 60;
  SDL_Event event;
  while (game.mQuit == false) {
    while (SDL_PollEvent(&event)){
      game.OnInput(&event);
    }
    game.Update();
    game.Render();

    Uint32 timeout = SDL_GetTicks() + fps;
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
      // busy work D: D:
    }
  }

  // tear down
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  SDL_Quit();

  return 0;
}
