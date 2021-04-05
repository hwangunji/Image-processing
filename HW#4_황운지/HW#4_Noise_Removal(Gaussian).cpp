//가우시안 잡음 지우기
#include <opencv.hpp>

using namespace cv;
using namespace std;

void main()
{
	Mat src = imread("C:\\Users\\happy\\OneDrive\\바탕 화면\\!막학기최선다해\\영상처리\\화소값 기반 처리 Code\\4.화소값기반처리\\lena.jpg", IMREAD_GRAYSCALE);//레나이미지 흑백 으로불러오기
	Mat dst = Mat::zeros(src.rows, src.cols, src.type());//잡음 이미지 
	Mat dst3 = Mat::zeros(src.rows, src.cols, src.type());//중앙값 
	Mat dst1 = Mat::zeros(src.rows, src.cols, src.type());//평균필터 
	Mat dst2 = Mat::zeros(src.rows, src.cols, src.type());//가우시안 
	// dst,dst1,dst2= Mat::zeros(src.rows, src.cols, src.type()); 영상을 src 영상과 같은 크기, 같은 자료형, 0으로 초기화하여 생성 여기에 잡음 제거 이미지 넣을것

	//원래 이미지에 가우시안 잡음 뿌리기
	int stddev = 20;//표준 편차 stddev 값 20으로
	Mat noise(src.size(), CV_32SC1);//평균이 0이고 표준 편차가 stddev인 가우시안 잡음을 생성하여 noise 행렬에 저장
	//평균이 0인 가우시안 잡음을 생성할 경우 양수와 음수가 섞여 있는 난수가 발생하므로 부호 있는 자료형 행렬을 사용해야함
	//noise 행렬은 부호 있는 정수형(CV_32SC1)을 사용
	randn(noise, 0, stddev);//noise 행렬을 randn() 함수에 전달

	add(src, noise, dst, Mat(), CV_8U);//잡음+원래 영상, 입력 영상 src에 가우시안 잡음 noise를 더하여 결과 영상 dst를 생성

	imshow("가우시안 노이즈 영상", dst);//잡음+원래 영상을 출력

	//kernel 7바이7
	//1.평균필터 적용Averaging Point(-1,-1)
	blur(dst, dst1, Size(7,7),Point(-1,-1));

	//2.가우시안 필터 적용
	GaussianBlur(dst, dst2, Size(7, 7),1.1,1.1);

	//3.중앙값 필터 적용
	medianBlur(dst, dst3, 7);

	imshow("평균필터 적용", dst1);//평균필터 적용 이미지 출력
	imshow("가우시안 필터 적용", dst2);//가우시안필터 적용 이미지 출력
	imshow("중앙값 필터 적용", dst3);//중앙값필터 적용 이미지 출력
	
	waitKey();
}