#include "testApp.h"

#define COLOR_SHIFT_TIMEOUT 2000
#define BACKGROUND_TIMEOUT 500

void testApp::setup(){
  mimitaImg.loadImage("brush.png");
  mimitaImg.resize(8, 32);

  vidGrabber.setVerbose(true);
  vidGrabber.initGrabber(320,240);

  haarImg.allocate(320, 240, OF_IMAGE_COLOR);
  haarFinder.setup("haarcascade_eye_tree_eyeglasses.xml");
}

void testApp::update(){
	vidGrabber.grabFrame();
	if (vidGrabber.isFrameNew()) {
    haarImg.setFromPixels(vidGrabber.getPixels(), 320, 240, OF_IMAGE_COLOR, true);
    haarImg.mirror(false, true);
    haarFinder.findHaarObjects(haarImg);

  }

  // Inicia mimitas en posicion de los ojos
  for(int i = 0; i < (int)haarFinder.blobs.size(); i++) {
    ofRectangle cur = haarFinder.blobs[i].boundingRect;
    for (int o = 0; o < haarFinder.blobs[i].area / 2; o++) {
      mimita m;
      float y = (haarFinder.blobs[i].centroid.y - ((o / (haarFinder.blobs[i].area / 2)) * ofRandom(-3, -10)));
      m.inicia(ofPoint(haarFinder.blobs[i].centroid.x, y));
      mimitas.push_back(m);
    }
  }
}

void testApp::draw(){
  ofPushMatrix();
  ofScale(3, 3, 1);
  ofEnableAlphaBlending();  
  ofSetHexColor(0xffffff);  
  haarImg.draw(0, 0);

  // mimitas
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  for (int i = 0; i < (int)mimitas.size(); i++) {    
    ofVec3f m = mimitas[i].actualiza();
    if (m.z < 0 || !ofInRange(m.x, -32, 352) || !ofInRange(m.y, -32, 273))
      mimitas.erase(mimitas.begin() + i);
    float hl = (1- m.z) / .35;
    hl = hl > 1 ? 1 : hl;
    if (ofRandomf()<.0001 || m.z < .0015) {
      ofSetColor(ofColor(255, 0, 0, 16).lerp(ofColor(255, 255, 0, 16), ofRandom(0, .45)));
      mimitaImg.draw(m.x - 2, m.y - 10, 2, ofRandom(5,20));
    } else {    
      ofColor mixColor = ofColor(255,255,255,32).lerp(ofColor(255, 255, 0, 32).lerp(ofColor(255, 0, 0, 32), .5 / m.z), hl);
      ofSetColor(mixColor);
      if (hl < 1 && ofRandomf() > .7) mimitaImg.draw(m.x - 16, m.y - 10, 32, 20);
      else mimitaImg.draw(m.x, m.y);
    }
  }
  for(int i = 0; i < (int)haarFinder.blobs.size(); i++) {
    float x = haarFinder.blobs[i].centroid.x, y = haarFinder.blobs[i].centroid.y;
    ofSetColor(255, 0, 0, 128);
    mimitaImg.draw(x - 10, y - 10, 20, 20);
  }
  ofPopMatrix();
}

void testApp::keyPressed(int key){

}

void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
