//
//  Plexi.cpp
//  Jeugdfilmfestival
//
//  Created by The Distillery on 23/02/14.
//
//

#import "ofMain.h"
#include "Plexi.h"



Plexi::Plexi(int x, int y, int size) {
    cout << "plexi.plexi" << endl;
    
    this->x = x;
    this->y = y;
    this->size = size;
    
    init();
}



void Plexi::init() {
    isLit = false;
    isHit = false;
    isMatch = false;
    isDead = false;
}



void Plexi::light(string p, int v, int s) {
    image.loadImage(p);
    value = v;
    
    isLit = true;
    lit_ts = ofGetElapsedTimeMillis() + s;
}



void Plexi::hit() {
    isHit = true;
    hit_ts = ofGetElapsedTimeMillis() + 100;
}


void Plexi::died() {
    image.loadImage("graphics/dead.png");
    isDead = true;
    dead_ts = ofGetElapsedTimeMillis() + 1000;
}



void Plexi::reset() {
    value = 0;
    image.clear();
}



void Plexi::update() {
    
    if (isLit && ofGetElapsedTimeMillis() > lit_ts) {
        isLit = false;
        image.clear();
    }
    
    if (isDead && ofGetElapsedTimeMillis() > dead_ts) {
        isDead = false;
        image.clear();
    }
    
    if (isHit && ofGetElapsedTimeMillis() > hit_ts) isHit = false;
}



void Plexi::draw() {
    
    if (isHit) { // yellow
        ofSetColor(247, 148, 30);
        ofRect(x, y, size, size);
    }
    else if (image.isAllocated()) { // 3-2-1-image
        ofSetColor(255, 255, 255);
        image.draw(x, y, size, size);
    }
    else {
        ofSetColor(75, 12, 98); // blue
        ofRect(x, y, size, size);
    }
}


