#include <src/view/gui/videoplayer/OpenCVVideoPlayer.hpp>
#include <iostream>

namespace src
{
    namespace view
    {
        namespace gui
        {

            namespace videoplayer
            {
                OpenCVVideoPlayer::OpenCVVideoPlayer(int captureInput, std::string nameOutput)
                    : mWindowOutputName(nameOutput)
                    , mIsRunningThread(true)
                    , mCapture(captureInput)
                {
                    mCurrentFrame = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
                    if (!mCapture.isOpened())
                    {
                        std::cout << "Could not open" << std::endl;
                    }
                }

                void OpenCVVideoPlayer::init()
                {
                    cv::Size sizeRef = cv::Size((int) mCapture.get(CV_CAP_PROP_FRAME_WIDTH),
                                                (int) mCapture.get(CV_CAP_PROP_FRAME_HEIGHT));

                    cv::namedWindow(mWindowOutputName, CV_WINDOW_AUTOSIZE);
                    cv::moveWindow(mWindowOutputName, 1000, 0);

                    std::cout << "Width: " << sizeRef.width << ", Height: " << sizeRef.height << std::endl;
                }

                void OpenCVVideoPlayer::run(cv::Mat newframe)
                {
                    mCapture >> mCurrentFrame;

                    if (mCurrentFrame.empty())
                    {
                        std::cout << "Frame empty!!" << std::endl;
                    }

                    cv::imshow(mWindowOutputName, newframe);
                    mWaitKey = (char) cv::waitKey(1);
                }

            }
        }
    }
}
