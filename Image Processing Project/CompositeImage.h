#ifndef CompositeImage_h
#define CompositeImage_h

#include<fstream>

#include "Image.h"

using namespace std;

class CompositeImage : public Image{

  private:
      Image img1,img2;
      float alpha;

  public:

    CompositeImage(Image I1, Image I2, float Alpha);
    ~CompositeImage();
    void createCompositeImage();
};

#endif
