//����þ� ���� �����
#include <opencv.hpp>

using namespace cv;
using namespace std;

void main()
{
	Mat src = imread("C:\\Users\\happy\\OneDrive\\���� ȭ��\\!���б��ּ�����\\����ó��\\ȭ�Ұ� ��� ó�� Code\\4.ȭ�Ұ����ó��\\lena.jpg", IMREAD_GRAYSCALE);//�����̹��� ��� ���κҷ�����
	Mat dst = Mat::zeros(src.rows, src.cols, src.type());//���� �̹��� 
	Mat dst3 = Mat::zeros(src.rows, src.cols, src.type());//�߾Ӱ� 
	Mat dst1 = Mat::zeros(src.rows, src.cols, src.type());//������� 
	Mat dst2 = Mat::zeros(src.rows, src.cols, src.type());//����þ� 
	// dst,dst1,dst2= Mat::zeros(src.rows, src.cols, src.type()); ������ src ����� ���� ũ��, ���� �ڷ���, 0���� �ʱ�ȭ�Ͽ� ���� ���⿡ ���� ���� �̹��� ������

	//���� �̹����� ����þ� ���� �Ѹ���
	int stddev = 20;//ǥ�� ���� stddev �� 20����
	Mat noise(src.size(), CV_32SC1);//����� 0�̰� ǥ�� ������ stddev�� ����þ� ������ �����Ͽ� noise ��Ŀ� ����
	//����� 0�� ����þ� ������ ������ ��� ����� ������ ���� �ִ� ������ �߻��ϹǷ� ��ȣ �ִ� �ڷ��� ����� ����ؾ���
	//noise ����� ��ȣ �ִ� ������(CV_32SC1)�� ���
	randn(noise, 0, stddev);//noise ����� randn() �Լ��� ����

	add(src, noise, dst, Mat(), CV_8U);//����+���� ����, �Է� ���� src�� ����þ� ���� noise�� ���Ͽ� ��� ���� dst�� ����

	imshow("����þ� ������ ����", dst);//����+���� ������ ���

	//kernel 7����7
	//1.������� ����Averaging Point(-1,-1)
	blur(dst, dst1, Size(7,7),Point(-1,-1));

	//2.����þ� ���� ����
	GaussianBlur(dst, dst2, Size(7, 7),1.1,1.1);

	//3.�߾Ӱ� ���� ����
	medianBlur(dst, dst3, 7);

	imshow("������� ����", dst1);//������� ���� �̹��� ���
	imshow("����þ� ���� ����", dst2);//����þ����� ���� �̹��� ���
	imshow("�߾Ӱ� ���� ����", dst3);//�߾Ӱ����� ���� �̹��� ���
	
	waitKey();
}