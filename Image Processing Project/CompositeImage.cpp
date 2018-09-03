#include "CompositeImage.h"
#include "Image.h"
#include "Pixel.h"
#include "Color.h"

using namespace std;

CompositeImage::CompositeImage(Image I1, Image I2, float Alpha):img1(I1),img2(I2),alpha(Alpha){

    width = min(I1.getWidth(), I2.getWidth());                     
    height = min(I1.getHeight(), I2.getHeight());
    maxColor = 255;
    createCompositeImage();
}

CompositeImage::~CompositeImage(){

}

void CompositeImage::createCompositeImage(){

  pix = new Pixel*[height];
  for(int i=0;i<height;i++){
      pix[i] = new Pixel[width];
  }
  for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
          Color A = img1.getPix()[i][j].getCol();
          Color B = img2.getPix()[i][j].getCol();
          Color C = A*(1-alpha) + B*alpha;
          pix[i][j].setCol(C);
      }
  }
}
