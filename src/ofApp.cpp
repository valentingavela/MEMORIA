#include "ofApp.h"

std::vector<ofImage> images(40);
std::vector<int> signum(10);

int fondo ;
int a ;
int b ;
int c ;
int d ;
int e ;

int randX = 1 ;
int randY = 1 ;
int randZ = 1 ;

int mouseX ;
int mouseY ;
int mapX ;
int mapY ;

float mapZ = 0 ;


//--------------------------------------------------------------
void ofApp::setup(){
	fondo =  ofRandom(0, 6) ;
	a = ofRandom(5, 40) ;
	b = ofRandom(5, 40) ;
	c = ofRandom(5, 40) ;
	d = ofRandom(5, 40) ;
	e = ofRandom(5, 40) ;

	for (int i = 0; i < signum.size(); ++i)
	{
		if ((int)ofRandom(0, 2) == 1)
		{
			signum[i] = 1;
		}
		else
		{
			signum[i] = -1;
		}
	}



	for (int i = 1; i < images.size(); ++i)
	{
		images[i].load(ofToString(i) + ".png");
	}
}

//--------------------------------------------------------------
void ofApp::update(){
//	ofLog() << "the number is " << width;
	mouseX = ofGetMouseX();
	mouseY = ofGetMouseY();

	mapX = ofMap(mouseX, 0, ofGetWidth(), 0, 100);
	mapY = ofMap(mouseY, 0, ofGetHeight(), 0, 100);
	mapZ = ofMap(mouseX, 0, ofGetWidth(), 0, -100);

	//ofLog() << "n\ X is " << mapX << " Y is " << mapY << " Z is " << mapZ;
}

//--------------------------------------------------------------
void ofApp::draw(){
	images[fondo].draw(0, 0, ofGetWidth(), ofGetHeight()) ;
	//ESTE SETEO ESTA GENIAL.
	//images[a].draw(mapX, mapY, mapZ, ofGetWidth(), ofGetHeight());
	//images[b].draw(!mapX, mapY, mapZ, ofGetWidth(), ofGetHeight());
	//images[c].draw(mapX, !mapY, mapZ, ofGetWidth(), ofGetHeight());
	//---
	images[a].draw(mapX * signum[0], mapY * signum[1], mapZ *signum[2], ofGetWidth(), ofGetHeight());
	images[b].draw(mapX * signum[3], mapY * signum[4], mapZ *signum[5], ofGetWidth(), ofGetHeight());
	images[c].draw(mapX * signum[6], mapY * signum[7], mapZ *signum[8], ofGetWidth(), ofGetHeight());
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
