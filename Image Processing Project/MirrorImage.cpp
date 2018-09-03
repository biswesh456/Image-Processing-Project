#include "MirrorImage.h"
MirrorImage::MirrorImage(){

}
MirrorImage::~MirrorImage(){

}

void MirrorImage::MirrorX(Image im){

  width = im.getWidth();
  height = im.getHeight();
  maxColor=255;
  pix = new Pixel*[height];
  for(int i=0;i<height;i++){
      pix[i] = new Pixel[width];
  }


  Pixel **p;
  p=im.getPix();
  for (int j = 0; j < im.getHeight()/2; j++) {
    for (int i = 0; i < im.getWidth(); i++) {
      Color c(p[i][j].getCol().getRed(),p[i][j].getCol().getGreen(),p[i][j].getCol().getBlue());
      this->getPix()[i][j].setCol(c);
    }
  }
  int k=0;
  for (int j = im.getHeight()/2; j < im.getHeight(); j++) {
    for (int i = 0; i < im.getWidth(); i++) {
      Color c(p[i][im.getHeight()/2-k].getCol().getRed(),p[i][im.getHeight()/2-k].getCol().getGreen(),p[i][im.getHeight()/2-k].getCol().getBlue());
      this->getPix()[i][j].setCol(c);
    }
    k++;
  }
  //k=0;
}
void MirrorImage::MirrorY(Image im){
  width = im.getWidth();
  height = im.getHeight();
  maxColor=255;
  pix = new Pixel*[height];
  for(int i=0;i<height;i++){
      pix[i] = new Pixel[width];
  }

  Pixel **p;
  p=im.getPix();
  for (int j = 0; j < im.getHeight(); j++) {
    for (int i = 0; i < im.getWidth()/2; i++) {
      Color c(p[i][j].getCol().getRed(),p[i][j].getCol().getGreen(),p[i][j].getCol().getBlue());
      this->getPix()[i][j].setCol(c);
    }
  }
  int k=0;
  for (int j = 0; j < im.getHeight(); j++) {
    for (int i = im.getWidth()/2; i < im.getWidth(); i++) {
      Color c(p[im.getWidth()/2-k][j].getCol().getRed(),p[im.getWidth()/2-k][j].getCol().getGreen(),p[im.getWidth()/2-k][j].getCol().getBlue());
      this->getPix()[i][j].setCol(c);
      k++;
    }
    k=0;
  }
}
