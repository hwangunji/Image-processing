//레나 이미지 가우시안 필터링하기
#include <opencv.hpp>

using namespace cv;
using namespace std;

void main()
{
	Mat src = imread("C:/Users/happy/OneDrive/바탕 화면/!막학기최선다해/영상처리/화소값 기반 처리 Code/4.화소값기반처리/lena.jpg", 1);//레나이미지 불러오기
	Mat dst = Mat::zeros(src.rows, src.cols, src.type());
	Mat dst2 = Mat::zeros(src.rows, src.cols, src.type());
	Mat dst3 = Mat::zeros(src.rows, src.cols, src.type());
	// dst, dst2,dst3= Mat::zeros(src.rows, src.cols, src.type()); 영상을 src 영상과 같은 크기, 같은 자료형, 0으로 초기화하여 생성 여기에 가우시안으로 필터링한 이미지 넣을것

	//가우시안 커널 필터 적용하기
	//가우시안 분포의 폭은 표준편차가 결정하는 데 이 값이 클수록 블러효과가 더 커짐(많은 저주파성분을 통과시켜서)

	//1.getGaussianKernel 사용하기
	//getGaussianKernel로 가우시안 표준 편차정하기 필터 타입은 CV_64F로 할것임
	//표준 편차가 sigma인 1차원 가우시안 분포 함수로부터 ksize×1 크기의 필터 마스크 행렬을 생성하여 반환
	//ksize는(6 * sigma)보다 크게 지정->(6*1.5)=9 그래서 ksize=9
	Mat gauss = getGaussianKernel(9, 1.5, CV_64F);//표준편차 1.5일때 
	//	gauss는 ksize×1크기

	Mat gauss2= gauss * gauss.t();//ksize×1,1차원이니까 곱해줘야해 filter2D를 위해 2차원으로 만들어
	//커널 정해 주었으니 이거로 필터링을 할것임 filter2D이용
	filter2D(src, dst,-1, gauss2, Point(-1, -1));//엣지는 디폴트값으로

	//2.GaussianBlur이용하기
	//getGaussianKernel의 표준편차 1.5로 했으니까 얘도 같은 효과를 위해 1.5표준편차로 하자
	GaussianBlur(src, dst2, Size(9, 9), 1.5, 1.5);//y축은 0으로 해도 시그마 값 1.5로 지정됨 그래도 1.5 써주자

	//표준편차가 커지면 효과가 클지 표준편차0.5으로 해서비교
	GaussianBlur(src, dst3, Size(3, 3), 0.5, 0.5);
	
	imshow("원래 레나", src);//원래이미지 출력
	imshow("getGaussianKernel적용 표준편차= 1.5", dst);//표준편차= 1.5 getGaussianKernel 출력
	imshow("GaussianBlur적용 표준편차= 1.5", dst2);//표준편차= 1.5 GaussianBlur 출력
	imshow("GaussianBlur적용 표준편차= 0.5", dst3);//표준편차= 0.5 GaussianBlur 출력

	waitKey();		
}