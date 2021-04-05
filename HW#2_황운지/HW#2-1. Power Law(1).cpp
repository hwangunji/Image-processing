//////////////////////////////////////////////////////////////
//                                                          //
//                        ���� ����                         //
//                                                          //
//      ������ ���� ���� �پ��ϰ� �Է¿����� ��ȯ           //
//                                                          // 
//                   s= T(r) = (r)^p                        //
//                                                          //   
//////////////////////////////////////////////////////////////

// p=1 : �Է� r�� s�� ����
// p<1 : �α׺�ȯ�� ����
// p>1 : ���α�(inverse log) ��ȯ�� ����


#include <opencv.hpp>

using namespace cv;


void main()
{
	Mat srcImage = imread("C:\\Users\\happy\\OneDrive\\���� ȭ��\\!���б��ּ�����\\����ó��\\ȭ�Ұ� ��� ó�� Code\\4.ȭ�Ұ����ó��\\Fig0308(a)(fractured_spine).tif");
	//�̹����� �ε��ؼ� matŬ���� �ȿ� ����
	Mat fImage;//matŬ������ ����ó���ϴ� �ڷᱸ�� ����
	srcImage.convertTo(fImage, CV_32F);// �ڷ��� CV_32F ����:power �ڷ����� double

	double power = 0.4;  // 0.4 = 1/2.5 �����
	Mat powImage;//powImage ��ü ����
	pow(fImage, power, powImage);//pow�Լ��� �̿��Ͽ� �� �ȼ��� �ŵ������� ���Ͽ� ������ ��ȯ 
	// �ŵ�������ȯ : powImage = fImage ^ power
	normalize(powImage, powImage, 0, 1.0, NORM_MINMAX);   // 0~1���̷� ����ȭ


	double power1 = 0.7;//0<r<1 �� �����
	Mat powImage1;//powImage1 ��ü ����
	pow(powImage, power1, powImage1);   // ����Ϳ� ��Ÿ���� ���
	// �ŵ�������ȯ : powImage1 = powImage ^ power1 ����� �̹��� �� ���

	normalize(powImage1, powImage1, 0, 1.0, NORM_MINMAX);// 0~1���̷� ����ȭ

	double power2 = 0.8;//0<r<1 �� �� �����
	Mat powImage2;//powImage2 ��ü ����
	pow(powImage1, power2, powImage2);
	// �ŵ�������ȯ : powImage2 = powImage1 ^ power2 �� ����� �̹��� �� ���

	normalize(powImage2, powImage2, 0, 1.0, NORM_MINMAX);// 0~1���̷� ����ȭ

	
	imshow("src", srcImage);//�����̹��� ���
	imshow("pow", powImage);//����� �̹��� ���
	imshow("pow1", powImage1);//�� ����� �̹��� ���
	imshow("pow2", powImage2);//�� �� ����� �̹��� ���

	waitKey(0);
}