#pragma once
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
class Sharpen
{
public:
	
	Sharpen(Mat _src_img);

	Mat Sobel();
	~Sharpen();
private:
	int Sobel_Op(int row,int col,Mat inputMat);
	Mat src_img;
};

