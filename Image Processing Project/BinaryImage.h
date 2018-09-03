#ifndef BinaryImage_h
#define BinaryImage_h

#include "Image.h"

// a derived class from image which converts image to a binary image on the basis of a threshold
// it is generalised class and ant 2d array(here brightness) can be given to convert into binary image.

 class BinaryImage : public Image{

    private:
      int threshold;
      int **binaryDeterminingArray;             // array which gives us value to decide the state of pixel. In this case its brightness array
    public:
       BinaryImage(Image img, int Threshold, float **binaryDeterminingArray);
       BinaryImage(const BinaryImage &i);
       ~BinaryImage();
       int getThreshold();
 };

#endif
