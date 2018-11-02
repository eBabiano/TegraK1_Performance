#ifndef AVVIEW_HPP
#define AVVIEW_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/gpu/gpu.hpp>

#include <boost/thread.hpp>
#include <ctime>

#include <src/view/av/events/UpdateBenchmarkEvent.hpp>
#include <src/util/Observable.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           class AVView : public util::Observable<events::UpdateBenchmarkEvent>
           {
               public:
                   AVView();
                   ~AVView();

                   virtual void start();
                   virtual void stop();
                   virtual void runCPUThread() = 0;
                   virtual void runGPUThread() = 0;
                   virtual void onMouseEvent(int event, int x, int y);

                   cv::Mat getImage();
                   void setImage(cv::Mat &image);

                   cv::Mat getCapturedImage();
                   void setCapturedImage(cv::Mat &capturedImage);

                   void resetImage();

                   void activateGPU(bool activate);

                   void setTotalFrames(int value);

               protected:
                   void updateBenchmark(double initTime, double endTime);
                   boost::thread* mThread;
                   bool mIsRunningThread;
                   cv::Mat mImage;
                   bool mIsGPU;

                   int mTotalFrames;

               private:
                   cv::Mat mCapturedImage;

                   using util::Observable<events::UpdateBenchmarkEvent>::notify;

           };
       }
    }
}

#endif // AVVIEW_HPP
