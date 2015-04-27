//
//  main.cpp
//  cvBasic
//
//  Created by Zhao He on 4/24/15.
//  Copyright (c) 2015 Zhao He. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[])
{
    Mat src = imread("asset/marker0.jpg");
    Mat dst = src.clone();
    GaussianBlur( src, dst, Size( 15, 15 ), 0, 0 );
    
    namedWindow("window 1", WINDOW_AUTOSIZE);
    imshow("window 1", src);

    namedWindow("window 2", WINDOW_AUTOSIZE);
    imshow("window 2", dst);

    waitKey();
    return 0;
}
