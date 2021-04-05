//////////////////////////////////////////////////////////////
//                                                          //
//                        감마 조절                         //
//                                                          //
//      지수의 값에 의해 다양하게 입력영상을 변환           //
//                                                          // 
//                   s= T(r) = (r)^p                        //
//                                                          //   
//////////////////////////////////////////////////////////////

// p=1 : 입력 r과 s가 동일
// p<1 : 로그변환과 유사
// p>1 : 역로그(inverse log) 변환과 유사


#include <opencv.hpp>

using namespace cv;


void main()
{
	Mat srcImage = imread("C:\\Users\\happy\\OneDrive\\바탕 화면\\!막학기최선다해\\영상처리\\화소값 기반 처리 Code\\4.화소값기반처리\\Fig0308(a)(fractured_spine).tif");
	//이미지를 로드해서 mat클래스 안에 넣음
	Mat fImage;//mat클래스로 영상처리하는 자료구조 생성
	srcImage.convertTo(fImage, CV_32F);// 자료형 CV_32F 이유:power 자료형이 double

	double power = 0.4;  // 0.4 = 1/2.5 밝아짐
	Mat powImage;//powImage 객체 선언
	pow(fImage, power, powImage);//pow함수를 이용하여 각 픽셀에 거듭제곱을 취하여 영상을 변환 
	// 거듭제곱변환 : powImage = fImage ^ power
	normalize(powImage, powImage, 0, 1.0, NORM_MINMAX);   // 0~1사이로 정규화


	double power1 = 0.7;//0<r<1 더 밝아짐
	Mat powImage1;//powImage1 객체 선언
	pow(powImage, power1, powImage1);   // 모니터에 나타나는 밝기
	// 거듭제곱변환 : powImage1 = powImage ^ power1 밝아진 이미지 더 밝게

	normalize(powImage1, powImage1, 0, 1.0, NORM_MINMAX);// 0~1사이로 정규화

	double power2 = 0.8;//0<r<1 더 더 밝아짐
	Mat powImage2;//powImage2 객체 선언
	pow(powImage1, power2, powImage2);
	// 거듭제곱변환 : powImage2 = powImage1 ^ power2 더 밝아진 이미지 더 밝게

	normalize(powImage2, powImage2, 0, 1.0, NORM_MINMAX);// 0~1사이로 정규화

	
	imshow("src", srcImage);//원래이미지 출력
	imshow("pow", powImage);//밝아진 이미지 출력
	imshow("pow1", powImage1);//더 밝아진 이미지 출력
	imshow("pow2", powImage2);//더 더 밝아진 이미지 출력

	waitKey(0);
}