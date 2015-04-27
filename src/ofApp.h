#pragma once

#include "ofMain.h"
#include "bubble.h"
#define number 20
#include "ofxGif.h"

class ofApp : public ofBaseApp{

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
    
    bubble myBubble;
    //bubble myBubbles[number];
    vector<bubble> myBubbles;
    vector<bubble> theBubbles;
    ofImage underwater;
    ofxGIF::fiGifLoader fishy;
    ofxGIF::fiGifLoader fishyRight;
    int index;
    ofVec2f fishPos;
    ofVec2f fishVel;
    bool fishLeft;
		
};
