#include "math.h"
#include <algorithm>
#include "Image.h"
#include "Pixel.h"
#include "Color.h"
#ifndef stenciling_H_
#define stenciling_H_
class stenciling :public Image
{
	private :
		int w,h;
public:
	stenciling(Image *i,int w,int h);
	Image* Stenciling(Image *i);
	Image* generate_image1();
	void generate_image(int n,int m,Image *ii);
	bool check(float r,int i,int j,int xc,int yc);
};
#endif
