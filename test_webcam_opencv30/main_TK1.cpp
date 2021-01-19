#include "my_lib.h"
#include "opencv2/opencv.hpp"
using namespace cv;



int main(int, char**){

VideoCapture cap(0); // open the default camera
	if(!cap.isOpened())  // check if we succeeded
		return -1;




	//VideoCapture cap(); // open the default camera
	if(!cap.isOpened())  // check if we succeeded
		return -1;




 int a=0;//permet de boucler la fonction

	while(1){

            Mat frame,Newframe,Contour;
	    // Capture frame-by-frame
	    cap >> frame;
             

	    char c=(char)waitKey(20);

	    if (c==115 || a==115){// touche s (seuillage)
	 	 a=115;
	  	frame= seuillage_couleur (frame);
	    }

             if (c==110 || a==110){// touche n (noir et blanc)
        	a=110;
		frame=noir_blanc(frame);
	     }

	     if (c==99  || a==99 ){// touche c (contour)
        	a=99;
		frame=contour(frame);
	     }

	     if (c==111 || a==111){// touche o (original)
	       a=111;
	       frame=normal(frame);
	     }

	     if (c==109 || a==109){//touche m (moyenneur)
	        a=109;
		frame= moyenneur (frame);
	     }
	     
	     if (c==103 || a==103){// touche g (glass mirroir)
		a=103;
		frame=mirroir(frame);
	     }

	     if(c==27)
	      break;

		imshow( "frame", frame);
	  }

	  // When everything done, release the video capture object
	  cap.release();
         

	  // Closes all the frames
	  destroyAllWindows();

	  return 0;
}

