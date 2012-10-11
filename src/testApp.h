#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "./mimita.h"

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

		// mimitas ( particle system )
		vector<mimita>			mimitas;
		// particle sprite
		ofImage							mimitaImg;

		// Haar features finder
    ofxCvHaarFinder			haarFinder;
		// Frame Image
		ofImage							haarImg;
    // Camera
		ofVideoGrabber 			vidGrabber;

};

