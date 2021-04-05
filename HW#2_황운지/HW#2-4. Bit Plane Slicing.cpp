#include <opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

char print(int i) {
	char temp = (char)(i + '0');
	return temp;
}

int main()
{
	Mat m1 = imread("C:/Users/happy/OneDrive/바탕 화면/!막학기최선다해/영상처리/화소값 기반 처리 Code/4.화소값기반처리/Fig0314(a)(100-dollars).tif", IMREAD_GRAYSCALE);
	imshow("Original", m1);//기본 이미지 출력 
	int cols, rows, x, y;
	cols = m1.cols; //픽셀 행 값 
	rows = m1.rows;//픽셀 열 값
	printf("%d %d \n", m1.rows, m1.cols);
	Mat out[9];//비트플레인값 저장할 변수 

	for (int i = 0; i <=8; i++) {//최하위 비트부터 비트 플레인 하나씩 떼서 out에 저장 
		out[i] = Mat(rows, cols, CV_8UC1, Scalar(0));
	}

	for (int i = 0; i <8; i++) {//비트플레인0부터7까지 
		for (int x = 0; x < rows; x++) {//이미지의 각 픽셀마다 돌면서 
			for (int y = 0; y < cols; y++) {//해당하는 비트플레인 만 떼서 픽셀 값에 저장 
				out[i].at<uchar>(x, y) = (m1.at<uchar>(x, y) & uchar(pow(2,i))) ? uchar(255) : uchar(0); //이미지 변환 
			}
		}
		string s = "dstImage";//변환한 그림 출력할때 마다 제목붙이고 
		s += print(i);//그뒤에 몇번째 비트플레인인지 출력 
		imshow(s, out[i]);
	}
	
	waitKey(0);

	return 0;
}
