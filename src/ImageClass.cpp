/*
 * ImageClass.cpp
 *
 *  Created on: Mar 18, 2018
 *      Author: cliff
 */

#include "ImageClass.h"
void ImageClass::setup(string _name)
{
//	num = (int)ofRandom(0,2) ;
//	ofLog() << "the number is " << ofToString(num);
	image.load(_name) ;
}

void ImageClass::draw()
{
	image.draw(100,100) ;
}

int ImageClass::dimensions(ofImage image)
{
	int dimensions ;
	int width ;
	int height ;

	width = image.getWidth();
	height = image.getHeight();
	dimensions = width+height ;

	if (dimensions > 2000)
	{
		ofLog() << "Image is BIG";
	}
	else
	{
		ofLog() << "Image is SMALL";
	}
	return 1 ;
}

