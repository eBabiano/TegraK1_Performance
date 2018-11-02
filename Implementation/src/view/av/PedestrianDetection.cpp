#include <src/view/av/PedestrianDetection.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           PedestrianDetection::PedestrianDetection()
           {
           }

           void PedestrianDetection::runCPUThread()
           {
               unsigned t1, t2;
               double time;
               cv::Mat frame;

               while(mIsRunningThread)
               {
                   getCapturedImage().copyTo(frame);

                   if (!frame.empty())
                   {
                       t1 = clock();
                       cv::cvtColor(frame, frame, CV_RGB2GRAY);
                       cv::HOGDescriptor hog;
                       hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

                       std::vector<cv::Rect> found, found_filtered;
                       hog.detectMultiScale(frame, found, 0, cv::Size(8,8), cv::Size(128,128), 1.05, 2);

                       size_t i, j;
                       for (i=0; i<found.size(); i++)
                       {
                           cv::Rect r = found[i];
                           for (j=0; j<found.size(); j++)
                               if (j!=i && (r & found[j])==r)
                                   break;
                           if (j==found.size())
                               found_filtered.push_back(r);
                       }

                       for (i=0; i<found_filtered.size(); i++)
                       {
                           cv::Rect r = found_filtered[i];
                           r.x += cvRound(r.width*0.1);
                           r.width = cvRound(r.width*0.8);
                           r.y += cvRound(r.height*0.06);
                           r.height = cvRound(r.height*0.9);
                           cv::rectangle(frame, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
                       }
                       t2 = clock();

                       frame.copyTo(mImage);

                       updateBenchmark(t1, t2);
                   }
               }

           }

           void PedestrianDetection::runGPUThread()
           {
               unsigned t1, t2;
               double time;
               cv::Mat frame;

               while(mIsRunningThread)
               {
                   getCapturedImage().copyTo(frame);

                   if (!frame.empty())
                   {
                       t1 = clock();
                       cv::cvtColor(frame, frame, CV_RGB2GRAY);
                       cv::HOGDescriptor hog;
                       ///cv::gpu::HOGDescriptor
                       hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

                       std::vector<cv::Rect> found, found_filtered;
                       hog.detectMultiScale(frame, found, 0, cv::Size(8,8), cv::Size(128,128), 1.05, 2);

                       size_t i, j;
                       for (i=0; i<found.size(); i++)
                       {
                           cv::Rect r = found[i];
                           for (j=0; j<found.size(); j++)
                               if (j!=i && (r & found[j])==r)
                                   break;
                           if (j==found.size())
                               found_filtered.push_back(r);
                       }

                       for (i=0; i<found_filtered.size(); i++)
                       {
                           cv::Rect r = found_filtered[i];
                           r.x += cvRound(r.width*0.1);
                           r.width = cvRound(r.width*0.8);
                           r.y += cvRound(r.height*0.06);
                           r.height = cvRound(r.height*0.9);
                           cv::rectangle(frame, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
                       }
                       t2 = clock();

                       frame.copyTo(mImage);

                       updateBenchmark(t1, t2);
                   }
               }
           }
       }
    }
}
