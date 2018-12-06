#ifndef FLYCAPTUREVIDEOPLAYER_HPP
#define FLYCAPTUREVIDEOPLAYER_HPP

#include <lib/flycapture2/include/FlyCapture2.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <src/view/gui/videoplayer/VideoPlayer.hpp>

#include <boost/thread.hpp>
#include <mutex>

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
                        FlyCaptureVideoPlayer(int indexCamera);
                        ~FlyCaptureVideoPlayer();

                        virtual void init();
                        virtual void run();

                        void setCurrentFrame(const cv::Mat &value);

                        void setGuid(const FlyCapture2::PGRGuid &value);

                private:
                        int readFramesFromCamera();
                        int initSingleCamera(FlyCapture2::PGRGuid guid);

                        FlyCapture2::Camera* mCam;
                        FlyCapture2::Image* mRawImage;
                        unsigned int mIndexCamera;
                        char mWaitKey;
                        FlyCapture2::PGRGuid mGuid;

                        boost::thread* mThread;
                        std::mutex mMutex;
                        cv::Mat mCurrentFrame;
                        bool mIsRunningThread;

                };
            }
        }
    }
}

#endif // FLYCAPTUREVIDEOPLAYER_HPP
