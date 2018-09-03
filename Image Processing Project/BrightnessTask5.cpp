#include "BrightnessTask5.h"
#include "Brightness.h"
#include "BinaryImage.h"
#include "CompositeImage.h"
#include "Reflection.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>

using namespace std;

BrightnessTask5::BrightnessTask5(){

}

BrightnessTask5::BrightnessTask5(Image i){           // the histogram gets calculated as soon as the brightness object is created.
  img = i;
  Image c(i);
  C = c;
  Image d(i);
  D = d;
  computeBrightnessHistogram();
}



void BrightnessTask5::findLocalMin(){
     for(int i=3;i<252;i++){
        if(brightness1[i]<brightness1[i-1] &&brightness1[i]<brightness1[i-2] &&brightness1[i]<brightness1[i-3]
        && brightness1[i]<brightness1[i+1] && brightness1[i]<brightness1[i+2] &&  brightness1[i]<brightness1[i+3]
        &&brightness1[i]!=0)
           min.push_back(i);
        }
     }
void BrightnessTask5::printHist() {
       int width = 256;
       int height = 0;
       for(int i = 0; i < width; i++) {
         if(height < brightness1[i]) {
           height = brightness1[i];
         }
       }
       Image image(width, height);
       for(int i = 0; i < height; i++) {
         for(int j = 0; j < width; j++) {
           if(brightness1[j] >= height - i) {
             Color c = Color(0, 0, 0);
             image.getPix()[i][j].setCol(c);
           } else {
             Color c = Color(255, 255, 255);
             image.getPix()[i][j].setCol(c);
           }
         }
       }

      }
void BrightnessTask5::printMin(){
        for(int i=0;i<min.size();i++){
           cout<<brightness1[min[i]]<<endl;
        }
        cout<<"count: "<<min.size()<<endl;
     }

void BrightnessTask5::setThreshold(){
        T1=img.getWidth()*img.getHeight();
        T2=img.getWidth()*img.getHeight();

         for(int i=0;i<min.size();i++){
            if(brightness1[min[i]]<T1){
                  T2=T1;
                  T1=min[i];
               }
            else if (brightness1[min[i]] < T2 && brightness1[min[i]] != T1)
               T2 = min[i];
           }
           // if(min.size()>2){T1=min[0];T2=min[1];}
     }

void BrightnessTask5::CreateImage_CD(){
           int bri;
           for(int i=0;i<img.getHeight();i++){
              for(int j=0;j<img.getWidth();j++){

                 bri=(img.getPix()[i][j].getCol().getRed()+img.getPix()[i][j].getCol().getBlue()+img.getPix()[i][j].getCol().getGreen())/3;
                 if(T1!=img.getWidth()*img.getHeight() && T2!=img.getWidth()*img.getHeight()){
                    if(bri<T1){

                      C.getPix()[i][j].setCol(Color(0,0,255));
                    }
                    else {

                      C.getPix()[i][j].setCol(Color(255,255,255));

                    }

                    if(bri<T2){
                      D.getPix()[i][j].setCol(Color(255,255,0));

                    }
                    else {
                       C.getPix()[i][j].setCol(Color(255,255,255));
                    }
                 }
              }
           }

           if(T1==img.getWidth()*img.getHeight() && T2==img.getWidth()*img.getHeight()){
                   Reflection ref(img);
                   Image c(ref.ReflectionX());
                   C=c;
                   Image d(ref.ReflectionY());
                   D=d;
                }
           CompositeImage Com(D,C,0.2);
           ofstream fout;
           fout.open("output_task5_imt2016092.ppm");
           fout<<Com;
           fout.close();

        }

void BrightnessTask5::run(){
              findLocalMin();
               setThreshold();
               CreateImage_CD();

        }
