#pragma once
#include "Image.h"
using namespace std;
class MirrorImage:public Image
{
public:
  MirrorImage();
  void MirrorX(Image im);
  void MirrorY(Image im);
  ~MirrorImage();
};
