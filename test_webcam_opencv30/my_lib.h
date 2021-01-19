#include "opencv2/opencv.hpp"

using namespace cv;
#ifndef MY_LIB_H
#define MY_LIB_H

Mat noir_blanc (Mat frame);
Mat contour (Mat frame);
Mat seuillage_couleur (Mat frame);
Mat normal (Mat frame);
Mat moyenneur (Mat frame);
Mat mirroir (Mat frame);

#endif
