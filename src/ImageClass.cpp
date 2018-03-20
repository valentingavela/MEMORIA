/*
 * ImageClass.cpp
 *
 *  Created on: Mar 18, 2018
 *      Author: cliff
 */

#include "ImageClass.h"
void ImageClass::load(string _name)
{
//	num = (int)ofRandom(0,2) ;
//	ofLog() << "the number is " << ofToString(num);
	image.load(_name) ;
}

void ImageClass::draw()
{
	image.draw(100,100) ;
}


