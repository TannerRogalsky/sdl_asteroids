#include <iostream>
#include "../include/game.h"

Game::Game(SDL_Renderer* r)
  : mQuit(false), renderer(r)
{
  this->mShip = std::shared_ptr<Ship>(new Ship(100, 100, this->LoadTexture("./images/player.png")));
}

Game::~Game(){
  // delete ship;
}

void Game::Update(){
}

void Game::OnInput(SDL_Event* event) {
  if (event->type == SDL_QUIT) {
    mQuit = true;
  }
  if (event->type == SDL_KEYDOWN){
    switch (event->key.keysym.sym){
      case SDLK_ESCAPE:
        mQuit = true;
        break;
      case SDLK_LEFT:
        mShip->mAngle -= 4;
        break;
      case SDLK_RIGHT:
        mShip->mAngle += 4;
        break;
      case SDLK_UP:
        break;
      case SDLK_DOWN:
        break;
      default:
        break;
    }
  }
}

void Game::Render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_Point pivot = { mShip->mBounds.w / 2, mShip->mBounds.h / 2 };
  SDL_RenderCopyEx(renderer, mShip->image, NULL, &mShip->mBounds, mShip->mAngle, &pivot, SDL_FLIP_NONE);

  SDL_RenderPresent(renderer);
}

SDL_Texture* Game::LoadTexture(const std::string &file){
  SDL_Texture *texture = IMG_LoadTexture(this->renderer, file.c_str());
  if (texture == nullptr){
    std::cout << "LoadTexture Error: " << SDL_GetError() << std::endl;
  }
  return texture;
}
