#include <src/model/av/AVManager.hpp>

#include <src/model/av/AVTypes.hpp>

namespace src
{
    namespace model
    {
        namespace av
        {
            AVManager::AVManager()
                : mSelectedType(AVTypes::AV_TEST_GPU_CPU)
                , mIsGPU(false)
            {
            }

            std::string AVManager::getSelectedType() const
            {
                return mSelectedType;
            }

            void AVManager::selectAV(const std::string &type)
            {
                mSelectedType = type;
            }

            void AVManager::play()
            {
                notify(events::AVStarted(mSelectedType, true, mIsGPU));
            }

            void AVManager::stop()
            {
                notify(events::AVStarted(mSelectedType, false, mIsGPU));
            }

            bool AVManager::getIsGPU() const
            {
                return mIsGPU;
            }
            
            void AVManager::setIsGPU(bool value)
            {
                mIsGPU = value;
            }
            
        }
    }
}
