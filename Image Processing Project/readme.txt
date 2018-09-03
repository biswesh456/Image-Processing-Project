                      



					CPP CODE README FILE					
		                 	  (GROUP -18 )
        
    Student Name        Roll Number   Task Number
    N.Sai Akshara       IMT2016022        8   
    Biswesh Mohapatra   IMT2016050        6

    Sagar Kumar         IMT2016071        4
    Mannepalli Yashaswi IMT2016092        5

    Kotha Tejas         IMT20160112       1
    Rishikesh Chaumal   IMT2016131        7



INDIVIDUAL CONTRIBUTIONS:
1) N.Sai Akshara:

	Did task 8 using my base codes(which was working fine) initially.
	As task 8 is an extension of task 6 I had to change my code and use the code of Biswesh(whose task is 6th).
	I  created the noise function using rand() to generate a random color and set it to each pixel in the image base class.
	Later I wrote the main function.
  			
2) Biswesh Mohapatra:

	Provided the base classes for the group. These included the following classes:
			
			a) Color  b) Pixel  c) Image 	 d) CompositeImage
	
	The integration of all the tasks was also done by me. To integrate the classes I have included the following files:
				
			a) tasks.cpp(contains all the tasks that are integrated)  b)I_OStream.cpp(for all input output operations)

	Did the task 6. Thus I made the following classes for it:
			
			a) BinaryImage(gives binary form of the image on the basis of threshold)   b) Brightness(class which does all work related to brightness such as histogram and connectedComponent).


3) Sagar:
	
	Did the task 4. For this I created the changeColour() function in brightness class. 
	I created the histogram and then added colour to first 6 range of threshold. Later I contributed the function to the group and used the group bases class function of histogram.

4) Yashaswi:


			
5) Tejas:

	Did the task 1. For this I created the following classes:
			
			a) clipping			: Clips the given image with 5 different circles in each of the quadrant and the origin.
			b) stencilling  		: Creates a mirror image of the clipped image. 
			c) composite			: Combines the clipped image and stencilled image. 

6) Rishikesh Chaumal:
	
	Did the task 7. For this I created the following classes:

			a)ScaledImage			: Scales the image but keeps the image size same 			b)MirrorImage			: Mirrors the image on X-axis or Y-axis as per need			c)PrimitiveSquareImage		: Cuts out the middle primitive square image as described in the question 


Final group contribution:
   Base classes: Biswesh
   Tasks, main: Biswesh	
   Classes - BinaryImage, CompositeImage, Brightness: Biswesh
   noise function in Image class: Akshara			
   Documentation: Akshara
   Reflection function: Tejas
   Classes - Clipping, Stencilling: Tejas
   Classes - MirrorImage, PrimitiveSquareImage, ScaledImage: Rishikesh
   changeColour function: Sagar	  		
	  							
 		
		
Code Structure:

The code takes in argument from the command line and the decides which task to do. We have an array of function pointers which maps to different functions(tasks). The task file contains these tasks.
We have a base Image class which contains pixels of the image, width, height etc. The class also acts as base class for various types of images such as BinaryImage, CompositeImage, MirrorImage etc.
We contain a brightness class contains an image. This class has functions like calculating the thresholds, create binary images and find connected components on the basis of the brightness of pixels of the image. All the codes are derived from bases classes which helped in making it modular. Hence we didn't face much problem in integrating our code. 
 






















































