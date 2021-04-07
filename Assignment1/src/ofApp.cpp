#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//window shape - square
	ofSetWindowShape(800, 800);
	
	//still looking for something similar to Processing's noLoop() but this works for now
	ofSetFrameRate(1);

	//color array
	colors[0] = ofColor(16, 149, 150);
	colors[1] = ofColor(221, 140, 40);
	colors[2] = ofColor(235, 194, 47);
	colors[3] = ofColor(36, 54, 111);

	ofSetCircleResolution(100);

	

	
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	tile1();
	tile4();
	tile2();
	tile3();
}
//--------------------------------------------------------------
void ofApp::tile1() {
	//tile 1 - upper left
	tileNumber = 1;
	//setting up  grid variables
	int colSmall = 8;
	int rowSmall = 8;

	//colorpalette for tile - excluding array
	ofColor blueGreen(16, 149, 150);
	ofColor white(255);
	
	//background
	ofSetColor(white);
	ofDrawRectangle(0, 0, tileWidth*tileNumber, tileHeight * tileNumber);

	// tile border
	ofSetColor(blueGreen);
	ofNoFill();
	ofSetLineWidth(15);
	ofDrawRectangle(0, 0, tileWidth * tileNumber, tileHeight * tileNumber);
	
	//setting up grid
	for (int c = 0; c < colSmall; c++) {
		for (int r = 0; r < rowSmall; r++) {

			ofNoFill();

			//ofDrawRectangle(c * 50, r * 50, 50, 50); 


			ofFill();
			//if-statements to alternate grid cells
			if (c % 2 == 0) {
				//diamonds
				ofPushMatrix();
				ofSetColor(colors[(int)ofRandom(0, 4)]);
				ofTranslate(c * 50, r * 50);
				ofRotateZDeg(45);
				ofDrawRectangle(27, -7, 20, 20);
				ofPopMatrix();
			}
			else {
				//circles
				ofPushMatrix();
				ofSetColor(colors[(int)ofRandom(0, 4)]);
				ofTranslate(c * 50, r * 50);
				ofDrawCircle(25, 25, 7.5);
				ofPopMatrix();

			}




		}

	}

}

//--------------------------------------------------------------
void ofApp::tile2() {
	tileNumber = 2; 

	//color for this tile
	ofColor blueGreen(16, 149, 150);
	ofColor orange(221, 140, 40);
	ofColor yellow(235, 194, 47);
	ofColor darkBlue(36, 54, 111);
	ofColor white(255);
	ofColor black(0);

	ofTranslate(tileWidth, 0);
	
	ofFill();
	//background
	ofSetColor(darkBlue);
	ofDrawRectangle(0, 0, tileWidth, tileHeight);


	//diamond
	ofPushMatrix();
	ofTranslate(tileWidth / 2, tileHeight / 4);
	ofRotateZDeg(45);
	ofSetLineWidth(20);
	ofSetColor(white);
	ofDrawRectangle(-65, (-tileHeight / 8)-15 , 280, 280);
	ofSetColor(blueGreen);
	ofDrawRectangle(-55, (-tileHeight / 8)-5, 260, 260);

	ofPopMatrix();






	//ellipses(vertical)
	ofSetColor(yellow);
	ofSetLineWidth(7);

	ofDrawEllipse(tileWidth / 2, tileHeight / 2 - 90, 35, 90);
	ofDrawEllipse(tileWidth / 2, tileHeight / 2 + 90, 35, 90);

	//ellipses(horizontal)
	ofDrawEllipse(tileWidth / 2 - 90, tileHeight / 2, 90, 35);
	ofDrawEllipse(tileWidth / 2 + 90, tileHeight / 2, 90, 35);

	//smallCirlces
	ofFill();
	ofSetColor(orange);
	ofDrawCircle(tileWidth / 3, tileHeight / 3, 13);
	ofDrawCircle((tileWidth / 3) * 2, tileHeight / 3, 13);
	ofDrawCircle((tileWidth / 3), (tileHeight / 3) * 2, 13);
	ofDrawCircle((tileWidth / 3) * 2, (tileHeight / 3) * 2, 13);

	//center cricle
	ofDrawCircle(tileWidth / 2, tileHeight / 2, 35);
	

}
//--------------------------------------------------------------
void ofApp::tile3() {
	tileNumber = 3;
	//colors
	ofColor blueGreen(16, 149, 150);
	ofColor orange(221, 140, 40);
	ofColor yellow(235, 194, 47);
	ofColor darkBlue(36, 54, 111);
	ofColor white(255);
	ofColor black(0);

	//translate to make variables easier, confused about the -400
	ofTranslate(-400,tileHeight);
	
	//border
	ofSetColor(darkBlue);
	ofDrawRectangle(0, 0, tileWidth, tileHeight);

	//background
	ofSetColor(white);
	ofDrawRectangle(35,35, 330, 330);
	//a circle in the center to bring rectangles together
	ofSetColor(orange);
	ofDrawCircle(tileWidth / 2, tileHeight / 2, 50);

	//reference variable in the center
	int triangleCenter = 200;
	//star
	ofDrawTriangle(triangleCenter-50, triangleCenter, triangleCenter, triangleCenter-150, triangleCenter+50, triangleCenter);
	ofDrawTriangle(triangleCenter-50, triangleCenter, triangleCenter, triangleCenter+150, triangleCenter+50, triangleCenter);
	ofDrawTriangle(triangleCenter, triangleCenter-50, triangleCenter+150, triangleCenter, triangleCenter, triangleCenter+50);
	ofDrawTriangle(triangleCenter, triangleCenter-50, triangleCenter-150, triangleCenter, triangleCenter, triangleCenter+50);
	ofDrawTriangle(triangleCenter-30, triangleCenter-50, triangleCenter+80, triangleCenter-80, triangleCenter+45, triangleCenter+35);
	ofDrawTriangle(triangleCenter-30, triangleCenter-50, triangleCenter-80, triangleCenter+80, triangleCenter+45, triangleCenter+35);
	ofDrawTriangle(triangleCenter-40, triangleCenter+50, triangleCenter+30, triangleCenter-40, triangleCenter-80, triangleCenter-80);
	ofDrawTriangle(triangleCenter-40, triangleCenter+50, triangleCenter+30, triangleCenter-40, triangleCenter+80, triangleCenter+80);
	
	//surrounding circles
	ofSetColor(yellow);
	ofDrawCircle(triangleCenter-95, triangleCenter-95, 10);
	ofDrawCircle(triangleCenter+95, triangleCenter+95, 10);
	ofDrawCircle(triangleCenter-95, triangleCenter+95, 10);
	ofDrawCircle(triangleCenter+95, triangleCenter-95, 10);


	
	



}
//--------------------------------------------------------------
void ofApp::tile4() {
	tileNumber = 4;

	//colors
	ofColor blueGreen(16, 149, 150);
	ofColor orange(221, 140, 40);
	ofColor yellow(235, 194, 47);
	ofColor darkBlue(36, 54, 111);
	ofColor white(255);
	ofColor black(0);

	//setting up grid variables
	int colSmall = 8;
	int rowSmall = 8;
	
	//background
	ofSetColor(white);
	ofDrawRectangle(tileWidth, tileHeight, tileWidth, tileHeight);
	
	//display grid
	ofNoFill();
	ofSetColor(black);
	ofSetLineWidth(1);
	for (int c = 0; c < colSmall; c++) {
		for (int r = 0; r < rowSmall; r++) {
			
			
			ofFill();
			//alternate rows and draw triangles
			if (r % 2 == 0) {
				ofSetColor(blueGreen);
				ofDrawTriangle((c * 50) + 400, (r * 50) + 450, (c * 50) + 450, (r * 50) + 400, (c * 50) + 450, (r * 50) + 450);
			
			}
			else {
				ofSetColor(darkBlue);
				ofDrawTriangle((c * 50) + 400, (r * 50) + 400, (c * 50) + 400, (r * 50) + 450, (c * 50) + 450, (r * 50) + 450);
			}

		}
	}
	ofNoFill();
	//border
	ofSetColor(blueGreen);
	ofSetLineWidth(15);
	ofDrawRectangle(tileWidth, tileHeight, tileWidth, tileHeight);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//screenshot
	if (key == 'x') {
		img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		img.save("screenshot3.png");
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
