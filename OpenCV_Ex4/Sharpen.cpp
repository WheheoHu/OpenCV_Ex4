#include "Sharpen.h"


#include <vector>


Sharpen::Sharpen(Mat _src_img)
{
	this->src_img = _src_img;
}

Mat Sharpen::Sobel()
{
	Mat res_img = src_img.clone();
	if (!res_img.data)
	{
		return src_img;
	}
	auto img_row = res_img.rows;
	auto img_col = res_img.cols;
	for (int row = 0; row < img_row; row++)
	{
		for (int col = 0; col < img_col; col++)
		{
			if (row > 0 && col > 0 && row < img_row - 1 && col < img_col - 1)
			{

				res_img.at<uchar>(row, col) = Sobel_Op(row, col, res_img);
				//res_img.at<uchar>(Point(row, col)) = res_img.at<uchar>(Point(row, col));

			}
			else
			{
				res_img.at<uchar>(row, col) = res_img.at<uchar>(row, col);
			}
		}
	}


	return res_img;
}

Sharpen::~Sharpen()
{
}

int Sharpen::Sobel_Op(int row, int col, Mat inputMat)
{
	Mat dx = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	Mat dy = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);

	//Mat src = inputMat.rowRange(row - 1, row + 2).colRange(col -1, col + 2);
	Mat src = inputMat(Rect(col - 1, row - 1, 3, 3));
	/*cout << inputMat.at<uchar>(row - 1, col - 1) << inputMat.at<uchar>(row - 1, col ) << inputMat.at<uchar>(row - 1, col + 1) << endl;
	cout << inputMat.at<uchar>(row , col - 1) << inputMat.at<uchar>(row , col) << inputMat.at<uchar>(row , col + 1) << endl;
	cout << inputMat.at<uchar>(row + 1, col - 1) << inputMat.at<uchar>(row + 1, col) << inputMat.at<uchar>(row + 1, col + 1) << endl;
	*/
	//int temp = src.at<uchar>(0, 0);
	//TODO finish this
	Mat resx;
	filter2D(src, resx, -1, dx);
	Mat resy;
	filter2D(src, resy, -1, dx);
	
	//int resx = sum(src.mul(dx))[0];
	//int resy = sum(src.mul(dy))[0];
	int x = abs(sum(resx)[0]);
	int y = abs(sum(resy)[0]);

	int res = sqrt(pow(x, 2) + pow(y, 2));
	res = x + y;


	return res;
}
