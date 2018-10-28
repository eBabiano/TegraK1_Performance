#include <src/view/av/AVView.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           AVView::AVView()
               : mIsRunningThread(false)
               , mIsGPU(false)
               , mTotalFrames(0)
           {
               mImage = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
           }

           AVView::~AVView()
           {
               mThread->join();
           }

           void AVView::start()
           {
               mIsRunningThread = true;
               std::cout << "OpenCV version: " << CV_VERSION << std::endl;
               if (mIsGPU)
                   mThread = new boost::thread(boost::bind(&AVView::runGPUThread, this));
               else
                   mThread = new boost::thread(boost::bind(&AVView::runCPUThread, this));

           }

           void AVView::stop()
           {
               mIsRunningThread = false;
               resetImage();
               mThread->join();
           }

           void AVView::onMouseEvent(int event, int x, int y)
           {

           }

           cv::Mat AVView::getImage()
           {
               return mImage;
           }

           void AVView::setImage(cv::Mat &image)
           {
               mImage = image;
           }

           cv::Mat AVView::getCapturedImage()
           {
               //cv::Mat image;// = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
               //if (!mCapturedImage.empty())
               //{
                   return mCapturedImage;
               //}
               //return image;
           }

           void AVView::setCapturedImage(cv::Mat &capturedImage)
           {
               if (!capturedImage.empty())
               {
                   mCapturedImage = capturedImage;
               }
           }

           void AVView::resetImage()
           {
               mImage = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
           }

           void AVView::activateGPU(bool activate)
           {
               mIsGPU = activate;
           }

           void AVView::updateBenchmark(double millisec)
           {
               notify(events::UpdateBenchmarkEvent(millisec*1000, ""));
           }

           void AVView::setTotalFrames(int value)
           {
               mTotalFrames = value;
           }

       }
    }
}
