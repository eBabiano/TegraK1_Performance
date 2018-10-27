#include <src/controller/av/SelectAVController.hpp>

namespace src
{
    namespace controller
    {
        namespace av
        {
            SelectAVController::SelectAVController(model::av::AVManager &avManager)
                : mAVManager(&avManager)
            {
            }

            void SelectAVController::observableUpdated(const view::gui::events::SelectAVEvent &event)
            {
                mAVManager->selectAV(event.getType());
                mAVManager->setIsGPU(event.getIsGPU());
            }
        }
    }
}
