#include <src/view/gui/videoplayer/VideoPlayer.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                VideoPlayer::VideoPlayer()
                {
                }

                cv::Mat VideoPlayer::getCurrentFrame()
                {
                    return mCurrentFrame;
                }
            }
        }
    }
}
