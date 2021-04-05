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
	Mat srcImage = imread("C:/Users/happy/OneDrive/���� ȭ��/!���б��ּ�����/����ó��/ȭ�Ұ� ��� ó�� Code/4.ȭ�Ұ����ó��/Fig0309(a)(washed_out_aerial_image).tif");
	//�̹����� �ε��ؼ� matŬ���� �ȿ� ����
	Mat fImage;//matŬ������ ����ó���ϴ� �ڷᱸ�� ����
	srcImage.convertTo(fImage, CV_32F);// �ڷ��� CV_32F ����:power �ڷ����� double

	double power = 2.4;  // r>1 ��ο���
	Mat powImage;//powImage ��ü ����
	pow(fImage, power, powImage);//pow�Լ��� �̿��Ͽ� �� �ȼ��� �ŵ������� ���Ͽ� ������ ��ȯ 
	// �ŵ�������ȯ : powImage = fImage ^ power
	normalize(powImage, powImage, 0, 1.0, NORM_MINMAX);   // 0~1���̷� ����ȭ


	double power1 = 1.5;//r>1 �� ��ο���
	Mat powImage1;//powImage1 ��ü ����
	pow(powImage, power1, powImage1);   // ����Ϳ� ��Ÿ���� ���
	// �ŵ�������ȯ : powImage1 = powImage ^ power1 ��ο��� �̹��� �� ��Ӱ�

	normalize(powImage1, powImage1, 0, 1.0, NORM_MINMAX);// 0~1���̷� ����ȭ

	double power2 = 1.2;//r>1 ���� ��ο���
	Mat powImage2;//powImage2 ��ü ����
	pow(powImage1, power2, powImage2);
	// �ŵ�������ȯ : powImage2 = powImage1 ^ power2 �� ��ο��� �̹���(powImage1) �� ��Ӱ�(power2)

	normalize(powImage2, powImage2, 0, 1.0, NORM_MINMAX);// 0~1���̷� ����ȭ

	
	imshow("src", srcImage);//�����̹��� ���
	imshow("pow", powImage);//��ο��� �̹��� ���
	imshow("pow1", powImage1);//�� ��ο��� �̹��� ���
	imshow("pow2", powImage2);//�� �� ��ο��� �̹��� ���

	waitKey(0);
}