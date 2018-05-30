//
//  main.cpp
//  video
//
//  Created by 黄悦 on 08/04/2018.
//  Copyright © 2018 tyrion. All rights reserved.
//

#include <opencv2/opencv.hpp>

using namespace cv;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    
    namedWindow("frames",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
//        cvtColor(frame, edges, COLOR_BGR2GRAY);
//        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
//        Canny(edges, edges, 0, 30, 3);
        
        // get size
        int rows = frame.rows;
        int cols = frame.cols;
        // std::cout << rows << " * " << cols << "\n";

        imshow("frames", frame);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
