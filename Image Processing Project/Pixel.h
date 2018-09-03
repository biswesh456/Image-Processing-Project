#ifndef Pixel_h
#define Pixel_h
#include<iostream>

#include "Color.h"

using namespace std;

class Pixel{
    private:
        int x,y;
        Color col;
    public:
        Pixel();
        Pixel(int X,int Y,Color c);
        Pixel(Pixel &p);
        ~Pixel();
        void setCol(Color c);
        Color getCol();
        void operator=(Pixel &pix);
        friend ostream& operator<<(ostream &os, Pixel &v);
        friend istream& operator>>(istream &is, Pixel &v);
};


#endif
