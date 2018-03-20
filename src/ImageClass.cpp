/*
 * ImageClass.cpp
 *
 *  Created on: Mar 18, 2018
 *      Author: cliff
 */

#include "ImageClass.h"

std::vector<ofImage> images(40);
std::vector<int> signum(10);
std::vector<int> resized(10);

int sizefactor;

void ImageClass::setup()
{
	fondo = ofRandom(0, 5);
	a = ofRandom(5, 40);
	b = ofRandom(5, 40);
	c = ofRandom(5, 40);
	d = ofRandom(5, 40);
	e = ofRandom(5, 40);

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

	for (int i = 0; i < resized.size(); ++i)
	{
		sizefactor = ofRandom(0, 500);
		if ((int)ofRandom(0, 2) == 1)
		{
			resized[i] = 1 * sizefactor;
		}
		else
		{
			resized[i] = -1 * sizefactor;
		}
	}

	for (int i = 1; i < images.size(); ++i)
	{
		images[i].load(ofToString(i) + ".png");
	}
}

void ImageClass::update()
{
	//	ofLog() << "the number is " << width;
	mouseX = ofGetMouseX();
	mouseY = ofGetMouseY();

	mapX = ofMap(mouseX, 0, ofGetWidth(), 0, 100);
	mapY = ofMap(mouseY, 0, ofGetHeight(), 0, 100);
	mapZ = ofMap(mouseX, 0, ofGetWidth(), 0, -100);

	//ofLog() << "n\ X is " << mapX << " Y is " << mapY << " Z is " << mapZ;
}

void ImageClass::draw()
{
	images[fondo].draw(0, 0, ofGetWidth(), ofGetHeight());

	//ESTE SETEO ESTA GENIAL.
	//images[a].draw(mapX, mapY, mapZ, ofGetWidth(), ofGetHeight());
	//images[b].draw(!mapX, mapY, mapZ, ofGetWidth(), ofGetHeight());
	//images[c].draw(mapX, !mapY, mapZ, ofGetWidth(), ofGetHeight());
	//---
	images[a].draw(mapX * signum[0], mapY * signum[1], mapZ * signum[1] + resized[1], ofGetWidth(), ofGetHeight());
	images[b].draw(mapX * signum[2], mapY * signum[3], mapZ * signum[2] + resized[2], ofGetWidth(), ofGetHeight());
	images[c].draw(mapX * signum[4], mapY * signum[5], mapZ * signum[3] + resized[3], ofGetWidth(), ofGetHeight());
	images[d].draw(mapX * signum[6], mapY * signum[7], mapZ * signum[4] + resized[4], ofGetWidth(), ofGetHeight());
	images[e].draw(mapX * signum[8], mapY * signum[9], mapZ * signum[5] + resized[5], ofGetWidth(), ofGetHeight());
}


