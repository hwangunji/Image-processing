#include "opencv2/opencv.hpp"
#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image1 = imread("C:/Users/happy/OneDrive/바탕 화면/!막학기최선다해/영상처리/화소값 기반 처리 Code/4.화소값기반처리/Fig0230(a)(dental_xray).tif", CV_8UC1);
    //이미지를 로드해서 mat클래스 안에 넣음
    Mat image2 = imread("C:/Users/happy/OneDrive/바탕 화면/!막학기최선다해/영상처리/화소값 기반 처리 Code/4.화소값기반처리/Fig0230(b)(dental_xray_mask).tif", CV_8UC1);
    //이미지를 로드해서 mat클래스 안에 넣음(마스크이미지)

    imshow("Image 1", image1);//원래이미지출력
    imshow("Image 2", image2);//마스크이미지 출력

    Mat res;//마스크 씌운 이미지 저장할 mat클래스선언

    // AND 연산
    bitwise_and(image1, image2, res);
    //원래이미지랑 마스크이미지랑 연산해서 res에 저장
    imshow("AND", res);//res출력

    waitKey(0);

    return 0;
}
