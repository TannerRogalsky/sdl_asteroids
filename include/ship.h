#ifndef SHIP_H
#define SHIP_H
#include <SDL2/SDL.h>

class Ship {
public:
  Ship();
  ~Ship();
  Ship(int, int, SDL_Texture*);
  SDL_Rect mBounds;
  SDL_Texture* image;
  int mAngle;
private:
  void Init(int, int, int, int, SDL_Texture*);
};

#endif
