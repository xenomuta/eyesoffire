#include "chispa.h"

void chispa::init(int iX, int iY) {
  x = iX + ofRandom(-5, 5);
  y = iY + ofRandom(0, 5);
  for (s = 0; s == 0; s = 5 * ofRandomf());
  v = MAX_VIDA;
}

void chispa::update() {
  if (v <= 0) return;
  x += ofRandom(-2, 2) / 2;
  y -= fabs(s / ofRandom(4,5));
  v -= (float)ofRandom(5, 40) / 100;

  /*
  int aa = a + ofRandom(-5, 5);
  if (aa < 85) aa = 85;
  if (aa > 95) aa = 95;

  x += sin(ofDegToRad(aa)) * s;
  y += cos(ofDegToRad(aa)) * s;
  */

  if (v > 0) {
    int al = 0x1f;
    ofColor amarillo = ofColor(255, 255, 0, al);
    ofColor rojo = ofColor(255, 0, 0, al);
    ofSetLineWidth(1);
    ofFill();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    if (v / MAX_VIDA > .85) {
      ofSetColor(amarillo.lerp(ofColor(255, 255, 255, al / 2), v / MAX_VIDA));
      ofEllipse(x, y, 10, 5);
    }
    ofSetColor(rojo.lerp(amarillo, (v / MAX_VIDA)));
    ofCircle(x, y, 4 * (1 - (v / MAX_VIDA)));
    ofDisableBlendMode();
  }
}
