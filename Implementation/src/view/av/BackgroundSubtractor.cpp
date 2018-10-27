#include <src/view/av/BackgroundSubtractor.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           BackgroundSubtractor::BackgroundSubtractor()
           {
           }

           void BackgroundSubtractor::runCPUThread()
           {
               unsigned t1, t2;
               double time;
               cv::Mat frame;
               cv::Mat frameMOG = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
               cv::Ptr<cv::BackgroundSubtractorMOG> backgroundSub = new cv::BackgroundSubtractorMOG();

               while (mIsRunningThread)
               {
                   frame = getCapturedImage();

                   t1 = clock();
                   if (frame.rows == frameMOG.rows && frame.cols == frameMOG.cols)
                   {
                       backgroundSub->operator()(frame, frameMOG);
                   }
                   t2 = clock();

                   frameMOG.copyTo(mImage);
                   time = (double(t2-t1)/CLOCKS_PER_SEC);
                   std::cout << "Execution Time: " << time*1000.0 << " ms" << std::endl;

                   updateBenchmark(time);
               }
           }

           void BackgroundSubtractor::runGPUThread()
           {

           }
       }
    }
}
