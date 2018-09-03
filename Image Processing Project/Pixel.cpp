#include "Pixel.h"

using namespace std;

Pixel::Pixel(){

}
Pixel::Pixel(int X,int Y,Color c):x(X),y(Y),col(c){

}
Pixel::~Pixel(){

}

Pixel::Pixel(Pixel &p){
    x=(p.x);
    y=(p.y);
    col = p.col;
}
void Pixel::operator=(Pixel &pix){
    x = pix.x;
    y = pix.y;
    col = pix.col;
}
void Pixel::setCol(Color c){
    col = c;
}

Color Pixel::getCol(){
    return col;
}
