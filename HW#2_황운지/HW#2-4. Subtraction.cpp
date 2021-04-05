//////////////////////////////////////////////////////////////
//                                                          //
//                         뺄셈 연산                        //
//                                                          //
//////////////////////////////////////////////////////////////
       

#include <opencv.hpp>

using namespace cv;
using namespace std;

int main(){
	Mat image1 = imread("C:/Users/happy/OneDrive/바탕 화면/!막학기최선다해/영상처리/화소값 기반 처리 Code/4.화소값기반처리/Fig0228(a)(angiography_mask_image).tif", IMREAD_GRAYSCALE);
	//이미지를 로드해서 mat클래스 안에 넣음
	Mat image2 = imread("C:/Users/happy/OneDrive/바탕 화면/!막학기최선다해/영상처리/화소값 기반 처리 Code/4.화소값기반처리/Fig0228(b)(angiography_live_ image).tif", IMREAD_GRAYSCALE);
	CV_Assert(!(image1.empty() || image2.empty()));

	double alpha = 0.6, beta = 0.7;

	Mat sub_img = abs(image2 - image1);//이미지1에서 이미지2를 빼면 비슷한건 사라지고 차이나는 것만 남음
	//비슷한 부분일수록 어두워짐
	imshow("image1", image1), imshow("image2", image2);//기존이미지 출력
	imshow("sub_img", sub_img);//변환한 것 출력
		
	waitKey(0);
}

