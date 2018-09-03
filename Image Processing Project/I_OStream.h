#ifndef I_OStream_h
#define I_OStream_h

#include<fstream>
#include <stdlib.h>
#include "Image.h"
#include "Pixel.h"
#include "Color.h"

ostream& operator<<(ostream &os, Color &c);
istream& operator>>(istream &is, Color &col);
ostream& operator<<(ostream &os, Pixel &pix);
istream& operator>>(istream &is, Pixel &pix);
ostream& operator<<(ostream &os, Image &img);
istream& operator>>(istream &is, Image &img);

#endif
