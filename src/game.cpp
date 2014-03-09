#include <iostream>
#include "../include/game.h"
#include "../include/window.h"

Game::Game()
  : mQuit(false)
{
  this->mShip = std::shared_ptr<Ship>(new Ship(100, 100, Window::LoadImage("./images/player.png")));
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
  Window::Clear();

  // SDL_Point pivot = { mShip->mBounds.w / 2, mShip->mBounds.h / 2 };
  Window::Draw(mShip->image, mShip->mBounds, NULL, mShip->mAngle, 0, 0, SDL_FLIP_NONE);

  Window::Present();
}
