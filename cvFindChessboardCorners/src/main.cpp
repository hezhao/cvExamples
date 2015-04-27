//
//  main.cpp
//  cvFindChessboardCorners
//
//  Created by Zhao He on 4/27/15.
//  Copyright (c) 2015 Zhao He. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

// download circle grid pattern at
// http://nerian.com/products/sp1-stereo-vision/patterns/

int main(int argc, const char * argv[])
{
    Mat img;
    Mat gray;
    vector<Point2f> corners;
    string img_file = "asset/marker0.jpg";
    Size patternsize = Size(6, 9);
    
    // 1. read image and convert to grayscale
    img = imread(img_file);
    if (!img.data) {
        cerr << "Image not found!" << endl;
        return -1;
    }
    cvtColor(img, gray, CV_RGB2GRAY);
    
    // 2. find corners in checkerboard
    bool patternfound = findChessboardCorners( gray, patternsize, corners,
                                  CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FAST_CHECK | CV_CALIB_CB_NORMALIZE_IMAGE);
    
    // 3. draw corners on the image
    namedWindow( "Window", WINDOW_AUTOSIZE );
    drawChessboardCorners(img, patternsize, Mat(corners), patternfound);
    imshow("Window", img);

    // 4. output center coordinates
    cout << patternfound << endl << endl;
    for (auto c: corners) cout << c << endl;
    
    waitKey();
    return 0;
}
