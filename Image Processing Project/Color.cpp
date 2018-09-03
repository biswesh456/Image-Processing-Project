#include "Color.h"

using namespace std;

Color::Color(){

}
Color::Color(float x,float y, float z):red(x),green(y),blue(z){

}
Color::~Color(){

}
Color::Color(const Color &c):red(c.red),green(c.green),blue(c.blue){

}
void Color::operator=(Color &col){
    red = col.red;
    green = col.green;
    blue = col.blue;
}

float Color::getRed(){
    return red;
}
float Color::getGreen(){
    return green;
}
float Color::getBlue(){
    return blue;
}

Color Color::operator*(float a){
    Color c;
    c.red = red*a;
    c.blue = blue*a;
    c.green = green*a;
    return c;
}

Color Color::operator+(Color a){
    Color c;
    c.red = red+a.red;
    c.blue = blue+a.blue;
    c.green = green+a.green;
    return c;
}
