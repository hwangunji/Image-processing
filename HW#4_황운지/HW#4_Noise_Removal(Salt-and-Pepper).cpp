//후추소금잡음 지우기
#include <opencv.hpp>

using namespace cv;
using namespace std;

void main()
{
	Mat src = imread("C:\\Users\\happy\\OneDrive\\바탕 화면\\!막학기최선다해\\영상처리\\화소값 기반 처리 Code\\4.화소값기반처리\\lena.jpg",IMREAD_GRAYSCALE);//레나이미지 흑백 으로불러오기
	Mat dst = Mat::zeros(src.rows, src.cols, src.type());//평균필터 
	Mat dst1 = Mat::zeros(src.rows, src.cols, src.type());//가우시안 
	Mat dst2 = Mat::zeros(src.rows, src.cols, src.type());//중앙값 
	// dst,dst1,dst2= Mat::zeros(src.rows, src.cols, src.type()); 영상을 src 영상과 같은 크기, 같은 자료형, 0으로 초기화하여 생성 여기에 잡음 제거 이미지 넣을것

	//원래 이미지에 후추 소금 잡음 뿌리기 (5%)
	int zabem = (int)(src.total() * 0.05);//전체 픽셀중에 5%만큼 잡음 생성할 거야

	for (int i = 0; i < zabem; i++) {//잡음 개수만큼
		int x = rand() % src.cols;//이미지의 cols중에서 무작위로 골라
		int y = rand() % src.rows;//이미지의 rows중에서 무작위로 골라
		src.at<uchar>(y, x) = (i % 2) * 255;//고른 화소값을 잡음으로 생성
	}

	//kernel 3바이3 
	//1.평균필터 적용Averaging
	//Point (-1, -1),kernel (filter)에서 가운데를 중심으로 적용
	blur(src, dst, Size(3, 3), Point(-1, -1));

	//2.가우시안 필터 적용
	GaussianBlur(src, dst1, Size(3,3), 1);

	//3.중앙값 필터 적용
	medianBlur(src, dst2, 3);
	
	imshow("후추 레나", src);//잡음이미지 출력
	imshow("평균필터 적용", dst);//평균필터 적용 이미지 출력
	imshow("가우시안 필터 적용", dst1);//가우시안필터 적용 이미지 출력
	imshow("중앙값 필터 적용", dst2);//중앙값필터 적용 이미지 출력

	waitKey();
}