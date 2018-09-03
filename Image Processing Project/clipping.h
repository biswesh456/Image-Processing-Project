#include "math.h"
#include <algorithm>
#include "Image.h"
#include "Pixel.h"
#include "Color.h"
#ifndef clipping_H_
#define clipping_H_
class clipping :public Image
{
    private :
    int w,h;
public:
    clipping(Image *i,int w,int h);
    Image* Clipping(Image *i);
    Image* generate_image1();
    void generate_image(int n,int m,Image *ii);
    bool check(float r,int i,int j,int xc,int yc);
};
#endif
