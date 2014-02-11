#include <iostream>
#include "../include/ship.h"

Ship::Ship() {
  Init(0, 0, 0, 0, NULL);
}

Ship::~Ship(){

}

Ship::Ship(int x, int y, SDL_Texture* image) {
  Init(x, y, 0, 0, image);
}

void Ship::Init(int x, int y, int width, int height, SDL_Texture* image){
  this->image = image;
  mBounds = {x, y, 50, 50};
  mAngle = 0;
}
