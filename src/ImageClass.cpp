/*
 * ImageClass.cpp
 *
 *  Created on: Mar 18, 2018
 *      Author: cliff
 */

#include "ImageClass.h"

std::vector<ofImage> images(45);
std::vector<int> selrandom(20);
std::vector<int> signum(10);
std::vector<int> resized(10);

int sizefactor;

void ImageClass::setup()
{
	//Elijo Fondo Random
	fondo = ofRandom(0, 5);

	// Genero un selector de fotos random
	for (int i = 0; i < selrandom.size(); ++i)
	{
		selrandom[i] = ofRandom(5, 45);
	}

	//Genero un numero positivo o negativo 
	//para randomizar su comportamiento
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

	//Genero un resize random
	//algunas se van a agrandar y otras a  achicar
	for (int i = 0; i < resized.size(); ++i)
	{
		sizefactor = ofRandom(0, 50);
		if ((int)ofRandom(0, 2) == 1)
		{
			resized[i] = 1 * sizefactor;
		}
		else
		{
			resized[i] = -1 * sizefactor;
		}
	}

	//Finalmente cargo a memoria las imagenes
	for (int i = 1; i < images.size(); ++i)
	{
		images[i].load(ofToString(i) + ".png");
	}

	images[selrandom[0]].rotate90(2);
}

void ImageClass::update()
{
	//	ofLog() << "the number is " << width;
	mouseX = ofGetMouseX();
	mouseY = ofGetMouseY();

	mapX = ofMap(mouseX, 0, ofGetWidth(), 0, 50);
	mapY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
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
	//---+++
	for (int i = 0; i < 8; i++)
	{
//		images[selrandom[i]].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());
//		images[selrandom[i]].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i], ofGetWidth(), ofGetHeight());
		images[selrandom[i]].draw(mapX * signum[i], mapY * signum[i], ofGetWidth(), ofGetHeight()) ;
	}
}


