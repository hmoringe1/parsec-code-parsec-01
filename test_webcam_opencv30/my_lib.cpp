#include "my_lib.h"
#include "opencv2/opencv.hpp"
///////////////////////////////////Seillage Couleur///////////////////////////////////////////////
Mat seuillage_couleur (Mat frame){
 float nr;
for (int i=0;i<frame.rows;i++){
	for (int j=0;j<frame.cols;j++){
		uchar r,v,b;

		b=frame.at<Vec3b>(i,j)[0];
		v=frame.at<Vec3b>(i,j)[1];
		r=frame.at<Vec3b>(i,j)[2];
		nr=r/sqrt((r*r)+(b*b)+(v*v));

		if (nr>0.8){
			frame.at<Vec3b>(i,j)[0]=b;
			frame.at<Vec3b>(i,j)[1]=r;
			frame.at<Vec3b>(i,j)[2]=r;

		}
		else {
			frame.at<Vec3b>(i,j)[0]=b;
			frame.at<Vec3b>(i,j)[1]=v;
			frame.at<Vec3b>(i,j)[2]=r;
		}

			

	}
}
return frame;
}

///////////////////////////////////Noir et Blanc //////////////////////////////////////////////////////

Mat noir_blanc (Mat frame){	

Mat gray,frameOut;


cvtColor(frame,gray,CV_BGR2GRAY);
frameOut.create(frame.rows,frame.cols,CV_8UC1);

for (int i=1;i<frame.rows;i++){
for(int j=1;j<frame.cols;j++){


short cont=gray.at<uchar>(i,j);

frameOut.at<uchar>(i,j)=(uchar)abs(cont);
		}
	}
return frameOut;
}

///////////////////////////////Contour/////////////////////////////////////////////////////////////////
Mat contour (Mat frame){

Mat gray,Outframe,nOutframe;



cvtColor(frame,gray,CV_BGR2GRAY);
Outframe.create(frame.rows,frame.cols,CV_8UC1);


for (int i=1;i<frame.rows;i++){
	for(int j=1;j<frame.cols;j++){


	

	short cont=(-1)*((short)gray.at<uchar>(i,j-1)+(short)gray.at<uchar>(i-1,j)+(short)gray.at<uchar>(i,j+1)+(short)gray.at<uchar>(i+1,j))+4*(short)gray.at<uchar>(i,j);


	Outframe.at<uchar>(i,j)=(uchar)abs(cont);

	if (Outframe.at<uchar>(i,j)>30){
		Outframe.at<uchar>(i,j)=255;}
	else {
		Outframe.at<uchar>(i,j)=0;}
}
}
return Outframe;
}

//////////////////////////////////normal/////////////////////////////////////////
Mat normal (Mat frame){
for (int i=0;i<frame.rows;i++){
	for (int j=0;j<frame.cols;j++){
uchar r,v,b;
	   b=frame.at<Vec3b>(i,j)[0];
		v=frame.at<Vec3b>(i,j)[1];
		r=frame.at<Vec3b>(i,j)[2];

			frame.at<Vec3b>(i,j)[0]=b;
			frame.at<Vec3b>(i,j)[1]=v;
			frame.at<Vec3b>(i,j)[2]=r;
}
}
return frame;
}
//////////////////////////moyenneur////////////////////////////////////////////:
Mat moyenneur (Mat frame){
Mat frameOut;
medianBlur(frame, frameOut, 5);
return frameOut;
}
/////////////mirroir//////////////////////////////////////////

Mat mirroir (Mat frame){
for (int i=0;i<frame.rows;i++){
	for (int j=0;j<frame.cols;j++){
uchar r,v,b;
	b=frame.at<Vec3b>(i,640-j)[0];
		v=frame.at<Vec3b>(i,640-j)[1];
		r=frame.at<Vec3b>(i,640-j)[2];

			frame.at<Vec3b>(i,j)[0]=b;
			frame.at<Vec3b>(i,j)[1]=v;
			frame.at<Vec3b>(i,j)[2]=r;


}
}
return frame;
}

