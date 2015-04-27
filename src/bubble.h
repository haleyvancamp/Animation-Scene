//
//  bubble.h
//  animationScene2
//
//  Created by Haley Van Camp on 4/26/15.
//
//

#ifndef __animationScene2__bubble__
#define __animationScene2__bubble__

#include <ofMain.h>

class bubble {
public:
    
    bubble();// constructor
    
    void setup(float x, float y);
    void update();
    void draw();
    
    ofVec2f myPos;
    ofVec2f myVel;
    int mySize;
    ofColor color;
    
};

#endif /* defined(__animationScene2__bubble__) */
