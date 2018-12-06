#include <src/view/gui/videoplayer/VideoPlayerManager.hpp>
#include <lib/flycapture2/include/FlyCapture2.h>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                VideoPlayerManager::VideoPlayerManager(const std::string& cameraType)
                {
                     if (cameraType == "--fly")
                     {
                         FlyCapture2::BusManager busManager;
                         unsigned int numCameras;
                         FlyCapture2::Error error = busManager.GetNumOfCameras(&numCameras);
                         if (error != FlyCapture2::PGRERROR_OK)
                         {
                             std::cout << "FlyCapture2 camera error detected" << std::endl;
                         }
                         else
                         {
                             std::cout << "Number of cameras detected: " << numCameras << std::endl;

                             for (unsigned int i = 0; i < numCameras; i++)
                             {
                                 FlyCapture2::PGRGuid guid;
                                 error = busManager.GetCameraFromIndex(i, &guid);
                                 if (error != FlyCapture2::PGRERROR_OK)
                                 {
                                     std::cout << "Error detected for camera " << i << std::endl;
                                 }
                                 FlyCaptureVideoPlayer* videoPlayer = new FlyCaptureVideoPlayer(i);
                                 mFlyCaptureVideoPlayersVector.push_back(videoPlayer);
                                 videoPlayer->setGuid(guid);
                                 videoPlayer->init();

                             }
                         }

                     }
                     else if (cameraType == "--cam")
                     {
                     }
                     else
                     {
                         std::cout << "Error in parameters: Specify input camera: [--fly], [--cam]" << std::endl;
                         exit(-1);
                     }
                }
            }
        }
    }
}
