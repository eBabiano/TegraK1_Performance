#ifndef AVRECTANGLE_HPP
#define AVRECTANGLE_HPP

#include <src/view/av/AVView.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           class AVRectangle
                   : public AVView
           {
              public:
                 AVRectangle();

                 virtual void runCPUThread();
                 virtual void runGPUThread();
           };
       }
    }
}

#endif // AVRECTANGLE_HPP
