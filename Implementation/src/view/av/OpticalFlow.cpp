#include <src/view/av/OpticalFlow.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           OpticalFlow::OpticalFlow()
           {
           }

           void OpticalFlow::runCPUThread()
           {
               unsigned t1, t2;
               double time;
               cv::Mat frame, old_gray, old_frame, frame_grey;
               std::vector<cv::Point2f> prevPoints, nextPoints, corners;
               std::vector<uchar> status;
               std::vector<float> err;

               std::cout << "))))))))))))))))" << std::endl;
               old_frame = getCapturedImage();
               std::cout << "------------------" << std::endl;
               cv::cvtColor(old_frame, old_gray, CV_BGR2GRAY);
                std::cout << "!!!!!!!!!!!!!!!!!" << std::endl;
               cv::goodFeaturesToTrack(old_gray, corners, 100, 0.3, 7, 7);
               std::cout << "*******************" << std::endl;

               while (mIsRunningThread)
               {
                   frame = getCapturedImage();
                   cv::cvtColor(frame, frame_grey, CV_BGR2GRAY);;

                   t1 = clock();
                   cv::calcOpticalFlowPyrLK(old_gray, frame_grey, prevPoints, nextPoints, status, err);

                   int i, k;
                   for (i = k = 0; i < nextPoints.size(); i++)
                   {
                       if (!status[i]) continue;
                       prevPoints[k] = prevPoints[i];
                       nextPoints[k] = nextPoints[i];
                       err[k] = err[i];
                       k++;
                   }
                   prevPoints.resize(k);
                   nextPoints.resize(k);
                   err.resize(k);
                   t2 = clock();

                   frame_grey.copyTo(mImage);
                   time = (double(t2-t1)/CLOCKS_PER_SEC);
                   std::cout << "Execution Time: " << time*1000.0 << " ms" << std::endl;

                   updateBenchmark(time);
               }
           }

           void OpticalFlow::runGPUThread()
           {

           }
       }
    }
}
