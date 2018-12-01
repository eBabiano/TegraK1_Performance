#include <src/view/gui/videoplayer/FlyCaptureVideoPlayer.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                FlyCaptureVideoPlayer::FlyCaptureVideoPlayer()
                {
                    mCurrentFrame = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);

                }

                void FlyCaptureVideoPlayer::init()
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
                            mIndexCamera = i;
                            error = busManager.GetCameraFromIndex(mIndexCamera, &guid);
                            if (error != FlyCapture2::PGRERROR_OK)
                            {
                                std::cout << "Error detected for camera " << i << std::endl;
                            }
                            initSingleCamera(guid);
                        }
                    }
                }

                int FlyCaptureVideoPlayer::initSingleCamera(FlyCapture2::PGRGuid guid)
                {
                    int ret = 0;
                    FlyCapture2::Error error;
                    mCam = new FlyCapture2::Camera();

                    // Connect to a camera
                    error = mCam->Connect(&guid);
                    if (error != FlyCapture2::PGRERROR_OK) {
                        std::cout << "FlyCapture2 camera error detected" << std::endl;
                        ret = -1;
                    }
                    else {
                        // Get the camera information
                        FlyCapture2::CameraInfo camInfo;
                        error = mCam->GetCameraInfo(&camInfo);
                        if (error != FlyCapture2::PGRERROR_OK) {
                            std::cout << "FlyCapture2 camera error detected" << std::endl;
                            ret = -1;
                        }
                        else {
                            ///printCameraInfo(&camInfo);
                            // Start capturing images
                            error = mCam->StartCapture();
                            if (error != FlyCapture2::PGRERROR_OK) {
                                std::cout << "FlyCapture2 camera error detected" << std::endl;
                                ret = -1;
                            }
                            else {
                                //read frames from camera and wait for user commands
                                ret = readFramesFromCamera();
                            }
                        }
                    }
                    return ret;
                }

                int FlyCaptureVideoPlayer::readFramesFromCamera()
                {
                    int ret = 0;
                    FlyCapture2::Error error;

                    mRawImage = new FlyCapture2::Image();

                    // Retrieve an image to get image size and allocate IplImage
                    error = mCam->RetrieveBuffer(mRawImage);
                    if (error != FlyCapture2::PGRERROR_OK) {
                        std::cout << "FlyCapture2 camera error detected" << std::endl;
                        ret = -1;
                    }
                    return ret;
                }

                void FlyCaptureVideoPlayer::run(cv::Mat newframe)
                {
                    FlyCapture2::Error error;

                    // Retrieve an image
                    error = mCam->RetrieveBuffer(mRawImage);
                    if (error != FlyCapture2::PGRERROR_OK) {
                        std::cout << "FlyCapture2 camera error detected" << std::endl;
                    }
                    else {
                        // Create a converted image
                        FlyCapture2::Image convertedImage;
                        // Convert the raw image
                        error = mRawImage->Convert(FlyCapture2::PIXEL_FORMAT_BGR, &convertedImage);
                        if (error != FlyCapture2::PGRERROR_OK) {
                            std::cout << "FlyCapture2 camera error detected" << std::endl;
                        }
                        else {
                            unsigned int rowBytes = (double) convertedImage.GetReceivedDataSize() /
                                    (double) convertedImage.GetRows();
                            cv::Mat(convertedImage.GetRows(), convertedImage.GetCols(),
                                    CV_8UC3, convertedImage.GetData(), rowBytes).copyTo(mCurrentFrame);

                            if (mCurrentFrame.empty())
                            {
                                std::cout << "Frame empty!!" << std::endl;
                            }

                            //cv::Mat imgReadColor;
                            //cv::cvtColor(mCurrentFrame, mCurrentFrame, CV_BGR2RGB);

                            cv::imshow("FlyCapture", newframe);
                            mWaitKey = (char) cv::waitKey(1);
                        }
                    }
                }
            }
        }
    }
}
