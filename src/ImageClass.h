/*
 * ImageClass.h
 *
 *  Created on: Mar 18, 2018
 *      Author: cliff
 */

#ifndef SRC_IMAGECLASS_H_
#define SRC_IMAGECLASS_H_

#include "ofMain.h"
#include "ofxGui.h"

class ImageClass{
public:
	void loadCollages();
	void drawCollages(int collage);
	void loadImagesRandom();
	void updateImagesRandom();
	void drawImagesRandom();

	void setup();
	void update(ofVec3f xyz);
	void draw();
	void guiSetup();
	void guiDraw();

	ofImage image ;

	int fondo;

	
	int actualTime = 0;
	int futureTime = 0;
	int interval = 0;
	int whatsdraw = 0;

	int randX = 1;
	int randY = 1;
	int randZ = 1;

	int mouseX;
	int mouseY;

	float mapX = 0;
	float mapY = 0;
	float mapZ = 0;

	//-GUI
	ofxPanel gui;
	ofxIntSlider collageNum;
	ofxFloatSlider minX;
	ofxFloatSlider maxX;
	ofxFloatSlider minY;
	ofxFloatSlider maxY;
	ofxFloatSlider minZ;
	ofxFloatSlider maxZ;
};


#endif /* SRC_IMAGECLASS_H_ */
