#include<vector>
#include<fstream>
#include <stdlib.h>
#include<math.h>

#include "Image.h"
#include "Pixel.h"
#include "Color.h"
#include "Brightness.h"
#include "CompositeImage.h"
#include "ScaledImage.h"
#include "MirrorImage.h"
#include "task1Functions.h"
#include "clipping.h"
#include "stenciling.h"
#include "tasks.h"
#include "I_OStream.h"

int main(int argc, char *argv[]){

    void (*functions[])(char* ) = {Task1, Task2, Task3, Task4, Task5, Task6, Task7, Task8};

    if(argc == 1){
      cout<<"Wrong Input Format"<<endl;
      return 0;
    }
    else if(argc == 2){
      cout<<"OUR GROUP TASK ID IS: 1,4,5,6,7,8"<<endl;
      functions[0](argv[1]);
      functions[3](argv[1]);
      functions[4](argv[1]);
      functions[5](argv[1]);
      functions[6](argv[1]);
      functions[7](argv[1]);
    }
    else{
      cout<<"OUR GROUP TASK ID IS:";
      for(int i=0;i<argc-2;i++){
        cout<<" "<<argv[i+2];
      }
      cout<<endl;

      for(int i=0;i<argc-2;i++){
        functions[stoi(argv[i+2])-1](argv[1]);
      }
    }
    return 0;

}
