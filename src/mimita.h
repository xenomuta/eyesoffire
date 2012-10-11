#include "ofMain.h"

#define GRAVEDAD 5

class mimita {
  public:
    void inicia(ofPoint ipos);
    ofVec3f actualiza();

    float vida;
    ofVec2f pos, opos;
};