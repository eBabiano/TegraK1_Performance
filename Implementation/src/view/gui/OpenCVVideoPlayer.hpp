#ifndef OPENCVVIDEOPLAYER_HPP
#define OPENCVVIDEOPLAYER_HPP

#include <opencv/highgui.h>

namespace src
{
    namespace view
    {
        namespace gui
        {
            class OpenCVVideoPlayer
            {
                public:
                    OpenCVVideoPlayer(int captureInput, std::string nameInput, std::string nameOutput);

                    void init();
                    void runVideoPlayerInput();
                    void runVideoPlayerOutput(cv::Mat newframe, bool sumWithInput);

                    cv::Mat getCurrentFrame() const;

                    cv::VideoCapture getVideoCapture() const;                    

                private:
                    std::string mWindowInputName;
                    std::string mWindowOutputName;
                    cv::VideoCapture mCapture;
                    cv::Mat mCurrentFrame;
                    char mWaitKey;

                    bool mIsRunningThread;

            };
        }
    }
}

#endif // OPENCVVIDEOPLAYER_HPP
