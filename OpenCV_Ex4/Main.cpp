#include <opencv2/opencv.hpp>
#include "Sharpen.h"
using namespace std;
using namespace cv;

int main() {

	Mat src_img = imread("test.jpg");
	imshow("test", src_img);
	Mat gray_img;
	cvtColor(src_img, gray_img, COLOR_RGB2GRAY);
	//Mat sobel_img = Sharpen(gray_img).Sobel();
	Mat sobel_cv_img;
	Sobel(gray_img,sobel_cv_img,-1,1,1);
	imshow("sobel", sobel_cv_img);
	waitKey();
}