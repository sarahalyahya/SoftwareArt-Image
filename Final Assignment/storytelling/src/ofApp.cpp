#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//bg
	ofSetWindowShape(1000, 800);
	ofBackground(0, 0, 0);
	//sound
	sweetDis.load("SweetDisposition.mp3");
	sweetDis.setVolume(1.0f); 
	sweetDis.setMultiPlay(false);
	sweetDis.setLoop(false);

	//font
	font.load("helvetica-medium-italic.otf", 20);

	//gui for screen 1
	sliders1.setName("how do the memories make you feel?");
	
	sliders1.add(bitter.set("bitter", 0, 0, 100));
	sliders1.add(sweet.set("sweet", 0, 0, 100));
	gui.setup(sliders1);
	gui.setSize(350, 200);

	//gui for screen 2
	sliders2.setName("how do the memories make you feel?");
	sliders2.add(blur.set("everything's blurry", 0, 0, 100)); 
	gui2.setup(sliders2);
	gui2.setSize(350, 200);


	//consistent gui for all screens
	sliders3.setName("");

	sliders3.add(nostalgia.set("nostalgic", 0, 0, 100));
	guiPerm.setup(sliders3); 
	guiPerm.setSize(350, 200);
	guiPerm.setPosition(10, 70); 

	
	
	
	//timer variable for intro animation
	timer = 0;
	//playCounter var to avoid any errors with calling sounds multiple
	playCounter = 0;
	movement = 0;
	speed = 0;

	first.load("1.jpg"); 
	second.load("2.jpg");
	third.load("2.jpg");
	fourth1.load("4.jpg");
	fourth2.load("4.jpg");
	fourth3.load("4.jpg");

	third.setImageType(OF_IMAGE_GRAYSCALE);


	




}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	ofSoundUpdate();
	timer += 1;

	


}

//--------------------------------------------------------------
void ofApp::draw(){
	//intro animation based on timer variable
	string intro = ""; 
	string subtitle = "";
	ofColor subtitleYellow(248, 227, 106);
	ofColor white(255);
	ofSetColor(subtitleYellow);
	
	
	if (timer > 0 && timer < 240) {
		ofBackground(0);
		ofSetColor(subtitleYellow);
		intro = "do you live life with an accompanying soundtrack?";

	}
	else if (timer >= 240 && timer < 300) {
		intro = "";
	}
	else if (timer >= 300 && timer < 480) {
		intro = "i do."; 
	}

	else if (timer >= 480 && timer < 540) {
		intro = ""; 
	}

	else if (timer >= 540 && timer < 900) {
		intro = "songs always remind me of memories I want to remember";
	}
	else if (timer >= 900 && timer < 1080) {
		intro = "...";
	}
	
	else if (timer >= 1080 && timer < 1260) {
		intro = "or forget"; 
	}
	else if (timer >= 1260 && timer < 1680) {
		intro = "some songs resonate more than others. this is one of them."; 
	}

	else if (timer >= 1680 && clicked == false) {
		intro = "click.";
	}



	//user click -> song + image display + gui display
	else if (timer >= 1680 && clicked == true) {
		intro = ""; 
		playCounter += 1; 
		
		
	}


	//avoiding any issues with early clicking
	if (timer < 1680 && clicked == true) {
		clicked = false; 
		
	}

	//avoiding issues with play() called multiple times
	if (playCounter == 1) {
		sweetDis.play();
	}
	
	
	//displaying text
	font.drawString(intro, ofGetWidth() / 2 - font.stringWidth(intro) / 2, ofGetHeight() / 2 - font.stringHeight(intro) / 2);


	
	//first part of the song
	if (sweetDis.getPositionMS()> 0 && sweetDis.getPositionMS() < 37001) {
		
		 
		//setting "nostalgia" to song speed
		sweetDis.setSpeed(ofMap(nostalgia, 10, 100, 1.0, 0.7));

		//white
		ofSetColor(255);
		ofBackground(255);
		
		
		// noisy waves, from assignment 2
		int randX = ofRandom(100);
		int randY = ofRandom(100);
		for (int x = 0; x < ofGetWidth() * 2; x++) {
			for (int y = 0; y < ofGetHeight() * 2; y++) {
				ofSetColor(0);  
				//mapping noise to "bitter"
				float val = ofNoise(x * ofMap(bitter,0,100,0.001,0.04) + randX, y * ofMap(bitter, 0, 100, 0.001, 0.04) + randY);
				if (int(val * 140) % 4 == 0) { 
					if (sweet > 0) {
						//mapping color to "sweet"
						ofSetColor(ofRandom(0, ofMap(sweet, 0, 100, 100, 255)), ofRandom(0, ofMap(sweet, 0, 100, 100, 255)), 200);

					}
					
					ofDrawLine(x, y, x + 1, y + 1); 


				}
			}


		}
		//setting opacity to "bitter" 
		ofSetColor(white,ofMap(bitter,0,100,255,0));
	

		
		first.draw(ofGetWidth()/2-250, ofGetHeight() / 2 - 250);

		//subtitle
		ofSetColor(subtitleYellow);
		subtitle = "is it bitter? sweet? bittersweet?";
		font.drawString(subtitle, ofGetWidth() / 2 - font.stringWidth(subtitle) / 2, (ofGetHeight() / 4) * 3);

		
		gui.draw();
		guiPerm.draw();
		
		 
		
	}

	else if (sweetDis.getPositionMS() >= 37001 && sweetDis.getPositionMS() < 66940) {

		sweetDis.setSpeed(ofMap(nostalgia, 10, 100, 1.0, 0.7));

		//movement variable to create a slight bounce in the image
		movement += 5; 
		ofBackground(255);

		//background of random subsections from image
		for (int i = 0; i <= ofMap(blur,0,100,0,25); i++) {
			
			third.drawSubsection(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofRandom(0, third.getWidth()/2), ofRandom(0, third.getHeight()/2), ofRandom(0, third.getWidth()), ofRandom(0, third.getHeight()));
			//i += 1;
		}
		

		ofSetColor(255); 
		//image bounce
		second.draw(ofGetWidth()/2 -250 + ofMap(sin(movement), -1, 1, ofGetWidth() / 2 - 225 , ofGetWidth() / 2 + 225) / ofMap(blur, 0, 100, 150, 30), ofGetHeight() / 2-250,500,500);
		
		//subtitle
		ofSetColor(subtitleYellow);
		subtitle = "how much of it do you remember?";
		font.drawString(subtitle, ofGetWidth() / 2 - font.stringWidth(subtitle) / 2, (ofGetHeight() / 4) * 3);


		gui.clear();
		gui2.draw();
		guiPerm.draw();
		
			
	}

	else if (sweetDis.getPositionMS() >= 66940 && sweetDis.getPositionMS() < 82000) {
		sweetDis.setSpeed(ofMap(nostalgia, 10, 100, 1.0, 0.7));
		//blank screen + subtitle
		ofSetBackgroundColor(0);
		ofSetColor(subtitleYellow);
		subtitle = "even if you want to keep this moment forever,";
		font.drawString(subtitle, ofGetWidth() / 2 - font.stringWidth(subtitle) / 2, (ofGetHeight() / 4) * 3);
		guiPerm.draw(); 

	}


	else if (sweetDis.getPositionMS() >= 82000){
		sweetDis.setSpeed(ofMap(nostalgia, 10, 100, 1.0, 0.7));
		//glitch   
		//var for descending lines
		speed += 2; 

		//three copies of the same image + color overlay, xoffset, bounce
		ofBackground(0);
		ofSetColor(255, 132, 0); //orange
		fourth1.draw(ofRandom(ofGetWidth() / 2 - 250, ofGetWidth()/2-400), ofGetHeight() / 2 - 250);
		ofSetColor(136, 0, 255); //purple
		fourth2.draw(ofRandom(ofGetWidth() / 2 - 250,ofGetWidth()/2 - 350), ofGetHeight() / 2 - 250);
		ofSetColor(255);
		fourth3.draw(ofRandom(ofGetWidth() / 2 - 250, ofGetWidth() / 2 - 300), ofGetHeight() / 2 - 250);
		ofDrawRectangle(0, ofRandom(ofGetHeight() / 2 - 80, ofGetHeight() / 2 - 100), ofGetWidth(), 50);
		ofSetColor(2, 255, 133,200);
		ofDrawRectangle(0, ofRandom(ofGetHeight() / 2, ofGetHeight() / 2 + 150), ofGetWidth(), ofGetHeight()- 2* ofGetHeight()/3);
		ofSetColor(136, 0, 255,200);
		ofDrawRectangle(0, ofRandom(ofGetHeight() / 2, ofGetHeight() / 2 + 150), ofGetWidth(), 60);
		ofSetColor(255);

		//loop to create descending line 
		for (int x = 0; x <= ofGetHeight() / 2; x += 3) {
			ofSetLineWidth(1.5);
			ofDrawLine(0, x + speed, ofGetWidth(), x + speed);
		}
		if (speed > ofGetHeight()) {
			speed = 0;
		}
		//subtitle
		ofSetColor(subtitleYellow);
		subtitle = "time is fleeting";
		font.drawString(subtitle, ofGetWidth() / 2 - font.stringWidth(subtitle) / 2, (ofGetHeight() / 4) * 3);
		
		gui2.clear();
		guiPerm.draw();

		//resetting after the song is over 
		timer = 0;
		clicked = false; 
	}
	

	



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
	clicked = true; 
	
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
