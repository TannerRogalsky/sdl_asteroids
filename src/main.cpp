#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/window.h"
#include "../include/game.h"

int main(int argc, char** argv){
  //Start our window
  try {
      Window::Init("Asteroids");
  }
  catch (const std::runtime_error &e){
      std::cout << e.what() << std::endl;
      Window::Quit();
      return -1;
  }

  Game game;

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
  Window::Quit();

  return 0;
}
