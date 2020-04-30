//
// Created by wangheng on 4/28/20.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

void draw_point(Mat &mat, int x, int y) {
    int left_x, right_x, top_y, end_y;
    left_x = (x - 2) >= 0 ? (x - 2) : 0;
    top_y = (y - 2) >= 0 ? (y - 2) : 0;
    
    right_x = (x+2)>=mat.size().width?mat.size().width:(x+2);
    end_y = (y+2)>=mat.size().height?mat.size().height:(y+2);
    
    for(int i = top_y;i<end_y;i++){
        for(int j = left_x;j<right_x;j++){
            mat.at<uchar>(Point(j, i)) = 255;
        }
    }
}

int main() {
    Mat img = Mat::zeros(500, 500, CV_8U);
//    circle(img, Point(50, 50), 20, Scalar(255, 0, 0));
//    imshow("demo", img);
    draw_point(img, 100, 300);
    cout<<img.size<<endl;
    imshow("paint", img);
    waitKey(0);
    destroyAllWindows();
    return 0;
}

