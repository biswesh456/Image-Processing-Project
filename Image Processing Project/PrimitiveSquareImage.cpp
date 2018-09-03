#include "PrimitiveSquareImage.h"

PrimitiveSquareImage::PrimitiveSquareImage(){

}
PrimitiveSquareImage::~PrimitiveSquareImage(){

}
PrimitiveSquareImage::PrimitiveSquareImage(Image im){

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
  for(int i=this->getHeight()/4;i<(3*this->getHeight())/4;i++){
    for(int j=this->getWidth()/4;j<(3*this->getWidth())/4;j++){
      Color c(p[j][i].getCol().getRed(),p[j][i].getCol().getGreen(),p[j][i].getCol().getBlue());
      this->getPix()[j][i].setCol(c);
    }
  }
}
