//
//  main.cpp
//  video
//
//  Created by 黄悦 on 08/04/2018.
//  Copyright © 2018 tyrion. All rights reserved.
//

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

VideoCapture getCaptureFromIndexOrIp(const string str) {
    if ( str == "0" || str == "1") {
        // use camera index
        int camera_id = atoi(str.c_str());
        cout << "camera index: " << camera_id << endl;
        VideoCapture camera(camera_id);
        return camera;
    } else {
        string camera_ip = str;
        cout << "camera ip: " << camera_ip << endl;
        string camera_stream = "rtsp://admin:mcd12345678@" + camera_ip + ":554//Streaming/Channels/1";
        VideoCapture camera(camera_stream);
        return camera;
    }
}

int main(int argc, char* argv[] ) {

    const String keys =
        "{help h  |      | print this message   }"
        "{@index  |0     | camera index         }"
    ;

    CommandLineParser parser(argc, argv, keys);
    parser.about("camera reader");
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

    string camera_index = parser.get<String>(0);

    if (!parser.check()) {
        parser.printErrors();
        return 0;
    }
    VideoCapture cap = getCaptureFromIndexOrIp(camera_index);; // open the default camera
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
