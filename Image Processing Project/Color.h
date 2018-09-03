#ifndef Color_h
#define Color_h
#include<iostream>

using namespace std;

class Color{

    private:
        float red,green,blue;
    public:
        Color();
        Color(float x,float y, float z);
        Color(const Color &c);
        ~Color();
        float getRed();
        float getGreen();
        float getBlue();
        Color operator*(float a);
        Color operator+(Color a);
        void operator=(Color &col);
        friend ostream& operator<<(ostream &os, Color &v);
        friend istream& operator>>(istream &is, Color &v);
};


#endif
