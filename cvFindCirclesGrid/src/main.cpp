//
//  main.cpp
//  cvFindCirclesGrid
//
//  Created by Zhao He on 4/24/15.
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
    vector<Point2f> centers;
    string img_file = "asset/marker0.jpg";
    Size patternsize = cv::Size(4, 11);
    
    // 1. read image and convert to grayscale
    img = imread(img_file);
    cvtColor(img, gray, CV_RGB2GRAY);
    
    // 2. find centers in asymmetric circle grid
    bool patternfound = findCirclesGrid(gray, patternsize, centers, CALIB_CB_ASYMMETRIC_GRID);
    
    // 3. draw centers on the image
    namedWindow( "window", WINDOW_AUTOSIZE );
    cv::drawChessboardCorners(img, patternsize, cv::Mat(centers), patternfound);
    imshow("window", img);

    // 4. output center coordinates
    cout << patternfound << endl << endl;
    for (auto c: centers) cout << c << endl;
    
    waitKey();
    return 0;
}
