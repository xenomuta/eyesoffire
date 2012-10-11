#include "mimita.h"

void mimita::inicia(ofPoint ipos) {
  opos = ofVec2f(ipos.x, ipos.y);
  pos = ofVec2f(opos);
  pos.x += ofRandom(-15, 15);
  pos.y -= ofRandom(5, 15);
  vida = ofRandom(.05, 1);
}

ofVec3f mimita::actualiza() {
  vida -= ofRandom(.005, .098);
  
  ofVec2f rumbo = ofVec2f(ofRandom(-(7 * vida), (7 * vida)), ofRandom(-.5, -3.3) * GRAVEDAD);

  pos += rumbo;
  pos.interpolate(opos, vida * .25);
  return ofVec3f(pos.x, pos.y, vida);
}