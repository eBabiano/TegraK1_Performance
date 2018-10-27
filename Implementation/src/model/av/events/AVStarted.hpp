#ifndef AVSTARTED_HPP
#define AVSTARTED_HPP

#include <string>

namespace src
{
    namespace model
    {
       namespace av
       {
           namespace events
           {
               class AVStarted
               {
                   public:
                       AVStarted(const std::string& type, bool activated, bool isGPU);

                       std::string getType() const;
                       bool getIsActivated() const;
                       bool getIsGPU() const;

                    private:
                       std::string mType;
                       bool mIsActivated;
                       bool mIsGPU;
               };
           }
       }
    }
}

#endif // AVSTARTED_HPP
