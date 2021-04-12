#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowShape(600, 600);
	ofBackground(0);
	//defining initial values
	rotation = 0;
	alpha = 255;
	//loop to populate ds with random x,y values to be used for the "stars"
	for (int i = 0; i < 600; i++)
	{
		circleX.push_back(ofRandom(0, ofGetWidth()));
		circleY.push_back(ofRandom(0, ofGetHeight()));
	}
}


//--------------------------------------------------------------
void ofApp::update(){
	//incrementing and setting rules to create the cycle
	rotation += 1;
	alpha = alpha + alphaChange; 

	if (rotation == 360) {
		rotation = 0;
	}
	if (alpha > 255  || alpha < 0 ){
		alphaChange *= -1;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofFill();
	ofRotateYDeg(0);
	//first bit of animation with the alpha
	ofSetColor(255, 254, 201, alpha);
	//randomly placing "stars"
	for (int i = 0; i < 600; i++) {
		ofDrawCircle(circleX.at(i), circleY.at(i), 2);
		i += 1; 
	}
	//sphere
	ofNoFill();
	ofSetColor(100,100,255);
	ofPushStyle();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//using rotation variable to animate sphere
	ofRotateYDeg(rotation);
	ofDrawSphere(0, 0, 100);
	ofPopStyle(); 

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
