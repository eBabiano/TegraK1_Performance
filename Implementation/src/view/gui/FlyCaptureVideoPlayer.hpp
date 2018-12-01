#ifndef FLYCAPTUREVIDEOPLAYER_HPP
#define FLYCAPTUREVIDEOPLAYER_HPP

#include <lib/flycapture2/include/FlyCapture2.h>

namespace src
{
    namespace view
    {
        namespace gui
        {
            class FlyCaptureVideoPlayer
            {
                public:
                    FlyCaptureVideoPlayer();
                    void init();
                    int runSingleCamera(FlyCapture2::PGRGuid guid, int idxCam);

                private:
                    int readFramesFromCamera(FlyCapture2::Camera *cam, int idxCam);

            };
        }
    }
}

#endif // FLYCAPTUREVIDEOPLAYER_HPP
