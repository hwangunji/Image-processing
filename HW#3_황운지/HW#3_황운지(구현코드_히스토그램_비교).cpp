#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	//���� �̹��� 2�� �ε�
	Mat srcImage1 = imread("C:/Users/happy/OneDrive/���� ȭ��/!���б��ּ�����/����ó��/ȭ�Ұ� ��� ó�� Code/4.ȭ�Ұ����ó��/imageEq1.jpg", IMREAD_GRAYSCALE); 
	Mat srcImage2 = imread("C:/Users/happy/OneDrive/���� ȭ��/!���б��ּ�����/����ó��/ȭ�Ұ� ��� ó�� Code/4.ȭ�Ұ����ó��/imageEq2.jpg", IMREAD_GRAYSCALE);

	int histSize = 256;
	float valueRange[] = { 0, 256 };//0~255���� ����
	const float* ranges[] = { valueRange };
	int channels = 0;//ä�ξ���
	int dims = 1;//1����

	Mat H1, H2;//�̹����� ���� ������׷� ����
	//srcImage1 ������׷� H1�� ����
	calcHist(&srcImage1, 1, &channels, Mat(), H1, dims, &histSize, ranges);
	//������ �̹������� ������ �׷��� ����ؼ� hist�� ��ȯ��
	normalize(H1, H1, 1, 0, NORM_L1, CV_32F);// 0~1���̷� ����ȭ(�ʹ� �󵵰� ���̳��� �ȵǴϱ�)
	//srcImage2 ������׷� H2�� ����
	calcHist(&srcImage2, 1, &channels, Mat(), H2, dims, &histSize, ranges);
	normalize(H2, H2, 1, 0, NORM_L1, CV_32F);// 0~1���̷� ����ȭ(�ʹ� �󵵰� ���̳��� �ȵǴϱ�)

	double dist1 = compareHist(H1, H2, HISTCMP_CORREL); //CV_COMP_CORREL
	//compareHist:������׷��� �񱳸��ؼ� �󸶳� �������� ���� �Լ� ���� ���� ����� ������ ������ �˻��� �� ����
	//�ΰ��� ������׷� H1�� H2�� HISTCMP_CORREL(���밪�� ũ�� ����)������� ���Ͽ� d(H1,H2)��ȯ
	double dist2 = compareHist(H1, H2, HISTCMP_CHISQR); //CV_COMP_CHISQR ���� ������ ����
	double dist3 = compareHist(H1, H2, HISTCMP_INTERSECT); //CV_COMP_INTERSECT ���� ũ�� ����
	double dist4 = compareHist(H1, H2, HISTCMP_BHATTACHARYYA); //CV_COMP_BHATTACHARYYA ���� ������ ����

	cout << "dist1=" << dist1 << endl;
	cout << "dist2=" << dist2 << endl;
	cout << "dist3=" << dist3 << endl;
	cout << "dist4=" << dist4 << endl;
}
 
