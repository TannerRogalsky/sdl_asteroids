#ifndef SHIP_H
#define SHIP_H
#include <SDL2/SDL.h>

class Ship {
public:
  Ship();
  Ship(int, int, SDL_Texture*);
  SDL_Rect bounds;
  SDL_Texture* image;
  int angle;
private:
  void Init(int, int, int, int, SDL_Texture*);
};

#endif
