/*Haley Van Camp
04/27/15
Animation HW*/

#include "ofApp.h"
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    fishLeft = true;
    underwater.loadImage("underwater.jpeg");
    fishy.load("fishy.gif");
    fishyRight.load("fishyRight.gif");
    myBubble.setup(700, 700);
    index = 0;
    
    fishPos = ofVec2f(800,550);
    fishVel = ofVec2f(ofRandom(2, 4), ofRandom(2, 4));

}

//--------------------------------------------------------------
void ofApp::update(){
    
    float screenW = ofGetScreenWidth();
    float screenH = ofGetScreenHeight();
    
    myBubble.update();
// A random number between 0-20 is picked each frame and if it's less than 5 it makes a bubble (a way to reduce the amount of bubbles on screen)
    if(ofRandom(20)<5) {
        bubble tempBubble;
        tempBubble.setup(ofRandom(screenW), 700);
        myBubbles.push_back(tempBubble);
    }
  
   //updating(moving) bubbles
    for(int i=0; i<myBubbles.size(); i++) {
        myBubbles[i].update();
        if(myBubbles[i].myPos.y < 200) { // erasing bubbles when the y value is less  than 200
            myBubbles.erase(myBubbles.begin()+i);
            i--;
        }
    }
    
    //updating bubbles for the fish
    for(int i=0; i<theBubbles.size(); i++) {
        theBubbles[i].update();
        
        if(theBubbles[i].myPos.y < 200) {// erasing bubbles when the y value is less  than 200
            theBubbles.erase(theBubbles.begin()+i);
            i--;
        }
    }
   // when the fish is facing left
    if(fishLeft) {
        if (ofGetElapsedTimeMillis() % 3){
            index++;
            if (index > fishy.pages.size()-1) index = 0;
        }
    }else { // when the fish is facing right
        if (ofGetElapsedTimeMillis() % 3){
            index++;
            if (index > fishyRight.pages.size()-1) index = 0;
        }
    }
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofBackground(10, 200, 200);
    underwater.draw(0,0);
    //when the fish is facing left
    if(fishLeft) {
         fishy.pages[index].draw(fishPos);
    }else { // when the fish is facing right
         fishyRight.pages[index].draw(fishPos);
    }
   // draws the bubbles that are constantly on the screen
    myBubble.draw();
    for(int i=0; i<myBubbles.size(); i++) {
       
        myBubbles[i].draw();
    }
    // draws the bubbles coming from the fish
    for(int i=0; i<theBubbles.size(); i++) {
        theBubbles[i].color = ofColor(235, 235, 255);
        ofFill();
        theBubbles[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_LEFT) { // if left arrow key, fish goes left
        fishLeft = true;
        fishVel = ofVec2f(-6,ofMap(sin(ofGetElapsedTimef()),-1,1,-5,5));
//        fishVel.x = -6;
//        fishVel.y = ofMap(sin(ofGetElapsedTimef()),-1,1,-10,10);
//        fishPos.x += fishVel.x;
        fishPos+=fishVel;
        
    }
    else if(key == OF_KEY_RIGHT) { // if right arrow key, fish goes right and the fish gif switches to the right facing fish
        fishVel = ofVec2f(6,ofMap(sin(ofGetElapsedTimef()),-1,1,-5,5));
        fishLeft = false;
//        fishVel.x = 6;
//        fishPos.x += fishVel.x;
        fishPos+=fishVel;
        
    }
    else if(key == OF_KEY_UP) { // if up key, fish goes up
        
        fishVel.y = -6;
        fishPos.y += fishVel.y;
    }
    else if(key == OF_KEY_DOWN) { // if down key, fish goes down
        
        fishVel.y = 6;
        fishPos.y += fishVel.y;
    }
    else if(key == OF_KEY_RETURN) { // if return key, bubbles from fish appear
        //fish blows bubbles
        //cout << "enter" << endl;
        int bubbleOffset = 0;
        if(!fishLeft) {
            bubbleOffset = 55;
        }
        for(int i=0; i<6; i++) {
            // where the bubbles enter the vector
            bubble tempBubble2;
            tempBubble2.setup(fishPos.x+ofRandom(5)+bubbleOffset, fishPos.y+30); // bubbleOffset so bubbles come out near mouth
            tempBubble2.myVel.y = ofRandom(-2, -5);
            theBubbles.push_back(tempBubble2);
        }
    }
       
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
