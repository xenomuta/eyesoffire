#pragma once

#include "ofMain.h"
#include "chispa.h"
#include "ofxOpenCv.h"

#define MAX_CHISPA 10000

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		

    void fireAt(int x, int y, int a);

		ofVideoGrabber 		vidGrabber;
    ofxCvColorImage   colorImg;
    ofImage           haarImg;
    ofTrueTypeFont    font1, font2;

    ofxCvHaarFinder 	haarFinder;
    chispa *fuego;
};

