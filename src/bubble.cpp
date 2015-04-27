//
//  bubble.cpp
//  animationScene2
//
//  Created by Haley Van Camp on 4/26/15.
//
//

#include "bubble.h"

bubble:: bubble() {
    float screenWidth = ofGetScreenWidth();
    myPos = ofVec2f(ofRandom(screenWidth), ofRandom(700));
    myVel = ofVec2f(ofRandom(6), ofRandom(-2, -4));
    mySize = ofRandom(5, 10);
    color = ofColor(255);
}

//--------------------------------------------------------

void bubble::setup(float x, float y) {
    myPos = ofVec2f(x, y);
}

//-------------------------------------------------------

void bubble::update() {
//    float currentValue = myVel.y;
//    float targetValue = ofGetScreenHeight();
//    currentValue = currentValue + ( targetValue - currentValue ) * 0.5;
    myPos.y += myVel.y; // moves the bubble
    
}

//--------------------------------------------------------

void bubble::draw() {
    ofNoFill();
    ofCircle(myPos, mySize);
    
}

