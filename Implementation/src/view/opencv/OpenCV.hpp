#ifndef VIEW_OPENCV_OPENCV_H
#define VIEW_OPENCV_OPENCV_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace src
{
    namespace view
    {
        namespace opencv
        {
            class OpenCV
            {
            public:
                OpenCV();
                void execute();
             private:
                cv::Mat mImage;
                cv::VideoCapture mVideoPlayer;
            };
        } //OPENCV
    } //VIEW
}

#endif // VIEW_OPENCV_OPENCV_H
