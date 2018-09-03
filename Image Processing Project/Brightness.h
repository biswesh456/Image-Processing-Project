#ifndef Brightness_h
#define Brightness_h

#include <vector>

#include "Pixel.h"
#include "Image.h"

using namespace std;

// a class which takes care of all the functions related to brightness of an image.
// it has an image and thus is flexible to function on any kind of image derived from the base class Image.


class Brightness{

  protected:
    Image img;
    float** brightness;                                   // stores the brightness of each pixel
    int histogram[256];                                   // array storing the histogram of brightness
    vector<int> thresholdPosition,threshold;              // thresholdPosition stores the histogram positions of thresholds
  public:
    Brightness();
    Brightness(Image i);
    Brightness(const Brightness &b);
    ~Brightness();
    float** getBrightness();                              // gives us a 2d array containing brightness of each pixel;
    Image getImg();
    void computeBrightnessHistogram();                    // calculates the number of pixels in each brightness(0 to 255)
    int* getBrightnessHistogram();
    void showHistogram(int yScale);                       // outputs the histogram in output.ppm file
    void calculateThreshold();                            // calculates the thresholds i.e local minima in this case
    vector<int> getThreshold();
    void convertImageBinary();                            // convert image black and white on the basis of median threshold.
    void findConnectedComponents();                       // finds out the connected components of an image
    void mergeGroups(vector<vector<int> > &groups, int grp1, int grp2);         // merges 2 groups if both are same
    void ChangeColor();                                   // converts image colours on the basis of the thresholds
};


#endif
