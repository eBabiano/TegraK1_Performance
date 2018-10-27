#ifndef TESTCUDAGPU_HPP
#define TESTCUDAGPU_HPP

#include <src/view/av/AVView.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           class TestCudaGpu
                   : public av::AVView
           {
               public:
                  TestCudaGpu();

                  virtual void runCPUThread();
                  virtual void runGPUThread();

               private:
                  cv::Mat mFrame;

           };
       }
    }
}

#endif // TESTCUDAGPU_HPP
