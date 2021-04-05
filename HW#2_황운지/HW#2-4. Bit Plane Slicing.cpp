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
	Mat m1 = imread("C:/Users/happy/OneDrive/���� ȭ��/!���б��ּ�����/����ó��/ȭ�Ұ� ��� ó�� Code/4.ȭ�Ұ����ó��/Fig0314(a)(100-dollars).tif", IMREAD_GRAYSCALE);
	imshow("Original", m1);//�⺻ �̹��� ��� 
	int cols, rows, x, y;
	cols = m1.cols; //�ȼ� �� �� 
	rows = m1.rows;//�ȼ� �� ��
	printf("%d %d \n", m1.rows, m1.cols);
	Mat out[9];//��Ʈ�÷��ΰ� ������ ���� 

	for (int i = 0; i <=8; i++) {//������ ��Ʈ���� ��Ʈ �÷��� �ϳ��� ���� out�� ���� 
		out[i] = Mat(rows, cols, CV_8UC1, Scalar(0));
	}

	for (int i = 0; i <8; i++) {//��Ʈ�÷���0����7���� 
		for (int x = 0; x < rows; x++) {//�̹����� �� �ȼ����� ���鼭 
			for (int y = 0; y < cols; y++) {//�ش��ϴ� ��Ʈ�÷��� �� ���� �ȼ� ���� ���� 
				out[i].at<uchar>(x, y) = (m1.at<uchar>(x, y) & uchar(pow(2,i))) ? uchar(255) : uchar(0); //�̹��� ��ȯ 
			}
		}
		string s = "dstImage";//��ȯ�� �׸� ����Ҷ� ���� ������̰� 
		s += print(i);//�׵ڿ� ���° ��Ʈ�÷������� ��� 
		imshow(s, out[i]);
	}
	
	waitKey(0);

	return 0;
}
