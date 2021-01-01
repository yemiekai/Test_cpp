#include <opencv2/opencv.hpp>
#include <iostream>  
#include <fstream>  
#include <stdio.h>
#include <stdlib.h>

// using namespace cv;
using namespace std;


#include "include/utils.h"

// 雷达相关
#include "include/radar.h"

// 其它项目内测试
#include "include/testInclude.h"

// #include "include/calibrate.h"

int main(int argc,char** agrv){
	main_aprilTagCalibrate_demo(argc, agrv);
	// main_fisheyeCorrect();
	return 0;
}