/*
 * ImageClass.cpp
 *
 *  Created on: Mar 18, 2018
 *      Author: cliff
 */

#include "ImageClass.h"

//Imagenes sueltas
std::vector<ofImage> imgRandom(45);
//Fondos
std::vector<ofImage> backgrounds(5);
//Vectores de Collages
std::vector<ofImage> col1(6);
std::vector<ofImage> col2(8);
std::vector<ofImage> col3(4);
std::vector<ofImage> col4(3);
std::vector<ofImage> col5(4);
std::vector<ofImage> col6(4);
std::vector<ofImage> col7(3);
std::vector<ofImage> col8(3);
std::vector<ofImage> col9(5);
std::vector<ofImage> col10(5);
std::vector<ofImage> col11(6);
std::vector<ofImage> col12(4);
//Parametros
std::vector<int> selrandom(20); //Seleccionador random
std::vector<int> signum(10); //cambia el signo de los numeros
std::vector<int> resized(10); //en que direccion cambia el tamaño

int sizefactor; //Con que exageracion se van a agrandar los numeros


void ImageClass::setup()
{
	//-Gui
	guiSetup();
	loadCollages();
	loadImagesRandom();
	//images[selrandom[0]].rotate90(2);

	//interval = 5;
	futureTime = interval;
}

void ImageClass::update(ofVec3f xyz)
{
	//mapX = ofMap(xyz.x, -1, 1, 0, 50);
	//mapY = ofMap(xyz.y, -1, 1, 0, 50);
	//mapZ = ofMap(xyz.z, 0, 1, 0, -100);

	ofLog() << "XYZ: " << xyz;

	mapX = ofMap(xyz.x, -1, 1, minX, maxX);
	mapY = ofMap(xyz.y, -1, 1, minY, maxY);
	mapZ = ofMap(xyz.z, 0, 1, minZ, maxZ);

	actualTime = ofGetElapsedTimef();

	//Esto tiene que ser llamado 1 vez cada X segundos
	
	if (actualTime == futureTime)
	{
		updateImagesRandom();

		if (whatsdraw == 0)
		{			
			if (collageNum < 12)
			{
				collageNum = collageNum + 1;
			}
			else
			{
				collageNum = 1;
			}
			whatsdraw = 1;
		}
		else
		{
			whatsdraw = 0;
		}
		futureTime = actualTime + interval;
	}

	//ofLog() << "n\ actual is " << actualTime << " future is " << futureTime ;
}

void ImageClass::draw()
{
	ofSetBackgroundColor(1, 1, 1);
	if (whatsdraw == 0)
	{
		drawCollages(collageNum);
	}
	else if (whatsdraw == 1)
	{
		drawImagesRandom();
	}
	guiDraw();
}

void ImageClass::guiSetup()
{
	//-GUI
	gui.setup();
	gui.add(collageNum.setup("CollageNum", 1, 1, 12));
	gui.add(interval.setup("Interval", 8, 8, 300));
	gui.add(minX.setup("minX", 0, 0, 600));
	gui.add(maxX.setup("maxX", 0, 0, 600));
	gui.add(minY.setup("minY", 0, 0, 600));
	gui.add(maxY.setup("maxY", 0, 0, 600));
	gui.add(minZ.setup("minZ", 0, 0, 600));
	gui.add(maxZ.setup("maxZ", 0, 0, 600));
	//-
	if (!ofFile("settings.xml"))
		gui.saveToFile("settings.xml");

	gui.loadFromFile("settings.xml");
}

void ImageClass::guiDraw()
{
	gui.draw();	
}


void ImageClass::loadCollages()
{
	//COLLAGE1
	for (int i = 0; i < col1.size(); ++i)
	{
		col1[i].load("C1_" + ofToString(i + 1) + ".png");
	}
	//COLLAGE2
	for (int i = 0; i < col2.size(); ++i)
	{
		col2[i].load("C2_" + ofToString(i + 1) + ".png");
	}
	//COLLAGE3
	for (int i = 0; i < col3.size(); ++i)
	{
		col3[i].load("C3_" + ofToString(i + 1) + ".png");
	}
	//COLLAGE4
	for (int i = 0; i < col4.size(); ++i)
	{
		col4[i].load("C4_" + ofToString(i + 1) + ".png");
	}
	//COLLAGE5
	for (int i = 0; i < col5.size(); ++i)
	{
		col5[i].load("C5_" + ofToString(i + 1) + ".png");
	}
	//COLLAGE6
	for (int i = 0; i < col6.size(); ++i)
	{
		col6[i].load("C6_" + ofToString(i + 1) + ".png");
	}
	//COLLAGE7
	for (int i = 0; i < col7.size(); ++i)
	{
		col7[i].load("C7_" + ofToString(i + 1) + ".png");
	}
	//COLLAGE8
	for (int i = 0; i < col8.size(); ++i)
	{
		col8[i].load("C8_" + ofToString(i + 1) + ".png");
	}
	//COLLAGE9
	for (int i = 0; i < col9.size(); ++i)
	{
		col9[i].load("C9_" + ofToString(i + 1) + ".png");
	}
	//COLLAGE10
	for (int i = 0; i < col10.size(); ++i)
	{
		col10[i].load("C10_" + ofToString(i + 1) + ".png");
	}
	//COLLAGE11
	for (int i = 0; i < col11.size(); ++i)
	{
		col11[i].load("C11_" + ofToString(i + 1) + ".png");
	}
	//COLLAGE12
	for (int i = 0; i < col12.size(); ++i)
	{
		col12[i].load("C12_" + ofToString(i + 1) + ".png");
	}
}


void ImageClass::drawCollages(int collage)
{
	//COLLAGE1
	if (collage == 1)
	{
		for (int i = 0; i < col1.size(); ++i)
		{
			//col1[i].draw(mapX, mapY, mapZ, ofGetWidth(), ofGetHeight());
			//col1[i].draw(!mapX, mapY, mapZ, ofGetWidth(), ofGetHeight());
			//col1[i].draw(mapX, !mapY, mapZ, ofGetWidth(), ofGetHeight());
			col1[i].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());
			//col1[i].draw(mapX * signum[i], mapY * signum[i], ofGetWidth(), ofGetHeight());
			//col1[i].draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	//COLLAGE2
	else if (collage == 2)
	{
		for (int i = 0; i < col2.size(); ++i)
		{
			col2[i].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());

//			col2[i].draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	//COLLAGE3
	else if (collage == 3)
	{
		for (int i = 0; i < col3.size(); ++i)
		{
			col3[i].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());

			//col3[i].draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	//COLLAGE4
	else if (collage == 4)
	{
		for (int i = 0; i < col4.size(); ++i)
		{
			col4[i].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());

			//col4[i].draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	//COLLAGE5
	else if (collage == 5)
	{
		for (int i = 0; i < col5.size(); ++i)
		{
			col5[i].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());

//			col5[i].draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	//COLLAGE6
	else if (collage == 6)
	{
		for (int i = 0; i < col6.size(); ++i)
		{
			col6[i].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());

			//col6[i].draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	//COLLAGE7
	else if (collage == 7)
	{
		for (int i = 0; i < col7.size(); ++i)
		{
			col7[i].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());

			//col7[i].draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	//COLLAGE8
	else if (collage == 8)
	{
		for (int i = 0; i < col8.size(); ++i)
		{
			col8[i].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());

			//col8[i].draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	//COLLAGE9
	else if (collage == 9)
	{
		for (int i = 0; i < col9.size(); ++i)
		{
			col9[i].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());

			//col9[i].draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	//COLLAGE10
	else if (collage == 10)
	{
		for (int i = 0; i < col10.size(); ++i)
		{
			col10[i].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());

			//col10[i].draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	else if (collage == 11)
	{
		for (int i = 0; i < col11.size(); ++i)
		{
			col11[i].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());

			//col11[i].draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	else if (collage == 12)
	{
		for (int i = 0; i < col12.size(); ++i)
		{
			col12[i].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());

			//col12[i].draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
}

void ImageClass::updateCollages()
{
}

void ImageClass::loadImagesRandom()
{
	//Finalmente cargo a memoria las imagenes
	for (int i = 0; i < imgRandom.size(); ++i)
	{
		imgRandom[i].load("RANDOM/"+ofToString(i+1) + ".png");
	}
}

void ImageClass::updateImagesRandom()
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
}

void ImageClass::drawImagesRandom()
{
	//images[fondo].draw(0, 0, ofGetWidth(), ofGetHeight());

	//ESTE SETEO ESTA GENIAL.
	//images[a].draw(mapX, mapY, mapZ, ofGetWidth(), ofGetHeight());
	//images[b].draw(!mapX, mapY, mapZ, ofGetWidth(), ofGetHeight());
	//images[c].draw(mapX, !mapY, mapZ, ofGetWidth(), ofGetHeight());
	//---+++
	for (int i = 0; i < 3; i++)
	{
	imgRandom[selrandom[i]].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i] + resized[i], ofGetWidth(), ofGetHeight());
	imgRandom[selrandom[i]].draw(mapX * signum[i], mapY * signum[i], mapZ * signum[i], ofGetWidth(), ofGetHeight());
	imgRandom[selrandom[i]].draw(mapX * signum[i], mapY * signum[i], ofGetWidth(), ofGetHeight()) ;
	}
}
