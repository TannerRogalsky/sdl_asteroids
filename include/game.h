#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ship.h"

class Game {
public:
  Game(SDL_Renderer* renderer);
  ~Game();
  void OnInput(SDL_Event* event);
  void Render();
  void Update();
  bool mQuit;
  SDL_Texture* LoadTexture(const std::string &file);
  SDL_Renderer* renderer;
  Ship* ship;
private:
  int mCounter;
};

#endif
