#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	//비교할 이미지 2개 로드
	Mat srcImage1 = imread("C:/Users/happy/OneDrive/바탕 화면/!막학기최선다해/영상처리/화소값 기반 처리 Code/4.화소값기반처리/imageEq1.jpg", IMREAD_GRAYSCALE); 
	Mat srcImage2 = imread("C:/Users/happy/OneDrive/바탕 화면/!막학기최선다해/영상처리/화소값 기반 처리 Code/4.화소값기반처리/imageEq2.jpg", IMREAD_GRAYSCALE);

	int histSize = 256;
	float valueRange[] = { 0, 256 };//0~255까지 계산됨
	const float* ranges[] = { valueRange };
	int channels = 0;//채널없음
	int dims = 1;//1차원

	Mat H1, H2;//이미지에 대한 히스토그램 생성
	//srcImage1 히스토그램 H1에 저장
	calcHist(&srcImage1, 1, &channels, Mat(), H1, dims, &histSize, ranges);
	//지정된 이미지에서 히스토 그램을 계산해서 hist로 반환함
	normalize(H1, H1, 1, 0, NORM_L1, CV_32F);// 0~1사이로 정규화(너무 빈도가 차이나면 안되니까)
	//srcImage2 히스토그램 H2에 저장
	calcHist(&srcImage2, 1, &channels, Mat(), H2, dims, &histSize, ranges);
	normalize(H2, H2, 1, 0, NORM_L1, CV_32F);// 0~1사이로 정규화(너무 빈도가 차이나면 안되니까)

	double dist1 = compareHist(H1, H2, HISTCMP_CORREL); //CV_COMP_CORREL
	//compareHist:히스토그램의 비교를해서 얼마나 유사한지 보는 함수 내가 가진 영상과 유사한 영상을 검색할 떄 유용
	//두개의 히스토그램 H1과 H2를 HISTCMP_CORREL(절대값이 크면 유사)방법으로 비교하여 d(H1,H2)반환
	double dist2 = compareHist(H1, H2, HISTCMP_CHISQR); //CV_COMP_CHISQR 값이 작으면 유사
	double dist3 = compareHist(H1, H2, HISTCMP_INTERSECT); //CV_COMP_INTERSECT 값이 크면 유사
	double dist4 = compareHist(H1, H2, HISTCMP_BHATTACHARYYA); //CV_COMP_BHATTACHARYYA 값이 작으면 유사

	cout << "dist1=" << dist1 << endl;
	cout << "dist2=" << dist2 << endl;
	cout << "dist3=" << dist3 << endl;
	cout << "dist4=" << dist4 << endl;
}
 
