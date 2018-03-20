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
	void setup(string _name);
	void draw();
	void dimensions(ofImage image);
	ofImage image ;
	int height ;
	int width ;
};


#endif /* SRC_IMAGECLASS_H_ */
