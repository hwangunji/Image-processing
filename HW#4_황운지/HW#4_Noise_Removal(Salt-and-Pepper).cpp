//���߼ұ����� �����
#include <opencv.hpp>

using namespace cv;
using namespace std;

void main()
{
	Mat src = imread("C:\\Users\\happy\\OneDrive\\���� ȭ��\\!���б��ּ�����\\����ó��\\ȭ�Ұ� ��� ó�� Code\\4.ȭ�Ұ����ó��\\lena.jpg",IMREAD_GRAYSCALE);//�����̹��� ��� ���κҷ�����
	Mat dst = Mat::zeros(src.rows, src.cols, src.type());//������� 
	Mat dst1 = Mat::zeros(src.rows, src.cols, src.type());//����þ� 
	Mat dst2 = Mat::zeros(src.rows, src.cols, src.type());//�߾Ӱ� 
	// dst,dst1,dst2= Mat::zeros(src.rows, src.cols, src.type()); ������ src ����� ���� ũ��, ���� �ڷ���, 0���� �ʱ�ȭ�Ͽ� ���� ���⿡ ���� ���� �̹��� ������

	//���� �̹����� ���� �ұ� ���� �Ѹ��� (5%)
	int zabem = (int)(src.total() * 0.05);//��ü �ȼ��߿� 5%��ŭ ���� ������ �ž�

	for (int i = 0; i < zabem; i++) {//���� ������ŭ
		int x = rand() % src.cols;//�̹����� cols�߿��� �������� ���
		int y = rand() % src.rows;//�̹����� rows�߿��� �������� ���
		src.at<uchar>(y, x) = (i % 2) * 255;//�� ȭ�Ұ��� �������� ����
	}

	//kernel 3����3 
	//1.������� ����Averaging
	//Point (-1, -1),kernel (filter)���� ����� �߽����� ����
	blur(src, dst, Size(3, 3), Point(-1, -1));

	//2.����þ� ���� ����
	GaussianBlur(src, dst1, Size(3,3), 1);

	//3.�߾Ӱ� ���� ����
	medianBlur(src, dst2, 3);
	
	imshow("���� ����", src);//�����̹��� ���
	imshow("������� ����", dst);//������� ���� �̹��� ���
	imshow("����þ� ���� ����", dst1);//����þ����� ���� �̹��� ���
	imshow("�߾Ӱ� ���� ����", dst2);//�߾Ӱ����� ���� �̹��� ���

	waitKey();
}