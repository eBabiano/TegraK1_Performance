#ifndef VIDEOPLAYER_HPP
#define VIDEOPLAYER_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                class VideoPlayer
                {
                    public:
                        VideoPlayer();

                        virtual void init() = 0;
                        virtual void run(cv::Mat newframe) = 0;

                        cv::Mat getCurrentFrame();

                    protected:
                        cv::Mat mCurrentFrame;

                };
            }
        }
    }
}

#endif // VIDEOPLAYER_HPP
