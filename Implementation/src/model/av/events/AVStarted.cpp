#include <src/model/av/events/AVStarted.hpp>

namespace src
{
    namespace model
    {
       namespace av
       {
           namespace events
           {
               AVStarted::AVStarted(const std::string &type, bool activated, bool isGPU)
                   : mType(type)
                   , mIsActivated(activated)
                   , mIsGPU(isGPU)
               {

               }

               std::string AVStarted::getType() const
               {
                   return mType;
               }

               bool AVStarted::getIsActivated() const
               {
                   return mIsActivated;
               }

               bool AVStarted::getIsGPU() const
               {
                   return mIsGPU;
               }

           }
       }
    }
}
