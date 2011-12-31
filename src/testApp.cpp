#include "testApp.h"

static int turn = 0, lapsus;
static bool ready = false;

void testApp::fireAt(int x, int y, int a) {
  for (int i = 0; i < a / 50; i++) {
    for (int f = 0; f < MAX_CHISPA; f++)
      if (fuego[f].v <= 0) {
        fuego[f].init(x, y);
        break;
      }
  }
}

void testApp::setup(){
  ofBackground(0);
  ofSetFrameRate(24);
  ofSeedRandom();
  ofEnableSmoothing();
  ofTrueTypeFont::setGlobalDpi(72);
  lapsus = time(NULL);
  font1.loadFont("pee-on-your-face.ttf", 26, true, true);
  font2.loadFont("charbb_reg.ttf", 20, true, true);
  vidGrabber.setVerbose(true);
  vidGrabber.initGrabber(320,240);
  haarFinder.setup("haarcascade_eye_tree_eyeglasses.xml");
  haarImg.allocate(320,240,OF_IMAGE_COLOR);
  fuego = new chispa[MAX_CHISPA];
  for (int i = 0; i < MAX_CHISPA; i++) fuego[i].v = 0;
}

void testApp::update(){
  if (!ready) lapsus = time(NULL);
  if (time(NULL) - lapsus > 5 && turn < 2) {
    turn++;
    //if (turn == 2) ofSetBackgroundAuto(false);
    lapsus = time(NULL);
  }
  vidGrabber.grabFrame();
  if (vidGrabber.isFrameNew()) {
    ready = true;
    haarImg.setFromPixels(vidGrabber.getPixels(), 320, 240, OF_IMAGE_COLOR, true);
    haarImg.mirror(false, true);
    haarFinder.findHaarObjects(haarImg);

    for(int i = 0; i < haarFinder.blobs.size(); i++) {
      ofRectangle cur = haarFinder.blobs[i].boundingRect;
      fireAt(cur.x + cur.width / 2, cur.y + cur.height / 2, cur.width * cur.height);
    }

  }
}

void testApp::draw(){
  ofPushMatrix();
  ofTranslate(20, 20, 1);
  ofScale(2, 2, 1);
  ofEnableAlphaBlending();
  ofFill();
  ofSetColor(0xff, 0xff, 0xff, turn > 1 ? 0x7f : 0x2f);
  haarImg.draw(0,0);

  for(int i = 0; i < MAX_CHISPA; i++) fuego[i].update();

/*
  ofSetColor(255, 255, 255, 32);
  for(int i = 0; i < haarFinder.blobs.size(); i++) {
    ofRectangle cur = haarFinder.blobs[i].boundingRect;
    ofEllipse(cur.x + cur.width / 2, cur.y + cur.height / 2, cur.width * 1.3, cur.height );
  }
*/
  if (turn == 0) {
    ofSetHexColor(0x00ff00);
    font1.drawString("XenoMuta", 40, 100);
    ofSetHexColor(0xff0000);
    font2.drawString("\"Eyes of Fire\"", 40, 120);
  }
  if (turn == 1) {
    ofSetHexColor(0x00ff00);
    font2.drawString("http://github.com/xenomuta/ojosdefuego", 20, 210);
  }

  ofDisableAlphaBlending();
 
  ofPopMatrix();
}

void testApp::keyPressed(int key){
}

void testApp::keyReleased(int key){
}

void testApp::mouseMoved(int x, int y ){
}

void testApp::mouseDragged(int x, int y, int button){
}

void testApp::mousePressed(int x, int y, int button){
}

void testApp::mouseReleased(int x, int y, int button){
}

void testApp::windowResized(int w, int h){
}

void testApp::gotMessage(ofMessage msg){
}

void testApp::dragEvent(ofDragInfo dragInfo){ 
}
