#include "tasks.h"
#include "BrightnessTask5.h"

void Task1(char *fileName){

  Image *img1 = new Image(fileName);
  int h = (*img1).getHeight();
  int w = (*img1).getWidth();
  Image *img2 = new Image(h,w);

  img2 = reflection(img1);

  ofstream output1;
  ofstream output2;
  ofstream output3;

  stenciling *t=new stenciling(img1,w,h);

  output1.open("output_task1_imt2016112_stenciled.ppm");
  output1<<"P3"<<"\n";
  output1<<w<<"\n"<<h<<"\n";
  output1<<255<<"\n";
  output1 << *((*t).Stenciling(img2));

  clipping *s=new clipping(img1,w,h);
  output2.open("output_task1_imt2016112_clipped.ppm");
  output2<<"P3"<<"\n";
  output2<<w<<"\n"<<h<<"\n";
  output2<<255<<"\n";
  output2 << *((*s).Clipping(img1));

  output3.open("output_task1_imt2016112_composite.ppm");
  output3<<"P3"<<"\n";
  output3<<w<<"\n"<<h<<"\n";
  output3<<255<<"\n";
  output3 << *(composite(0.5,(*s).Clipping(img1),(*t).Stenciling(img2)));
  // cout << "tejas"<< endl;
  output1.close();
  output2.close();
  output3.close();
  cout<<"Task 1 completed"<<endl;
}

void Task4(char *fileName){

  Image im1(fileName);
  Image im2(fileName);
  Brightness b(im1);                         // task 4
  b.ChangeColor();
  Image i = b.getImg();
  CompositeImage com(i,im2,0.4);
  ofstream fout;
  fout.open("output_task4_imt2016071.ppm");
  fout<<com;
  fout.close();
  cout<<"Task 4 completed"<<endl;
}

void Task6(char *fileName){

      Image im1(fileName);
      Brightness b(im1);
      // b.showHistogram(10); // give the y-scale as argument
      ofstream fout;
      ofstream fout2;
      fout.open("output_task6_imt2016050_connectedcomponent.ppm");
      fout2.open("output_task6_imt2016050_binaryimage.ppm");

      b.convertImageBinary();
      Image binImg = b.getImg();
      fout2<<binImg;
      b.findConnectedComponents();
      Image img = b.getImg();
      fout<<img;
      fout.close();
      fout2.close();
      cout<<"Task 6 completed"<<endl;
}

void Task7(char *fileName){

  Image im1(fileName);
  ofstream fout("output_task7_imt2016131_scaledImage.ppm");          // task of rishikesh
  ofstream fout2("output_task7_imt2016131_c.ppm");
  ScaledImage sim(im1);
  MirrorImage simx;
  MirrorImage simxy;
  simx.MirrorX(sim);
  simxy.MirrorY(simx);
  fout<<sim;
  fout2<<simxy;
  fout.close();
  fout2.close();
  cout<<"Task 7 completed"<<endl;
}

void Task8(char* fileName){

  Image im1(fileName);
  Image noise(im1.getHeight(),im1.getWidth());
  noise.createNoiseImage();
  CompositeImage com(im1,noise,0.5);
  Brightness b(com);
  b.convertImageBinary();
  b.findConnectedComponents();
  Image i = b.getImg();
  ofstream fout;
  fout.open("output_task8_imt2016022.ppm");
  fout<<i;
  fout.close();
  cout<<"Task 8 completed"<<endl;
}

void Task2(char *fileName){
  cout<<"Task 2 not integrated......"<<endl;
}

void Task3(char *fileName){
  cout<<"Task 3 not integrated......"<<endl;
}

void Task5(char *fileName){
   Image I=Image(fileName);
   BrightnessTask5 his(I);
   his.run();
   cout<<"Task 5 completed"<<endl;
}
