#include "Brightness.h"
#include "BinaryImage.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>

using namespace std;

enum color{
  red, green, blue, cyan, magenta, yellow
};

Brightness::Brightness(){

}

Brightness::Brightness(Image i):img(i){           // the histogram gets calculated as soon as the brightness object is created.
  computeBrightnessHistogram();
}

Brightness::Brightness(const Brightness &b):img(b.img){
  computeBrightnessHistogram();
}

Brightness::~Brightness(){
  for(int i=0;i<img.getHeight();i++){
        delete[] brightness[i];
    }
    delete[] brightness;
}

float** Brightness::getBrightness(){
    return brightness;
}

Image Brightness::getImg(){
    return img;
}

int* Brightness::getBrightnessHistogram(){
    return histogram;
}

// next function computes brightness by taking the mean of the rgb values of a pixel and then calculates the histogram

void Brightness::computeBrightnessHistogram(){

  brightness = new float*[img.getHeight()];
  for(int i=0;i<img.getHeight();i++){
      brightness[i] = new float[img.getWidth()];
  }

  for (int i = 0; i < img.getHeight(); i++) {
      for (int j = 0; j < img.getWidth(); j++) {
        brightness[i][j] = (img.getPix()[i][j].getCol().getRed()+img.getPix()[i][j].getCol().getGreen()+img.getPix()[i][j].getCol().getBlue())/3;
      }
    }


  for(int i=0;i<256;i++){
    histogram[i] = 0;
  }

  for(int i=0;i<img.getHeight();i++){
    for(int j=0;j<img.getWidth();j++){
      int A = round(brightness[i][j]);
      histogram[A]+=1;
    }
  }
  calculateThreshold();
}

// this function calculates the local minima

void Brightness::calculateThreshold(){

    int range = 1;
    for(int i=0;i<256;i++){
      int flag = 0;
      for(int j=-range;j<=range;j++){
        if(j!=0 && (i+j) >=0 && (i+j)<256 ){
          if(j>0 && histogram[i+j]<=histogram[i]){
            flag=1;
            break;
          }
          else if(j<0 && histogram[i+j]<histogram[i]){
            flag=1;
            break;
          }
        }

      }
      if(flag==0){
        threshold.push_back(histogram[i]);
        thresholdPosition.push_back(i);
      }
    }
}

vector<int> Brightness::getThreshold(){
    return threshold;
}

// this function converts the image to binary image on the basis of the brightness

void Brightness::convertImageBinary(){

  int median;
  int size=thresholdPosition.size();
  if(size%2==1){
    median = thresholdPosition[(size+1)/2];
  }
  else{
    median = (thresholdPosition[size/2]+thresholdPosition[size/2+1])/2;
  }
  // median = 130;
  // cout<<median;
  BinaryImage I(img, median, brightness);
  img = I;
}

// next function determines the connected components in the image.
// the algorithm traverses through the pixels and checks their up, left, upLeft, upRight pixels
// and determines which connected component it belong to. Each connected component has a distinct integer value used as id.
// if for a pixel its neighbouring pixels belong to different connected components then it means that both the connected components are same.
// hence we merge those 2 connected components. We just note that the 2 connectedComponents belong to a single group.
// for this we have created a vector of vectors called groups.
// While calculating the connectedComponent of each pixel, we not down the group that each pixels and also
// have a reverse map of pixels that belong to a particular group. this map helps in making the code highly efficient(O(height*width) or a linear time algorithm)
// finally we go through each group and then to each coonected component in it
// and colour all the pixels in that group(reverse map) with the same colour of the group(so all connectedComponents in same group have same colour).
// the colours for each group is chosen randomly since many groups can get formed.

void Brightness::findConnectedComponents(){

  convertImageBinary();
  int height = img.getHeight();
  int width = img.getWidth();
  int connectedComponent[height][width];
  int count = 0;
  vector<vector<int> > groups;
  vector<vector<pair<int,int> > > map;

  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      connectedComponent[i][j]=-1;
    }
  }
  for(int i=0;i<height;i++){
    int left=-1,up=-1,upLeft=-1,upRight=-1;
    for(int j=0;j<width;j++){

        if(img.getPix()[i][j].getCol().getRed() == 0){

            if(i>0){
              up = connectedComponent[i-1][j];
              if(up!=-1)
                connectedComponent[i][j] = up;
            }

            if(j>0){

              left = connectedComponent[i][j-1];
              if(left!=-1){
                if(connectedComponent[i][j]== -1){
                  connectedComponent[i][j] = left;
                }
                else if(left!=up){
                    connectedComponent[i][j] = up;
                    mergeGroups(groups, up, left);
                }
              }

            }


            if(connectedComponent[i][j]==-1){
              connectedComponent[i][j] = count;
              vector<int> temp;
              temp.push_back(count);
              groups.push_back(temp);

              vector<pair<int,int> > tempMap;
              pair<int,int> tempPair;
              tempPair.first = i;
              tempPair.second = j;

              tempMap.push_back(tempPair);

              map.push_back(tempMap);
              count++;
            }
            else{
              pair<int,int> tempPair;
              tempPair.first = i;
              tempPair.second = j;
              map[connectedComponent[i][j]].push_back(tempPair);

            }
        }
    }
  }


  for(int i=0;i<height;i++){
   for(int j=0;j<width;j++){
      img.getPix()[i][j].setCol(Color(0,0,0));
   }
 }


  for(int m=0;m<groups.size();m++){
    int red = rand()%256;                           // generate random colors for this connected group
    int green = (red*m*12)%(256);
    int blue = (green*m*54)%(256);

    for(int n=0;n<groups[m].size();n++){
        for(int k=0;k<map[groups[m][n]].size();k++){
          Color c(red, green, blue);
          img.getPix()[map[groups[m][n]][k].first ][map[groups[m][n]][k].second].setCol(c);
        }
    }
  }

}

void Brightness::mergeGroups(vector<vector<int> > &groups, int grp1, int grp2){

      int grp1Pos = -1,grp2Pos = -1;

      for(int i=0;i<groups.size();i++){             // find out in which collection of connected groups do the new groups belong
        for(int j=0;j<groups[i].size();j++){
          if(groups[i][j]==grp1){
            grp1Pos = i;
          }
          else if(groups[i][j]== grp2){
            grp2Pos = i;
          }
        }
      }

      if(grp1Pos!=grp2Pos){               // if both the groups are not same then merge the groups

        for(int i=0;i<groups[grp2Pos].size();i++){              // copy values of group2 to group1
            groups[grp1Pos].push_back(groups[grp2Pos][i]);
        }

        groups.erase(groups.begin()+grp2Pos);               // delete group2
      }

}

// function to show the histogram in output.ppm

void Brightness::showHistogram(int yScale){

  int scaledHistogram[256];
  for(int i=0;i<256;i++)
    scaledHistogram[i]=histogram[i]/yScale;

  long long max =scaledHistogram[0];
  for(int j=1;j<256;j++){
      if(max<scaledHistogram[j]){
          max = scaledHistogram[j];
      }
  }
  int Width = 256;
  int Height = max;

  ofstream fout;
  fout.open("output.ppm");

  fout << "P3" << endl;
  fout << Width << " " << Height << " " << 255 <<endl;

  for (int i = 0; i < Height; i++) {

      for (int j = 0; j < Width; j++) {
        int flag=0;
        for(int k=0;k<thresholdPosition.size();k++){
            if(j==thresholdPosition[k]){
              flag=1;
              break;
            }
          }

        if((Height-i)<=scaledHistogram[j]){

          if(flag==1){
            Color c(255,0,0);
            fout << c << " ";
          }
          else{
            Color c(0,0,0);
            fout << c << " ";
          }

        }
        else if(flag==1){
          Color c(0,255,0);
          fout << c << " ";
        }
        else{
          Color c(255,255,255);
          fout << c << " ";
        }
      }
  }
  fout.close();
}

// changes colour of the image on the basis of the threshold

void Brightness::ChangeColor(){

  int size = thresholdPosition.size();
  for(int i=0;i<img.getHeight();i++){
   for(int j=0;j<img.getWidth();j++){
      if((size > 0) && brightness[i][j] < thresholdPosition[0]){
        img.getPix()[i][j].setCol(Color(255,0,0));
      }
      else if(size > 1 && brightness[i][j] < thresholdPosition[1]){
        img.getPix()[i][j].setCol(Color(0,255,0));
      }
      else if(size > 2 && brightness[i][j] < thresholdPosition[2]){
        img.getPix()[i][j].setCol(Color(0,0,255));
      }
      else if(size > 3 && brightness[i][j] < thresholdPosition[3]){
        img.getPix()[i][j].setCol(Color(255,255,0));
      }
      else if(size > 4 && brightness[i][j] < thresholdPosition[4]){
        img.getPix()[i][j].setCol(Color(255,0,255));
      }
      else if(size > 5 && brightness[i][j] < thresholdPosition[5]){
        img.getPix()[i][j].setCol(Color(0,255,255));
      }
      else{
        img.getPix()[i][j].setCol(Color(0,0,0));
      }
   }
 }

}
