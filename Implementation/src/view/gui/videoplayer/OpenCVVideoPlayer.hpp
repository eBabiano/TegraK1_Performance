#ifndef OPENCVVIDEOPLAYER_HPP
#define OPENCVVIDEOPLAYER_HPP

#include <opencv/highgui.h>
#include <src/view/gui/videoplayer/VideoPlayer.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                class OpenCVVideoPlayer
                        : public VideoPlayer
                {
                    public:
                        OpenCVVideoPlayer(int captureInput, std::string nameOutput);

                        virtual void init();
                        virtual void run(cv::Mat newframe);

                    private:
                        std::string mWindowOutputName;
                        cv::VideoCapture mCapture;
                        char mWaitKey;

                        bool mIsRunningThread;

                };
            }
        }
    }
}

#endif // OPENCVVIDEOPLAYER_HPP
