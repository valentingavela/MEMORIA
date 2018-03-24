#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(45);

	receiver.setup(PORT);
	current_msg_string = 0;

	imageClass.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	uint64_t lastBodyId = bodyId;
	oscReceiver(); //actualiza el valor de body id
	//Con este sistema me aseguro de que la persona
	//que pasa 100 frames frente a la kinect puede interactuar
	if (bodyId == lastBodyId)
	{
		i++;
	}
	else
	{
		i = 0 ;
	}

	if (i > 100)
	{ 
		imageClass.update(head);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	imageClass.draw();

	ofDrawBitmapString("Body Id: " + ofToString(bodyId), 0, 20);
	ofDrawBitmapString("Hand Right x: " + ofToString(handRight.x) + " y: " + ofToString(handRight.y) + " z: " + ofToString(handRight.z), 0, 50);
	ofDrawBitmapString("Hand Left x: " + ofToString(handLeft.x) + " y: " + ofToString(handLeft.y) + " z: " + ofToString(handLeft.z), 0, 100);
	ofDrawBitmapString("Head x: " + ofToString(head.x) + " y: " + ofToString(head.y) + " z: " + ofToString(head.z), 0, 150);

}

void ofApp::oscReceiver()
{
	// hide old messages
	for (int i = 0; i < NUM_MSG_STRINGS; i++) {
		if (timers[i] < ofGetElapsedTimef()) {
			msg_strings[i] = "";
		}
	}

	// check for waiting messages
	while (receiver.hasWaitingMessages()) {
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(m);

		// check for mouse moved message
		if (m.getAddress() == "/kinect/body/id") {
			bodyId = m.getArgAsInt64(0);
		}
		else if (m.getAddress() == "/kinect/hands/right") {
			handRight.x = m.getArgAsFloat(0);
			handRight.y = m.getArgAsFloat(1);
			handRight.z = m.getArgAsFloat(2);
		}
		else if (m.getAddress() == "/kinect/hands/left") {
			handLeft.x = m.getArgAsFloat(0);
			handLeft.y = m.getArgAsFloat(1);
			handLeft.z = m.getArgAsFloat(2);
		}
		else if (m.getAddress() == "/kinect/head") {
			// both the arguments are float's
			head.x = m.getArgAsFloat(0);
			head.y = m.getArgAsFloat(1);
			head.z = m.getArgAsFloat(2);
		}
		else {
			// unrecognized message: display on the bottom of the screen
			string msg_string;
			msg_string = m.getAddress();
			msg_string += ":";
			for (int i = 0; i < m.getNumArgs(); i++) {
				// get the argument type
				msg_string += " ";
				msg_string += m.getArgTypeName(i);
				msg_string += ":";
				// display the argument - make sure we get the right type
				if (m.getArgType(i) == OFXOSC_TYPE_INT32) {
					msg_string += ofToString(m.getArgAsInt32(i));
				}
				else if (m.getArgType(i) == OFXOSC_TYPE_FLOAT) {
					msg_string += ofToString(m.getArgAsFloat(i));
				}
				else if (m.getArgType(i) == OFXOSC_TYPE_STRING) {
					msg_string += m.getArgAsString(i);
				}
				else {
					msg_string += "unknown";
				}
			}
			// add to the list of strings to display
			msg_strings[current_msg_string] = msg_string;
			timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
			current_msg_string = (current_msg_string + 1) % NUM_MSG_STRINGS;
			// clear the next line
			msg_strings[current_msg_string] = "";
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'f':
		ofToggleFullscreen();
		break;
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
