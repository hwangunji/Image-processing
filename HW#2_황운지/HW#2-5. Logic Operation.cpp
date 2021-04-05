#include "opencv2/opencv.hpp"
#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image1 = imread("C:/Users/happy/OneDrive/���� ȭ��/!���б��ּ�����/����ó��/ȭ�Ұ� ��� ó�� Code/4.ȭ�Ұ����ó��/Fig0230(a)(dental_xray).tif", CV_8UC1);
    //�̹����� �ε��ؼ� matŬ���� �ȿ� ����
    Mat image2 = imread("C:/Users/happy/OneDrive/���� ȭ��/!���б��ּ�����/����ó��/ȭ�Ұ� ��� ó�� Code/4.ȭ�Ұ����ó��/Fig0230(b)(dental_xray_mask).tif", CV_8UC1);
    //�̹����� �ε��ؼ� matŬ���� �ȿ� ����(����ũ�̹���)

    imshow("Image 1", image1);//�����̹������
    imshow("Image 2", image2);//����ũ�̹��� ���

    Mat res;//����ũ ���� �̹��� ������ matŬ��������

    // AND ����
    bitwise_and(image1, image2, res);
    //�����̹����� ����ũ�̹����� �����ؼ� res�� ����
    imshow("AND", res);//res���

    waitKey(0);

    return 0;
}
