//���� �̹��� ����þ� ���͸��ϱ�
#include <opencv.hpp>

using namespace cv;
using namespace std;

void main()
{
	Mat src = imread("C:/Users/happy/OneDrive/���� ȭ��/!���б��ּ�����/����ó��/ȭ�Ұ� ��� ó�� Code/4.ȭ�Ұ����ó��/lena.jpg", 1);//�����̹��� �ҷ�����
	Mat dst = Mat::zeros(src.rows, src.cols, src.type());
	Mat dst2 = Mat::zeros(src.rows, src.cols, src.type());
	Mat dst3 = Mat::zeros(src.rows, src.cols, src.type());
	// dst, dst2,dst3= Mat::zeros(src.rows, src.cols, src.type()); ������ src ����� ���� ũ��, ���� �ڷ���, 0���� �ʱ�ȭ�Ͽ� ���� ���⿡ ����þ����� ���͸��� �̹��� ������

	//����þ� Ŀ�� ���� �����ϱ�
	//����þ� ������ ���� ǥ�������� �����ϴ� �� �� ���� Ŭ���� ��ȿ���� �� Ŀ��(���� �����ļ����� ������Ѽ�)

	//1.getGaussianKernel ����ϱ�
	//getGaussianKernel�� ����þ� ǥ�� �������ϱ� ���� Ÿ���� CV_64F�� �Ұ���
	//ǥ�� ������ sigma�� 1���� ����þ� ���� �Լ��κ��� ksize��1 ũ���� ���� ����ũ ����� �����Ͽ� ��ȯ
	//ksize��(6 * sigma)���� ũ�� ����->(6*1.5)=9 �׷��� ksize=9
	Mat gauss = getGaussianKernel(9, 1.5, CV_64F);//ǥ������ 1.5�϶� 
	//	gauss�� ksize��1ũ��

	Mat gauss2= gauss * gauss.t();//ksize��1,1�����̴ϱ� ��������� filter2D�� ���� 2�������� �����
	//Ŀ�� ���� �־����� �̰ŷ� ���͸��� �Ұ��� filter2D�̿�
	filter2D(src, dst,-1, gauss2, Point(-1, -1));//������ ����Ʈ������

	//2.GaussianBlur�̿��ϱ�
	//getGaussianKernel�� ǥ������ 1.5�� �����ϱ� �굵 ���� ȿ���� ���� 1.5ǥ�������� ����
	GaussianBlur(src, dst2, Size(9, 9), 1.5, 1.5);//y���� 0���� �ص� �ñ׸� �� 1.5�� ������ �׷��� 1.5 ������

	//ǥ�������� Ŀ���� ȿ���� Ŭ�� ǥ������0.5���� �ؼ���
	GaussianBlur(src, dst3, Size(3, 3), 0.5, 0.5);
	
	imshow("���� ����", src);//�����̹��� ���
	imshow("getGaussianKernel���� ǥ������= 1.5", dst);//ǥ������= 1.5 getGaussianKernel ���
	imshow("GaussianBlur���� ǥ������= 1.5", dst2);//ǥ������= 1.5 GaussianBlur ���
	imshow("GaussianBlur���� ǥ������= 0.5", dst3);//ǥ������= 0.5 GaussianBlur ���

	waitKey();		
}