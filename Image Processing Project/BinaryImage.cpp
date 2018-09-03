#include "BinaryImage.h"

using namespace std;

BinaryImage::BinaryImage(Image img, int Threshold, float **binaryDeterminingArray):threshold(Threshold){

    width = img.getWidth();
    height = img.getHeight();
    maxColor = 255;
    pix = new Pixel*[height];
    for(int i=0;i<height;i++){
        pix[i] = new Pixel[width];
    }

    for(int i=0;i<height;i++){
      for(int j=0;j<width;j++){

          if(binaryDeterminingArray[i][j]<threshold){
            Color c(0,0,0);
            pix[i][j].setCol(c);

          }
          else{
            Color c(255,255,255);
            pix[i][j].setCol(c);
          }
      }
    }

}

int BinaryImage::getThreshold(){
    return threshold;
}

BinaryImage::BinaryImage(const BinaryImage &img):threshold(img.threshold){

   width = img.width;
   height = img.height;
   maxColor = img.maxColor;
   pix = new Pixel*[height];
   for(int i=0;i<height;i++){
       pix[i] = new Pixel[width];
   }
}

BinaryImage::~BinaryImage(){
}
