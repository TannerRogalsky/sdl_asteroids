#include <iostream>
#include <SDL2/SDL.h>
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

  SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == nullptr){
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  Game game;

  int fps = 1000 / 60;
  SDL_Event event;
  while (game.quit == false) {
    game.HandleInput(&event);
    game.Update();
    game.Render(ren);

    Uint32 timeout = SDL_GetTicks() + fps;
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
      // busy work D: D:
    }
  }

  // tear down
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();

  return 0;
}
