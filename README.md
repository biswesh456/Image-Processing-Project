# Image-Processing-Project

##Code Structure:

* The code takes in argument from the command line and the decides which task to do. We have an array of function pointers which maps to different functions(tasks). The task file contains these tasks.

* We have a base Image class which contains pixels of the image, width, height etc. The class also acts as base class for various types of images such as BinaryImage, CompositeImage, MirrorImage etc.

* We contain a brightness class contains an image. This class has functions like calculating the thresholds, create binary images and find connected components on the basis of the brightness of pixels of the image. All the codes are derived from bases classes which helped in making it modular. Hence we didn't face much problem in integrating our code. 



