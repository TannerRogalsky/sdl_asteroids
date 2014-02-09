#include <iostream>
#include "../include/game.h"

Game::Game(SDL_Renderer* renderer)
  : quit(false), counter(0)
{
  this->renderer = renderer;
  Ship ship (100, 100, this->LoadTexture("./images/player.png"));
  this->ship = ship;
}

void Game::Update(){
  counter++;
  if (counter % 60 == 0) {
    std::cout << counter / 60 << std::endl;
  }
}

void Game::OnInput(SDL_Event* e) {
  SDL_Event event = SDL_Event(*e);
  while (SDL_PollEvent(e)){
    if (event.type == SDL_QUIT) {
      this->quit = true;
    }
    if (event.type == SDL_KEYDOWN){
      switch (event.key.keysym.sym){
        case SDLK_ESCAPE:
          this->quit = true;
          break;
        default:
          break;
      }
    }
  }
}

void Game::Render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  // SDL_RenderFillRect(renderer, &ship.bounds);
  SDL_RenderCopy(renderer, ship.image, NULL, &ship.bounds);

  SDL_RenderPresent(renderer);
}

SDL_Texture* Game::LoadTexture(const std::string &file){
  SDL_Texture *texture = IMG_LoadTexture(this->renderer, file.c_str());
  if (texture == nullptr){
    std::cout << "LoadTexture Error: " << SDL_GetError() << std::endl;
  }
  return texture;
}
