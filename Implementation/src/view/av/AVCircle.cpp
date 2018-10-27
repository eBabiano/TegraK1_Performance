#include <src/view/av/AVCircle.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           AVCircle::AVCircle()
           {

           }

           void AVCircle::runCPUThread()
           {
               cv::Mat image;
               unsigned t1, t2;
               double time;

                while(mIsRunningThread)
                {
                    std::cout << "Running AVCircle thread" << std::endl;
                    image = getImage();
                    t1 = clock();
                    cv::circle(image, cv::Point(320, 240), 32.0, cv::Scalar(0, 255, 0), 2, 8);
                    t2 = clock();

                    image.copyTo(mImage);

                    time = (double(t2-t1)/CLOCKS_PER_SEC);
                    std::cout << "Execution Time: " << time*1000.0 << " ms" << std::endl;
                    updateBenchmark(time);
                    sleep(1);
                }

           }

           void AVCircle::runGPUThread()
           {

           }
       }
    }
}
