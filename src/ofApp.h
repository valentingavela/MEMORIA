#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include "ImageClass.h"
#include "ofxOsc.h"
//#include "ofxGui.h"

#define PORT 12345
#define NUM_MSG_STRINGS 20

//TODO: FALTAN LAS ROTACIONES
//TODO: A CADA UNO LE VOY A SACAR UNA SCREENSHOT
//TODO: GENERAR UN PROGRAMA KINECT OSC QUE TRANSMITA LAS COORDENADAS Y YA ME QUEDE JOYA
//TODO: INTEGRAR EL OSC A ESTE PROGRAMA

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void oscReceiver();

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

		ImageClass imageClass ;
		//kinectOscReceiver kinect ;
		
		//osc
		ofxOscReceiver receiver;

		int current_msg_string;
		string msg_strings[NUM_MSG_STRINGS];
		float timers[NUM_MSG_STRINGS];
		
		ofTrueTypeFont font;
		
		ofVec3f handLeft;
		ofVec3f handRight;
		ofVec3f head;
		uint64_t bodyId;
		int i;
		//--
};
