#pragma once

#include "ofMain.h"

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

		//define functions
		void tile1();
		void tile2();
		void tile3();
		void tile4();

		//cols and rows for main grid
		int cols = 2;
		int rows = 2;
		//default tile size
		int tileWidth = 400;
		int tileHeight = 400;

		//tileNumber as index
		int tileNumber;

		//color array for first tile
		ofColor colors[4];

		//image variable for screenshot
		ofImage img; 
	
		
};
