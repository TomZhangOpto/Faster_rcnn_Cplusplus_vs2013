#include <iostream>
#include "Caffe_Net.h"
using namespace std;

//matlab model and net prototxt file .
const string rpn_prototxt_file = "./models/proposal_test.prototxt";
const string rpn_model_file = "./models/proposal_final";
const string fcnn_prototxt_file = "./models/detection_test.prototxt";
const string fcnn_model_file = "./models/detection_final";

//mean_image.bmp is convert from the model.mat  in  matlab model directory 
//you can save mean_image by command  imwrite(uint8(proposal_detection_model.image_means),"mean_image.bmp")
const string mean_image_file = "./models/mean_image.bmp";



int main(){

	Caffe_Net net_(rpn_prototxt_file, rpn_model_file, fcnn_prototxt_file, fcnn_model_file, mean_image_file);
	string test_file = "./test/test.jpg";
	Mat img = imread(test_file.c_str());
	if (img.empty()){
		cout << "input image error;";
		return -1;
	}
	Mat dst = net_.fasterrcnn(img);
	imshow("showImage", dst);
	cvWaitKey(0);
	return 0;
}