#ifndef BrightnessTask5_h
#define BrightnessTask5_h

#include <vector>

#include "Pixel.h"
#include "Image.h"
#include "Brightness.h"

using namespace std;

class BrightnessTask5: public Brightness{

  int brightness1[256],T1,T2;
   Image Main_Img;
   Image C;
   Image D;
   vector<int> min;
   int h,w;
 public:
   BrightnessTask5();
   BrightnessTask5(Image i);
   BrightnessTask5(const Brightness &b);
   
   void findLocalMin();
    void printHist();
    void printMin();

    void setThreshold();
    void CreateImage_CD();
    void run();


};




#endif
