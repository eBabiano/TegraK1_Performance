#include <src/view/opencv/OpenCV.hpp>

namespace src
{
    namespace view
    {
        namespace opencv
        {
            OpenCV::OpenCV()
            {

            }

            void OpenCV::execute()
            {
                mVideoPlayer.open(0);

                if (!mVideoPlayer.isOpened())
                {
                    std::cerr << "Could not open the video capture" << std::endl;
                }

                while(1)
                {
                    mVideoPlayer >> mImage;
                    if (mImage.empty())  break;
                    //cv::imshow("Example", mImage);
                    if (cv::waitKey(33) >= 0)   break;
                }
            }
        } //OPENCV
    } //VIEW
}

