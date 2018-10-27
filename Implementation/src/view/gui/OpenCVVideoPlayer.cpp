#include <src/view/gui/OpenCVVideoPlayer.hpp>
#include <iostream>
#include <lib/flycapture2/include/FlyCapture2.h>

namespace src
{
    namespace view
    {
        namespace gui
        {
            OpenCVVideoPlayer::OpenCVVideoPlayer(int captureInput, std::string nameInput, std::string nameOutput)
                : mWindowInputName(nameInput)
                , mWindowOutputName(nameOutput)
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

                cv::namedWindow(mWindowInputName, CV_WINDOW_AUTOSIZE);
                cv::moveWindow(mWindowInputName, 400, 0);

                cv::namedWindow(mWindowOutputName, CV_WINDOW_AUTOSIZE);
                cv::moveWindow(mWindowOutputName, 1000, 0);

                std::cout << "Width: " << sizeRef.width << ", Height: " << sizeRef.height << std::endl;
            }

            void OpenCVVideoPlayer::runVideoPlayerInput()
            {
                cv::Mat frame;

                mCapture >> mCurrentFrame;

                if (mCurrentFrame.empty())
                {
                    std::cout << "Frame empty!!" << std::endl;
                }

                frame = mCurrentFrame;

                cv::imshow(mWindowInputName, frame);
                mWaitKey = (char) cv::waitKey(13);
            }

            void OpenCVVideoPlayer::runVideoPlayerOutput(cv::Mat newframe, bool sumWithInput)
            {
                cv::Mat frame;

                mCapture >> mCurrentFrame;

                if (mCurrentFrame.empty())
                {
                    std::cout << "Frame empty!!" << std::endl;
                }

                if (sumWithInput)
                {
                    frame = mCurrentFrame + newframe;
                }
                else
                {
                    frame = newframe;
                }

                cv::imshow(mWindowOutputName, frame);
                mWaitKey = (char) cv::waitKey(13);
            }

            cv::Mat OpenCVVideoPlayer::getCurrentFrame() const
            {
                return mCurrentFrame;
            }

            cv::VideoCapture OpenCVVideoPlayer::getVideoCapture() const
            {
                return mCapture;
            }

        }
    }
}
