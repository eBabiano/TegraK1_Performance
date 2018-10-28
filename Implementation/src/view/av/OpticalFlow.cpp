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

           /*void OpticalFlow::runCPUThread()
           {
               unsigned t1, t2;
               double time;
               cv::Mat frame, old_gray, frame_grey;
               std::vector<cv::Point2f> prevPoints, nextPoints, corners;
               std::vector<uchar> status;
               std::vector<float> err;

               while (corners.empty())
               {
                   cv::Mat old_frame = getCapturedImage();
                   if (old_frame.channels() == 3 || old_frame.channels() == 4)
                   {
                       cv::cvtColor(old_frame, old_gray, CV_RGB2GRAY);
                       cv::goodFeaturesToTrack(old_gray, corners, 100, 0.3, 7, cv::Mat(), 7);
                       std::cout << "empty" << std::endl;
                   }
               }

               prevPoints = corners;
               while (mIsRunningThread)
               {
                   std::cout << "@@@@@@@@@@@@@@@@" << std::endl;
                   getCapturedImage().copyTo(frame);
                   std::cout << "=================" << std::endl;
                   if (frame.channels() == 3 || frame.channels() == 4)
                   {
                   cv::cvtColor(frame, frame_grey, CV_RGB2GRAY);;

                   t1 = clock();
                   std::cout << "))))))))))))))))" << std::endl;


                   std::cout << "old_gray.channels: " << old_gray.channels() << std::endl;
                   std::cout << "old_gray.size: " << old_gray.size() << std::endl;
                   std::cout << "frame_grey.channels: " << frame_grey.channels() << std::endl;
                   std::cout << "frame_grey.size: " << frame_grey.size() << std::endl;
                   std::cout << "corners.size: " << corners.size() << std::endl;

                   ///@todo error: (-209) The operation is neither 'array op array'
                       cv::calcOpticalFlowPyrLK(old_gray, frame_grey, prevPoints, nextPoints, status, err);

                       int i, k;
                       std::cout << "------------------" << std::endl;

                       std::cout << "nextPoints.size: " << nextPoints.size() << std::endl;

                       for (i = k = 0; i < nextPoints.size(); i++)
                       {
                           if (!status[i]) continue;
                           prevPoints[k] = prevPoints[i];
                           nextPoints[k] = nextPoints[i];
                           err[k] = err[i];
                           k++;
                       }
                       std::cout << "!!!!!!!!!!!!!!!!!" << std::endl;

                       prevPoints.resize(k);
                       nextPoints.resize(k);
                       err.resize(k);
                   }
                   else
                   {
                       std::cout << "999" << std::endl;
                   }

                   t2 = clock();

                   frame_grey.copyTo(mImage);
                   time = (double(t2-t1)/CLOCKS_PER_SEC);
                   std::cout << "Execution Time: " << time*1000.0 << " ms" << std::endl;
                   std::cout << "*******************" << std::endl;

                   updateBenchmark(time);
               }
           }*/

           void OpticalFlow::runCPUThread()
           {
               unsigned t1, t2;
               double time;

               cv::TermCriteria termcrit(cv::TermCriteria::COUNT|cv::TermCriteria::EPS,20,0.03);
               cv::Size subPixWinSize(10,10), winSize(31,31);

               const int MAX_COUNT = 500;
               bool needToInit = true;
               bool nightMode = false;

               ///Mouse events
               bool addRemovePt = false;
               cv::Point2f point;

               cv::Mat gray, prevGray, image;
               std::vector<cv::Point2f> points[2];

               while(mIsRunningThread)
               {
                   getCapturedImage().copyTo(image);
                   if( !image.empty() )
                   {
                       t1 = clock();
                       cv::cvtColor(image, gray, CV_BGR2GRAY);

                       if( nightMode )
                           image = cv::Scalar::all(0);

                       if( needToInit )
                       {
                           // automatic initialization
                           cv::goodFeaturesToTrack(gray, points[1], MAX_COUNT, 0.01, 10, cv::Mat(), 3, 0, 0.04);
                           cv::cornerSubPix(gray, points[1], subPixWinSize, cv::Size(-1,-1), termcrit);
                           addRemovePt = false;
                       }
                       else if( !points[0].empty() )
                       {
                           std::vector<uchar> status;
                           std::vector<float> err;
                           if(prevGray.empty())
                               gray.copyTo(prevGray);
                           cv::calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize,
                                   3, termcrit, 0, 0.001);
                           size_t i, k;
                           for( i = k = 0; i < points[1].size(); i++ )
                           {
                               if( addRemovePt )
                               {
                                   if( cv::norm(point - points[1][i]) <= 5 )
                                   {
                                       addRemovePt = false;
                                       continue;
                                   }
                               }

                               if( !status[i] )
                                   continue;

                               points[1][k++] = points[1][i];
                               cv::circle( image, points[1][i], 3, cv::Scalar(0,255,0), -1, 8);
                           }
                           points[1].resize(k);
                       }

                       if( addRemovePt && points[1].size() < (size_t)MAX_COUNT )
                       {
                           std::vector<cv::Point2f> tmp;
                           tmp.push_back(point);
                           cv::cornerSubPix( gray, tmp, winSize, cv::Size(-1,-1), termcrit);
                           points[1].push_back(tmp[0]);
                           addRemovePt = false;
                       }

                       t2 = clock();

                       needToInit = false;
                       image.copyTo(mImage);

                       time = (double(t2-t1)/CLOCKS_PER_SEC);
                       std::cout << "Execution Time: " << time*1000.0 << " ms" << std::endl;

                       updateBenchmark(time);

                       std::swap(points[1], points[0]);
                       cv::swap(prevGray, gray);
                   }
               }
           }

           void OpticalFlow::runGPUThread()
           {

           }
       }
    }
}
