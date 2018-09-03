#include "ScaledImage.h"
ScaledImage::ScaledImage(){

}
ScaledImage::~ScaledImage(){

}

ScaledImage::ScaledImage(Image im){

	width = im.getWidth();
	height = im.getHeight();
	maxColor=255;
	pix = new Pixel*[height];
	for(int i=0;i<height;i++){
			pix[i] = new Pixel[width];
	}

	Pixel **p;
	p=im.getPix();

	for(int i=0;i<this->getHeight();i++){
		for(int j=0;j<this->getWidth();j++){
			Color c(255,255,255);
			this->getPix()[j][i].setCol(c);
		}
	}
	for(int i=0;i<this->getHeight()/2;i++){
		for(int j=0;j<this->getWidth()/2;j++){
			Color c(p[j*2][i*2].getCol().getRed(),p[j*2][i*2].getCol().getGreen(),p[j*2][i*2].getCol().getBlue());
			this->getPix()[j][i].setCol(c);
		}
	}

}
