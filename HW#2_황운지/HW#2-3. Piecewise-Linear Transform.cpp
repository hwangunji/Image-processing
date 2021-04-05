#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

uchar computeOutput(uchar x, int r1, int s1, int r2, int s2);
//unsinged char ��ȯ��

int main() {
	Mat src = imread("C:\\Users\\happy\\OneDrive\\���� ȭ��\\!���б��ּ�����\\����ó��\\ȭ�Ұ� ��� ó�� Code\\4.ȭ�Ұ����ó��\\Fig0310(b)(washed_out_pollen_image).tif", 0);
	//�̹����� �ε��ؼ� matŬ���� �ȿ� ����(�÷����� �״��)
	Mat newImage1 = src.clone();//�� ������ newImage1�� src�� ���纻�� �������� ���Ե�
	Mat newImage2;//matŬ���� �ڷᱸ�� ����
	int s,s_2;
	int r1, s1, r2, s2;
	//r1, s1, r2, s2 �Է��ϱ�
	cout << " r1: " << endl; cin >> r1;
	cout << " s1: " << endl; cin >> s1;
	cout << " r2: " << endl; cin >> r2;
	cout << " s2: " << endl; cin >> s2;

	for (int x = 0; x < src.rows; x++) {
		for (int y = 0; y < src.cols; y++) {//�̹��� �� �ȼ�����
			s = computeOutput(src.at<uchar>(x, y), r1, s1, r2, s2);
			//src.at<uchar>(x, y) ��ǥ�� �ִ� �ȼ��� B, G, R �����͸� ��ȯ
			newImage1.at<uchar>(x, y) = saturate_cast<uchar>(s);
			//saturate_cast uchar �ڷ����� ��ȯ�� ���� �ڷ����� ǥ�� �����ȿ� �ֵ��� ��
		}
	}

	newImage2 = newImage1.clone();

	for (int q = 0; q < newImage1.rows; q++) {
		for (int w = 0; w < newImage1.cols; w++) {//�̹��� �� �ȼ�����
			s_2 = computeOutput(newImage1.at<uchar>(q, w), r1, s1, r2, s2);
			//src.at<uchar>(x, y) ��ǥ�� �ִ� �ȼ��� B, G, R �����͸� ��ȯ
			newImage2.at<uchar>(q, w) = saturate_cast<uchar>(s_2);
			//saturate_cast uchar �ڷ����� ��ȯ�� ���� �ڷ����� ǥ�� �����ȿ� �ֵ��� ��
		}
	}

	imshow("src", src);//�����̹��� ���
	imshow("result1", newImage1);
	imshow("result2", newImage2);
	waitKey(0);
	return 0;
}



uchar computeOutput(uchar x, int r1, int s1, int r2, int s2) {
	uchar result = 0;
	
	if (0 <= x && x <= r1) {//0���� r1����
		result = s1 / r1 * x;//���� s1 / r1 
	}
	else if (r1 < x && x <= r2) {//r1���� r2����
		result = ((s2 - s1) / (r2 - r1)) * (x - r1) + s1;
	}
	else if (r2 < x && x <= 255) {//r2�̻�
		result = ((255 - s2) / (255 - r2)) * (x - r2) + s2;//����(255 - s2) / (255 - r2) �����̵� s2
	}
	
	return result;
}