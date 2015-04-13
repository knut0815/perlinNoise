#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    noiseTexture.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //Update the Perlin noise
    float time = ofGetElapsedTimef();
    
    float scaleX = 0.007;		//1.0 / scaleX is coherence in x
    float scaleY = 0.008;		//1.0 / scaleY is coherence in y
    float posX0 = 593.2;
    float posY0 = 43.7;
    for (int y = 0; y < noiseTexture.getHeight(); y++) {
        for(int x = 0; x < noiseTexture.getWidth(); x++) {
            
            float value = ofNoise(x * scaleX + posX0, y * scaleY + posY0, time * 0.3 + 445.6 );
            noiseTexture.getPixelsRef()[x + y * noiseTexture.getWidth()] = value * 255;
            
        }
    }
    
    //This causes issues
    noiseTexture.reloadTexture();
    
    //This works as expected
    //noiseTexture.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    noiseTexture.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
