#include <src/view/av/events/UpdateBenchmarkEvent.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           namespace events
           {
               UpdateBenchmarkEvent::UpdateBenchmarkEvent(double timeProcMillis, const std::string& device)
                   : mTimeProcMillis(timeProcMillis)
                   , mDevice(device)
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

           }
       }
    }
}
