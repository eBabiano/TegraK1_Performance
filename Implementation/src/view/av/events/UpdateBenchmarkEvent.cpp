#include <src/view/av/events/UpdateBenchmarkEvent.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           namespace events
           {
               UpdateBenchmarkEvent::UpdateBenchmarkEvent(double timeProcMillis, double fps, const std::string& device)
                   : mTimeProcMillis(timeProcMillis)
                   , mDevice(device)
                   , mFPS(fps)
               {
               }

               double UpdateBenchmarkEvent::getTimeProcMillis() const
               {
                   return mTimeProcMillis;
               }

               std::string UpdateBenchmarkEvent::getDevice() const
               {
                   return mDevice;
               }

               double UpdateBenchmarkEvent::getFPS() const
               {
                   return mFPS;
               }
               
           }
       }
    }
}
