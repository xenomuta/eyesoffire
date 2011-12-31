#pragma once

#include "ofMain.h"

#define MAX_VIDA 10

/*
Sistema de particulas de chispas de fuego
*/
class chispa {
  public:
  void init(int iX, int iY);
  void update();

  float x, y; // posicion
  float v, s; // vida y velocidad
};
