#ifndef Image_h
#define Image_h
#include<fstream>
#include<cstring>
#include<cstdlib>

#include "Pixel.h"
#include "Color.h"

using namespace std;

class Image{
    protected:
        int width,height,maxColor;
        Pixel** pix;

    public:
        Image();
        Image(char *fileName);
        Image(int x,int y);
        Image(const Image &i);
        ~Image();
        int getHeight();
        int getWidth();
        Pixel** getPix();
        void operator=(Image &img);
        void filter(Color c, float alpha);
        void createNoiseImage();
        friend ostream& operator<<(ostream &os, Image &v);
        friend istream& operator>>(istream &is, Image &v);

};

#endif
