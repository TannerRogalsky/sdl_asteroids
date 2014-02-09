#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>

class Game {
public:
  Game();
  bool quit;
  void OnInput(SDL_Event* event);
  void Render(SDL_Renderer* renderer);
  void Update();
private:
  int counter;
};

#endif
