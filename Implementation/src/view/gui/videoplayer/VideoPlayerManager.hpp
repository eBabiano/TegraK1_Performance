#ifndef VideoPlayerManager_HPP
#define VideoPlayerManager_HPP

#include <src/view/gui/videoplayer/FlyCaptureVideoPlayer.hpp>
#include <src/view/gui/videoplayer/OpenCVVideoPlayer.hpp>
#include <string>
#include <vector>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                class VideoPlayerManager
                {
                    public:
                        VideoPlayerManager(const std::string& cameraType);

                    private:
                        std::vector<FlyCaptureVideoPlayer*> mFlyCaptureVideoPlayersVector;
                        std::vector<OpenCVVideoPlayer*> mOpenCVVideoPlayersVector;

                };
            }
        }
    }
}

#endif // VideoPlayerManager_HPP
