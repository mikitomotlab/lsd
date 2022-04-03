#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cassert>
#include <chrono>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
//#include <lsd.h>
#include "lsdvcpp.h"
#include <time.h>

#include <opencv2/opencv.hpp>
#include <C:\dev\opencv-3.2.0\include\opencv\highgui.h> 

#pragma comment(lib, "opencv_highgui343.lib")
//#pragma comment(lib, "C:\Program Files (x86)\Windows Phone Kits\8.0\Include\ws2_32.lib")

int n_lines;
double* lines;
//#ifdef __cplusplus
//extern "C"
//{
//#endif
//	cv::Mat image = cv::imread("image.png", 1);
//#ifdef __cplusplus
//}
//#endif


int main()
{
	cv::Mat image = cv::imread("image.png",1); 
	//cv::Mat image(480, 270, CV_32F, img);
	//cv::imshow("sensingimage", image);
	//cv::waitKey(5000);
	//cv::imwrite("D:\\dev\\workspace\\UMap\\SEN\\PiCA\\1.img\\'+ rcvmsg+'.jpg", image);

	//LSD�p�摜�ɕϊ�����
	double *dat = new double[image.rows * image.cols];
	for (int y = 0; y < image.rows; y++)
		for (int x = 0; x < image.cols; x++)
			dat[y * image.cols + x] = image.at<unsigned char>(y, x);

	//LSD����
	lines = lsd(&n_lines, dat, image.cols, image.rows);

	//�������l�̍ő�l�ƍŏ��l�������Ă���
	int max_NFA = 0;
	for (int i = 0; i < n_lines; i++)
		max_NFA = std::max(max_NFA, static_cast<int>(lines[i * 7 + 6]));

	//���ʕ`��p�摜
	//cv::cvtColor(img, image, CV_GRAY2RGB);

	//���ʕ\���p�E�B���h�E
	cv::namedWindow("result_image");
	//cv::createTrackbar("NFA", "result_image", NULL, max_NFA, change_th_lsd);
	cv::setTrackbarPos("NFA", "result_image", max_NFA);

	//���ʕ\��
	cv::imshow("result_image", image);
	cv::waitKey(0);


		

	}



