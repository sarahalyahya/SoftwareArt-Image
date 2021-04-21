#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//size and initial variables
	ofSetWindowShape(800, 800);
	ofColor primaryYellow(255, 255, 0);
	ofSetBackgroundColor(primaryYellow);
	colorPicker = 0;

	//img
	//png from Maxim Kulikov - uploaded on 'The Noun Project' 
	silhouette.load("silhouette2.png");
	
	//gui
	sliders.setName("Sliders");
	sliders.add(noise.set("noise", 0.001, 0.001, 0.04));
	sliders.add(frequency.set("frequency", 100, 10, 400));

	gui.setup(sliders);


}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	//color palette
	ofColor primaryBlue(0, 0, 255);
	ofColor circlePalette[8];
	circlePalette[0] = ofColor(233, 66, 36);
	circlePalette[1] = ofColor(255, 139, 137);
	circlePalette[2] = ofColor(225, 59, 56);
	circlePalette[3] = ofColor(128, 170, 167);
	circlePalette[4] = ofColor(68,100,173);
	circlePalette[5] = ofColor(171, 196, 171);
	circlePalette[6] = ofColor(59, 53, 97);
	circlePalette[7] = ofColor(0);

	ofSetColor(primaryBlue);

	//movement/flow
	int randX = ofRandom(100); 
	int randY = ofRandom(100);
	

	//grid like approach, going through screen like columns
	for (int x = 0; x < ofGetWidth() * 2; x++) {
		for (int y = 0; y < ofGetHeight() * 2; y++) {

			//generating a (not-so-random) value so that the tiny lines have some relation to each other 
			float val = ofNoise(x * noise + randX, y * noise + randY); // larger decimal value = noisier the shape is
			if (int(val * frequency) % 4 == 0) { //frequency / range (smaller multiplication by n = blobbier shape / less range)
				ofDrawLine(x, y, x + 1, y + 1); //tiny line resembling a point


			}
		}


	}



	silhouette.draw(ofGetWidth() / 2 - silhouette.getWidth() / 2, ofGetHeight() / 2 - silhouette.getHeight() / 2);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	
	for (int i = 0; i < 8; i++) { 
		int colorIndex = i + colorPicker; 
		if (colorIndex >= 7) {
			colorIndex = 0;
		}
		ofSetColor(circlePalette[colorIndex]);
		
		cout << colorIndex << endl; 
		ofRotateDeg(360 / 8);
		ofDrawEllipse(300, 0, 50, 50);


	}
	ofPopMatrix();
	

	
	gui.draw();
	
	
	if (colorPicker < 7) {
		colorPicker += 1;
	}
	else if (colorPicker >= 7) {
		colorPicker = 0;
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
