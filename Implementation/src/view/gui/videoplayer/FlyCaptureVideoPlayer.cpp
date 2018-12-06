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
                FlyCaptureVideoPlayer::FlyCaptureVideoPlayer(int indexCamera)
                    : mIndexCamera(indexCamera)
                    , mIsRunningThread(false)
                {
                    mCurrentFrame = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
                }

                FlyCaptureVideoPlayer::~FlyCaptureVideoPlayer()
                {
                    if (mIsRunningThread)
                    {
                        mThread->join();
                        mCam->Disconnect();
                    }
                }

                void FlyCaptureVideoPlayer::init()
                {
                    initSingleCamera(mGuid);
                    mThread = new boost::thread(boost::bind(&FlyCaptureVideoPlayer::run, this));
                    mIsRunningThread = true;
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

                void FlyCaptureVideoPlayer::setGuid(const FlyCapture2::PGRGuid &value)
                {
                    mGuid = value;
                }


                void FlyCaptureVideoPlayer::setCurrentFrame(const cv::Mat &value)
                {
                    mCurrentFrame = value;
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

                void FlyCaptureVideoPlayer::run()
                {
                    FlyCapture2::Error error;

                    while(mCam->IsConnected())
                    {
                        mMutex.lock();
                        // Retrieve an image
                        error = mCam->RetrieveBuffer(mRawImage);

                        if (error != FlyCapture2::PGRERROR_OK) {
                            std::cout << "FlyCapture2 camera error detected 1" << std::endl;
                        }
                        else {
                            // Create a converted image
                            FlyCapture2::Image convertedImage;
                            // Convert the raw image
                            error = mRawImage->Convert(FlyCapture2::PIXEL_FORMAT_BGR, &convertedImage);

                            if (error != FlyCapture2::PGRERROR_OK) {
                                std::cout << "FlyCapture2 camera error detected 2" << std::endl;
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

                                cv::imshow("FlyCapture" + std::to_string(mIndexCamera), mCurrentFrame);
                            }
                        }
                        mMutex.unlock();
                        usleep(60000);
                    }
                    mCam->Disconnect();
                }
            }
        }
    }
}
