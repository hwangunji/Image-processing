//마스크로 컨볼루션 하기
#include <opencv.hpp>

using namespace cv;
using namespace std;

void main()
{
	Mat src = imread("C:\\Users\\happy\\OneDrive\\바탕 화면\\!막학기최선다해\\영상처리\\화소값 기반 처리 Code\\4.화소값기반처리\\Fig0327(a).jpg", IMREAD_GRAYSCALE);
	//이미지 불러오기 그레이 스케일 영상으로 

	Mat box_dst = Mat::zeros(src.rows, src.cols, src.type());//박스 결과 이미지 저장(초기화)
	Mat gauss_dst = Mat::zeros(src.rows, src.cols, src.type());//가우시안 결과 이미지 저장(초기화)
	Mat sharpen_dst = Mat::zeros(src.rows, src.cols, src.type());//샤프닝 결과 이미지 저장(초기화)
	Mat motion_dst = Mat::zeros(src.rows, src.cols, src.type());//모션 결과 이미지 저장(초기화)
	Mat supeng_dst = Mat::zeros(src.rows, src.cols, src.type());//수평에지 결과 이미지 저장(초기화)
	Mat suzic_dst = Mat::zeros(src.rows, src.cols, src.type());//수직에지 결과 이미지 저장(초기화)

	//커널 생성

	//1)박스
	Mat box_kernel(Size(3, 3), CV_32F, Scalar(1.0 / Size(3, 3).area()));   //커널 내 모든 화소값이 동일한 가중치를 가진다
	//3바이3행렬안에 1을 전체 커널수 9로 나눈걸 넣는다 1/9값이 들어가

	//filter2D로 컨볼루션하기 박스_커널로 중심은 중앙에 두고 계계는 디폴트로 src컨볼루션헤서 box_dst로 출력
	//filter2D-> 입력과 입력 영상과 크기, 채널수가 동일한 결과 영상,-1은 결과 영상의 깊이(depth)가 입력과 같음
	//box_kernel로 컨볼루션 해준다. Point(-1, -1)는 결과를 마스크 중앙 화소에 반환, 이미지 테두리는 BORDER_DEFAULT
	//filter2D는 마스크와 마스크에 해당하는 호소값을 곱해서 더한 다음 그걸 반환 한다(컨볼루션). 
	filter2D(src, box_dst, -1, box_kernel, Point(-1, -1), 0, BORDER_DEFAULT);
	         

	//2)가우시안
	float gau_k[] = {.0,.0,0.0002,.0,.0,  .0,.0113,.0837,.0113,.0,  .0002,.0837,.6187,.0837,.0002,  .0,.0113,.0837,.0113,.0,  .0,.0,.0002,.0,.0, };//가우시안 필터 안에 들어갈 값적기
	Mat  gauss_kernel(5, 5, CV_32FC1, gau_k);//5바이5행렬안에 gau_k의 값이 들어간다.
	//filter2D로 입력, 결과 영상을 받고 gauss_kernel로 컨볼루션 해 결과를 마스크 중앙 화소에 반환한다(Point(-1, -1)), 이미지 테두리는 BORDER_DEFAULT
	filter2D(src, gauss_dst, -1, gauss_kernel, Point(-1, -1), 0, BORDER_DEFAULT);

	//3)샤프닝
	float shar_k[] = {0.0,-1.0, 0.0,-1.0,5.0,-1.0,0.0,-1.0,0.0};//샤프닝 3바이3 필터에 들어갈 값
	Mat  sharpening_kernel(3, 3, CV_32FC1, shar_k);//3바이3행렬안에 shar_k의 값이 들어간다.
	//filter2D로 입력, 결과 영상을 받고 sharpening_kernel로 컨볼루션 해 결과를 마스크 중앙 화소에 반환한다(Point(-1, -1)), 이미지 테두리는 BORDER_DEFAULT
	filter2D(src, sharpen_dst, -1, sharpening_kernel, Point(-1, -1), 0, BORDER_DEFAULT);

	////4)수평에지
	float supeng_k[] = {1.0,1.0 ,1.0, 0.0,0.0,0.0, -1.0,-1.0 ,-1.0 };//3바이3 필터에 들어갈 값
	Mat  supeng_kernel(3, 3, CV_32FC1, supeng_k);//3바이3 필터 생성
	//filter2D로 입력, 결과 영상을 받고 supeng_kernel로 컨볼루션 해 결과를 마스크 중앙 화소에 반환한다(Point(-1, -1)), 이미지 테두리는 BORDER_DEFAULT
	filter2D(src, supeng_dst, -1, supeng_kernel, Point(-1, -1), 0, BORDER_DEFAULT);

	////5)수직에지
	float suzic_k[] = { 1.0,0.0 ,-1.0, 1.0,0.0 ,-1.0, 1.0,0.0 ,-1.0};//3바이3 필터에 들어갈 값
	Mat  suzic_kernel(3, 3, CV_32FC1, suzic_k);//3바이3 필터 생성
	//filter2D로 입력, 결과 영상을 받고 suzic_kernel로 컨볼루션 해 결과를 마스크 중앙 화소에 반환한다(Point(-1, -1)), 이미지 테두리는 BORDER_DEFAULT
	filter2D(src, suzic_dst, -1, suzic_kernel, Point(-1, -1), 0, BORDER_DEFAULT);

	//6)모션
	float motion_k[] = { 0.0304 ,0.0501,0.0,0.0 ,0.0,  0.0501,0.1771,0.0519,0.0,0.0,  0.0,0.0519,0.1771,0.0519,0.0,  0.0 ,0.0 ,0.0519 ,0.1771 ,0.0501,  0.0 ,0.0,0.0 ,0.0501,0.0304 };//모션 필터에 들어갈 가중치들
	Mat  motion_kernel(5, 5, CV_32FC1, motion_k);//5바이5 필터 생성
	//filter2D로 입력, 결과 영상을 받고 motion_kernel로 컨볼루션 해 결과를 마스크 중앙 화소에 반환한다(Point(-1, -1)), 이미지 테두리는 BORDER_DEFAULT
	filter2D(src, motion_dst, -1, motion_kernel, Point(-1, -1), 0, BORDER_DEFAULT);
	
	imshow("원래 이미지", src);//원래이미지 출력
	imshow("박스", box_dst);//박스이미지 출력
	imshow("가우시안", gauss_dst);//가우시안 이미지 출력
	imshow("샤프닝", sharpen_dst);//샤프닝 이미지 출력
	imshow("수평에지", supeng_dst);//수평에지 이미지 출력
	imshow("수직에지", suzic_dst);//수직에지 이미지 출력
	imshow("모션", motion_dst);//모션 이미지 출력
	
	waitKey();
}