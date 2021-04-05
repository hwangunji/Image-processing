#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

uchar computeOutput(uchar x, int r1, int s1, int r2, int s2);
//unsinged char 반환형

int main() {
	Mat src = imread("C:\\Users\\happy\\OneDrive\\바탕 화면\\!막학기최선다해\\영상처리\\화소값 기반 처리 Code\\4.화소값기반처리\\Fig0310(b)(washed_out_pollen_image).tif", 0);
	//이미지를 로드해서 mat클래스 안에 넣음(컬러영상 그대로)
	Mat newImage1 = src.clone();//빈 영상인 newImage1에 src의 복사본이 생성된후 대입됨
	Mat newImage2;//mat클래스 자료구조 생성
	int s,s_2;
	int r1, s1, r2, s2;
	//r1, s1, r2, s2 입력하기
	cout << " r1: " << endl; cin >> r1;
	cout << " s1: " << endl; cin >> s1;
	cout << " r2: " << endl; cin >> r2;
	cout << " s2: " << endl; cin >> s2;

	for (int x = 0; x < src.rows; x++) {
		for (int y = 0; y < src.cols; y++) {//이미지 각 픽셀마다
			s = computeOutput(src.at<uchar>(x, y), r1, s1, r2, s2);
			//src.at<uchar>(x, y) 좌표에 있는 픽셀의 B, G, R 데이터를 반환
			newImage1.at<uchar>(x, y) = saturate_cast<uchar>(s);
			//saturate_cast uchar 자료형을 변환한 값이 자료형의 표현 범위안에 있도록 함
		}
	}

	newImage2 = newImage1.clone();

	for (int q = 0; q < newImage1.rows; q++) {
		for (int w = 0; w < newImage1.cols; w++) {//이미지 각 픽셀마다
			s_2 = computeOutput(newImage1.at<uchar>(q, w), r1, s1, r2, s2);
			//src.at<uchar>(x, y) 좌표에 있는 픽셀의 B, G, R 데이터를 반환
			newImage2.at<uchar>(q, w) = saturate_cast<uchar>(s_2);
			//saturate_cast uchar 자료형을 변환한 값이 자료형의 표현 범위안에 있도록 함
		}
	}

	imshow("src", src);//원래이미지 출력
	imshow("result1", newImage1);
	imshow("result2", newImage2);
	waitKey(0);
	return 0;
}



uchar computeOutput(uchar x, int r1, int s1, int r2, int s2) {
	uchar result = 0;
	
	if (0 <= x && x <= r1) {//0부터 r1까지
		result = s1 / r1 * x;//기울기 s1 / r1 
	}
	else if (r1 < x && x <= r2) {//r1부터 r2까지
		result = ((s2 - s1) / (r2 - r1)) * (x - r1) + s1;
	}
	else if (r2 < x && x <= 255) {//r2이상
		result = ((255 - s2) / (255 - r2)) * (x - r2) + s2;//기울기(255 - s2) / (255 - r2) 평행이동 s2
	}
	
	return result;
}