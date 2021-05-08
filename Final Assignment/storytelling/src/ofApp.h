#pragma once

#include "ofMain.h"
#include "ofxGui.h" 

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxPanel gui;
		ofParameterGroup sliders1;
		ofParameter<int> bitter; 
		ofParameter<int> sweet;


		ofxPanel gui2; 
		ofParameterGroup sliders2;
		ofParameter<int> blur; 
		
		
		ofParameterGroup sliders3; 
		ofxPanel guiPerm;
		ofParameter<float> nostalgia;



		ofSoundPlayer sweetDis;
		ofTrueTypeFont font; 

		int timer; 
		bool clicked;  
		int playCounter;
		int movement; 
		int speed; 

		ofImage first; 
		ofImage second;
		ofImage third; 
		ofImage fourth1;
		ofImage fourth2;
		ofImage fourth3; 


		
};
