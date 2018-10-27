#include <src/view/av/TestCudaGpu.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           TestCudaGpu::TestCudaGpu()
           {
           }

           void TestCudaGpu::runCPUThread()
           {
               cv::Mat image, dest;
               unsigned t1, t2;
               double time;

               ///WITH GPU
                while(mIsRunningThread)
                {
                    std::cout << "Running Test CUDA thread" << std::endl;
                    image = getCapturedImage();
                    t1 = clock();

                    cv::gpu::GpuMat gpuMatIni(image);
                    cv::gpu::GpuMat gpuMatDest;

                    cv::gpu::bilateralFilter(gpuMatIni, gpuMatDest, -1, 50, 7);
                    cv::gpu::Canny(gpuMatDest, gpuMatDest, 35, 200, 3);

                    //mImage = cv::Mat(gpuMatDest);

                    t2 = clock();

                    time = (double(t2-t1)/CLOCKS_PER_SEC);
                    std::cout << "Execution Time: " << time*1000.0 << " ms" << std::endl;
                    sleep(1);
                }

                ///WITHOUT GPU
             /*    while(mIsRunningThread)
                 {
                     std::cout << "Running Test CUDA thread" << std::endl;
                     image = getCapturedImage(); ///getImage();
                     t1 = clock();

                     cv::bilateralFilter(image, dest, -1, 50, 7);
                     cv::Canny(dest, dest, 35, 200, 3);

                     t2 = clock();

                     //setImage(dest);
                    // dest.copyTo(mImage);
                    // image = dest;

                     time = (double(t2-t1)/CLOCKS_PER_SEC);
                     std::cout << "Execution Time: " << time*1000.0 << " ms" << std::endl;
                     //sleep(1);
                 }*/
           }

           void TestCudaGpu::runGPUThread()
           {

           }
       }
    }
}
