#include "Image.h"

using namespace std;

Image::Image(){

}
Image::Image(char *fileName){
    ifstream fin;
    fin.open(fileName);
    char type[10];
    fin >> type;
    if (strcmp(type, "P3")) {
        cout << "WRONG FORMAT" << endl;
    }

    fin >> width;
    fin >> height;
    fin >> maxColor;

    pix = new Pixel*[height];
    for(int i=0;i<height;i++){
        pix[i] = new Pixel[width];
    }

    int r, g, b;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fin >> r >> g >> b;
            Color c(r,g,b);
            pix[i][j].setCol(c);
        }
    }
    fin.close();
}
Image::Image(int X,int Y){
    width = Y;
    height = X;
    pix = new Pixel*[X];
    for(int i=0;i<X;i++){
        pix[i] = new Pixel[Y];
    }
}
Image::~Image(){

}

Image::Image(const Image &p):width(p.width),height(p.height),maxColor(p.maxColor){
    pix = new Pixel*[height];
    for(int i=0;i<height;i++){
        pix[i] = p.pix[i];
    }
}
void Image::operator=(Image &img){
    width = img.width;
    height = img.height;
    pix = img.pix;
}

void Image::filter(Color c, float alpha) {

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Color col = pix[i][j].getCol()*(1-alpha) + c*alpha;
            pix[i][j].setCol(col);
        }
    }
}

int Image::getHeight(){
  return height;
}

int Image::getWidth(){
  return width;
}

Pixel** Image::getPix(){
    return pix;
}

void Image::createNoiseImage(){
    srand(time(NULL));
    int g;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            g = rand() % 256;
            Color col(g,g,g);
            pix[j][i].setCol(col);
        }
    }
}
