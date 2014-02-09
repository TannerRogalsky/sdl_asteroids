#include <iostream>
#include "../include/game.h"

Game::Game()
  : quit(false), counter(0)
{
}

void Game::Update(){
  counter++;
  if (counter % 60 == 0) {
    std::cout << counter / 60 << std::endl;
  }
}

void Game::OnInput(SDL_Event* event) {
  while (SDL_PollEvent(event)){
    if (event->type == SDL_QUIT) {
      this->quit = true;
    }
    if (event->type == SDL_KEYDOWN){
      switch (event->key.keysym.sym){
        case SDLK_ESCAPE:
          this->quit = true;
          break;
        default:
          break;
      }
    }
  }
}

void Game::Render(SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_Rect rect;
  rect.x = 10;
  rect.y = 10;
  rect.w = 100;
  rect.h = 100;

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(renderer, &rect);

  SDL_RenderPresent(renderer);
}
