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
               cv::Mat frame_gray, frameMOG;
               //cv::Ptr<cv::BackgroundSubtractorMOG> backgroundSub = new cv::BackgroundSubtractorMOG();
               cv::BackgroundSubtractorMOG2 mog2;

               while (mIsRunningThread)
               {
                   std::cout << "(((((((((((((((((" << std::endl;
                   getCapturedImage().copyTo(frame);
                   std::cout << "/////////////////" << std::endl;
                   if (!frame.empty())
                   {
                       if (frame.channels() == 3 || frame.channels() == 4)
                       {
                           cv::cvtColor(frame, frame_gray, CV_RGB2GRAY);
                           std::cout << "****************" << std::endl;

                           t1 = clock();
                           ///@todo OpenCV Error: Sizes of input arguments do not match
                           mog2(frame_gray, frameMOG, 0.0);
                           t2 = clock();
                           std::cout << "------------------" << std::endl;

                           frameMOG.copyTo(mImage);
                           time = (double(t2-t1)/CLOCKS_PER_SEC);
                           std::cout << "Execution Time: " << time*1000.0 << " ms" << std::endl;

                           updateBenchmark(time);
                           std::cout << "@@@@@@@@@@@@@@@@@@@" << std::endl;

                       }
                   }
               }
           }

           void BackgroundSubtractor::runGPUThread()
           {

           }
       }
    }
}
