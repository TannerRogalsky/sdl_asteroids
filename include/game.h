#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include "ship.h"

class Game {
public:
  Game();
  ~Game();
  void OnInput(SDL_Event* event);
  void Render();
  void Update();
  bool mQuit;
  SDL_Texture* LoadTexture(const std::string &file);
  std::shared_ptr<Ship> mShip;
private:
};

#endif
