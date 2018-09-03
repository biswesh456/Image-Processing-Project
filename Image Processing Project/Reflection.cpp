#include"Reflection.h"
#include"Image.h"

   Reflection::Reflection(){}
   Reflection::Reflection(Image I):Image(I){}

   Image Reflection::ReflectionX(){
      	Image answer(getWidth(),getHeight());
      	for(int i = 0 ; i < getHeight() ; i++){
      		for(int j = 0 ; j < getWidth() ; j++){

      			answer.getPix()[i][j].setCol(getPix()[getHeight()-1-i][j].getCol());
      		}
      	}
      	return answer;
      }


   Image Reflection::ReflectionY(){
      Image answer(getWidth(),getHeight());
      for(int i = 0 ; i < getHeight() ; i++){
         for(int j = 0 ; j < getWidth() ; j++){
            answer.getPix()[i][j].setCol(getPix()[i][getWidth()-1-j].getCol());
         }
      }
      return answer;
   }

   Image Reflection::ReflectionXY(){
      Image answer(ReflectionX());

      Reflection ref=answer;
      Image c(ref.ReflectionY());
      answer=c;
      return answer;
   }
