#ifndef UPDATEBENCHMARKEVENT_HPP
#define UPDATEBENCHMARKEVENT_HPP

#include <string>

namespace src
{
    namespace view
    {
       namespace av
       {
           namespace events
           {
               class UpdateBenchmarkEvent
               {
                   public:
                       UpdateBenchmarkEvent(double timeProcMillis, double fps, const std::string &device);

                       double getTimeProcMillis() const;
                       std::string getDevice() const;
                       double getFPS() const;

               private:
                       double mTimeProcMillis;
                       double mFPS;
                       std::string mDevice;
               };
           }
       }
    }
}

#endif // UPDATEBENCHMARKEVENT_HPP
