#include "chispa.h"

void chispa::init(int iX, int iY) {
  x = iX + ofRandom(-10, 10);
  y = iY + ofRandom(0, 5);
  for (s = 0; s == 0; s = 10 * ofRandomf());
  v = MAX_VIDA;
}

void chispa::update() {
  if (v <= 0) return;

  x += ofRandom(-2, 2);
  y -= fabs(s / ofRandom(2,4));
  v -= (float)ofRandom(5, 40) / 100;

  if (v > 0) {
    int al = 0x4f;
    ofColor amarillo = ofColor(255, 255, 0, al);
    ofColor rojo = ofColor(255, 0, 0, al);
    ofSetLineWidth(1);
    ofFill();
    //ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    if (v / MAX_VIDA > .90) {
      ofSetColor(amarillo.lerp(ofColor(255, 255, 255, al / 2), v / MAX_VIDA));
      //ofEllipse(x, y, 10, 5);
      ofEllipse(x, y, 2, 4);
    }
    ofSetColor(rojo.lerp(amarillo, (v / MAX_VIDA)));
    //ofCircle(x, y, 4 * (1 - (v / MAX_VIDA)));
    ofEllipse(x, y, 4 * (v / MAX_VIDA), 8 * (v / MAX_VIDA));
    //ofEllipse(x, y, 2, 4);
    ofDisableBlendMode();
  }
}
