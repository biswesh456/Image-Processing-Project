#include "I_OStream.h"

ostream& operator<<(ostream &os, Color &c){
    os << (int)c.red << " " << (int)c.green << " " << (int)c.blue;
    return os;
}
istream& operator>>(istream &is, Color &col){
    is>>col.red>>col.green>>col.blue;
    return is;
}


ostream& operator<<(ostream &os, Pixel &pix){
    os<<pix.col;
    return os;
}
istream& operator>>(istream &is, Pixel &pix){
    is>>pix.x>>pix.y>>pix.col;
    return is;
}


ostream& operator<<(ostream &os, Image &img){

  os << "P3" << endl;
  os << img.width << " " << img.height << endl;
  os << img.maxColor << endl;
  for (int i = 0; i < img.height; i++) {
      for (int j = 0; j < img.width; j++) {
          Color c = img.pix[i][j].getCol();
          os << c << " ";
      }
      os << endl;
  }
  return os;
}
istream& operator>>(istream &is, Image &img){
    is>>img.width>>img.height;
    return is;
}
