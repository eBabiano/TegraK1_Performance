#ifndef AVMANAGER_HPP
#define AVMANAGER_HPP

#include <src/util/Observable.hpp>
#include <src/model/av/events/AVStarted.hpp>

#include <map>

namespace src
{
    namespace model
    {
        namespace av
        {
            class AVManager
                    : public util::Observable<events::AVStarted>
            {
                public:
                    AVManager();

                    std::string getSelectedType() const;
                    void selectAV(const std::string& type);
                    void play();
                    void stop();

                    bool getIsGPU() const;
                    void setIsGPU(bool value);

            private:
                    std::string mSelectedType;
                    bool mIsGPU;


                    using util::Observable<events::AVStarted>::notify;

            };
        }
    }
}

#endif // AVMANAGER_HPP
