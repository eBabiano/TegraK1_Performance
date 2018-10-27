#ifndef STARTAVCONTROLLER_HPP
#define STARTAVCONTROLLER_HPP

#include <src/model/av/AVManager.hpp>
#include <src/util/Observer.hpp>
#include <src/view/gui/events/StartAVEvent.hpp>

namespace src
{
    namespace controller
    {
        namespace av
        {
            class StartAVController
                    : public src::util::Observer<view::gui::events::StartAVEvent>
            {
                public:
                    StartAVController(model::av::AVManager &avManager);
                    virtual void observableUpdated(const view::gui::events::StartAVEvent& event);

                private:
                    src::model::av::AVManager* mAVManager;
            };
        }
    }
}

#endif // STARTAVCONTROLLER_HPP
