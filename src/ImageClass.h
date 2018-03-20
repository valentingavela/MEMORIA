/*
 * ImageClass.h
 *
 *  Created on: Mar 18, 2018
 *      Author: cliff
 */

#ifndef SRC_IMAGECLASS_H_
#define SRC_IMAGECLASS_H_

#include "ofMain.h"

class ImageClass{
public:
	void setup();
	void update();
	void draw();
	ofImage image ;

	int fondo;
	int a;
	int b;
	int c;
	int d;
	int e;

	int randX = 1;
	int randY = 1;
	int randZ = 1;

	int mouseX;
	int mouseY;
	int mapX;
	int mapY;

	float mapZ = 0;
};


#endif /* SRC_IMAGECLASS_H_ */
