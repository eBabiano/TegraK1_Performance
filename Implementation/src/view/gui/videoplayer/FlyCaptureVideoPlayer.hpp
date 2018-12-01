#ifndef FLYCAPTUREVIDEOPLAYER_HPP
#define FLYCAPTUREVIDEOPLAYER_HPP

#include <lib/flycapture2/include/FlyCapture2.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <src/view/gui/videoplayer/VideoPlayer.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                class FlyCaptureVideoPlayer
                        : public VideoPlayer
                {
                    public:
                        FlyCaptureVideoPlayer();

                        virtual void init();
                        virtual void run(cv::Mat newframe);

                    private:
                        int readFramesFromCamera();
                        int initSingleCamera(FlyCapture2::PGRGuid guid);

                        FlyCapture2::Camera* mCam;
                        FlyCapture2::Image* mRawImage;
                        unsigned int mIndexCamera;
                        char mWaitKey;

                };
            }
        }
    }
}

#endif // FLYCAPTUREVIDEOPLAYER_HPP
