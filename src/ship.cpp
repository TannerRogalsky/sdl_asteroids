#include <iostream>
#include "../include/ship.h"

Ship::Ship() {
  Init(0, 0, 0, 0, NULL);
}

Ship::Ship(int x, int y, SDL_Texture* image) {
  Init(x, y, 0, 0, image);
}

void Ship::Init(int x, int y, int width, int height, SDL_Texture* image){
  this->image = image;
  bounds.x = x;
  bounds.y = y;
  bounds.w = 50;
  bounds.h = 50;
  angle = 0;
}
