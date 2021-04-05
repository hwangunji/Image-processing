//����ũ�� ������� �ϱ�
#include <opencv.hpp>

using namespace cv;
using namespace std;

void main()
{
	Mat src = imread("C:\\Users\\happy\\OneDrive\\���� ȭ��\\!���б��ּ�����\\����ó��\\ȭ�Ұ� ��� ó�� Code\\4.ȭ�Ұ����ó��\\Fig0327(a).jpg", IMREAD_GRAYSCALE);
	//�̹��� �ҷ����� �׷��� ������ �������� 

	Mat box_dst = Mat::zeros(src.rows, src.cols, src.type());//�ڽ� ��� �̹��� ����(�ʱ�ȭ)
	Mat gauss_dst = Mat::zeros(src.rows, src.cols, src.type());//����þ� ��� �̹��� ����(�ʱ�ȭ)
	Mat sharpen_dst = Mat::zeros(src.rows, src.cols, src.type());//������ ��� �̹��� ����(�ʱ�ȭ)
	Mat motion_dst = Mat::zeros(src.rows, src.cols, src.type());//��� ��� �̹��� ����(�ʱ�ȭ)
	Mat supeng_dst = Mat::zeros(src.rows, src.cols, src.type());//������ ��� �̹��� ����(�ʱ�ȭ)
	Mat suzic_dst = Mat::zeros(src.rows, src.cols, src.type());//�������� ��� �̹��� ����(�ʱ�ȭ)

	//Ŀ�� ����

	//1)�ڽ�
	Mat box_kernel(Size(3, 3), CV_32F, Scalar(1.0 / Size(3, 3).area()));   //Ŀ�� �� ��� ȭ�Ұ��� ������ ����ġ�� ������
	//3����3��ľȿ� 1�� ��ü Ŀ�μ� 9�� ������ �ִ´� 1/9���� ��

	//filter2D�� ��������ϱ� �ڽ�_Ŀ�η� �߽��� �߾ӿ� �ΰ� ���� ����Ʈ�� src��������켭 box_dst�� ���
	//filter2D-> �Է°� �Է� ����� ũ��, ä�μ��� ������ ��� ����,-1�� ��� ������ ����(depth)�� �Է°� ����
	//box_kernel�� ������� ���ش�. Point(-1, -1)�� ����� ����ũ �߾� ȭ�ҿ� ��ȯ, �̹��� �׵θ��� BORDER_DEFAULT
	//filter2D�� ����ũ�� ����ũ�� �ش��ϴ� ȣ�Ұ��� ���ؼ� ���� ���� �װ� ��ȯ �Ѵ�(�������). 
	filter2D(src, box_dst, -1, box_kernel, Point(-1, -1), 0, BORDER_DEFAULT);
	         

	//2)����þ�
	float gau_k[] = {.0,.0,0.0002,.0,.0,  .0,.0113,.0837,.0113,.0,  .0002,.0837,.6187,.0837,.0002,  .0,.0113,.0837,.0113,.0,  .0,.0,.0002,.0,.0, };//����þ� ���� �ȿ� �� ������
	Mat  gauss_kernel(5, 5, CV_32FC1, gau_k);//5����5��ľȿ� gau_k�� ���� ����.
	//filter2D�� �Է�, ��� ������ �ް� gauss_kernel�� ������� �� ����� ����ũ �߾� ȭ�ҿ� ��ȯ�Ѵ�(Point(-1, -1)), �̹��� �׵θ��� BORDER_DEFAULT
	filter2D(src, gauss_dst, -1, gauss_kernel, Point(-1, -1), 0, BORDER_DEFAULT);

	//3)������
	float shar_k[] = {0.0,-1.0, 0.0,-1.0,5.0,-1.0,0.0,-1.0,0.0};//������ 3����3 ���Ϳ� �� ��
	Mat  sharpening_kernel(3, 3, CV_32FC1, shar_k);//3����3��ľȿ� shar_k�� ���� ����.
	//filter2D�� �Է�, ��� ������ �ް� sharpening_kernel�� ������� �� ����� ����ũ �߾� ȭ�ҿ� ��ȯ�Ѵ�(Point(-1, -1)), �̹��� �׵θ��� BORDER_DEFAULT
	filter2D(src, sharpen_dst, -1, sharpening_kernel, Point(-1, -1), 0, BORDER_DEFAULT);

	////4)������
	float supeng_k[] = {1.0,1.0 ,1.0, 0.0,0.0,0.0, -1.0,-1.0 ,-1.0 };//3����3 ���Ϳ� �� ��
	Mat  supeng_kernel(3, 3, CV_32FC1, supeng_k);//3����3 ���� ����
	//filter2D�� �Է�, ��� ������ �ް� supeng_kernel�� ������� �� ����� ����ũ �߾� ȭ�ҿ� ��ȯ�Ѵ�(Point(-1, -1)), �̹��� �׵θ��� BORDER_DEFAULT
	filter2D(src, supeng_dst, -1, supeng_kernel, Point(-1, -1), 0, BORDER_DEFAULT);

	////5)��������
	float suzic_k[] = { 1.0,0.0 ,-1.0, 1.0,0.0 ,-1.0, 1.0,0.0 ,-1.0};//3����3 ���Ϳ� �� ��
	Mat  suzic_kernel(3, 3, CV_32FC1, suzic_k);//3����3 ���� ����
	//filter2D�� �Է�, ��� ������ �ް� suzic_kernel�� ������� �� ����� ����ũ �߾� ȭ�ҿ� ��ȯ�Ѵ�(Point(-1, -1)), �̹��� �׵θ��� BORDER_DEFAULT
	filter2D(src, suzic_dst, -1, suzic_kernel, Point(-1, -1), 0, BORDER_DEFAULT);

	//6)���
	float motion_k[] = { 0.0304 ,0.0501,0.0,0.0 ,0.0,  0.0501,0.1771,0.0519,0.0,0.0,  0.0,0.0519,0.1771,0.0519,0.0,  0.0 ,0.0 ,0.0519 ,0.1771 ,0.0501,  0.0 ,0.0,0.0 ,0.0501,0.0304 };//��� ���Ϳ� �� ����ġ��
	Mat  motion_kernel(5, 5, CV_32FC1, motion_k);//5����5 ���� ����
	//filter2D�� �Է�, ��� ������ �ް� motion_kernel�� ������� �� ����� ����ũ �߾� ȭ�ҿ� ��ȯ�Ѵ�(Point(-1, -1)), �̹��� �׵θ��� BORDER_DEFAULT
	filter2D(src, motion_dst, -1, motion_kernel, Point(-1, -1), 0, BORDER_DEFAULT);
	
	imshow("���� �̹���", src);//�����̹��� ���
	imshow("�ڽ�", box_dst);//�ڽ��̹��� ���
	imshow("����þ�", gauss_dst);//����þ� �̹��� ���
	imshow("������", sharpen_dst);//������ �̹��� ���
	imshow("������", supeng_dst);//������ �̹��� ���
	imshow("��������", suzic_dst);//�������� �̹��� ���
	imshow("���", motion_dst);//��� �̹��� ���
	
	waitKey();
}