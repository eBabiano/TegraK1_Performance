#include <src/model/Benchmark.hpp>
#include <src/model/av/AVTypes.hpp>

namespace src
{
    namespace model
    {
        Benchmark::Benchmark()
            : mProcessingTimeMillisec(0.0)
            , mFramesPerSec(0)
            , mIsGPU(false)
        {
        }
        double Benchmark::getProcessingTimeMillisec() const
        {
            return mProcessingTimeMillisec;
        }

        void Benchmark::setProcessingTimeMillisec(double value)
        {
            mProcessingTimeMillisecVector.push_back(mProcessingTimeMillisec);
            mProcessingTimeMillisec = value;
            notify(events::BenchmarkUpdatedEvent());
        }
        int Benchmark::getFramesPerSec() const
        {
            return mFramesPerSec;
        }

        void Benchmark::setFramesPerSec(int value)
        {
            mFramesPerSec = value;
        }

        int Benchmark::getFrames() const
        {
            return mFrames;
        }

        void Benchmark::setFrames(int value)
        {
            mFrames = value;
        }

        double Benchmark::getWeightedAverageProcessingTimeMillisec()
        {
            double acumValue = 0.0;
            int size = mProcessingTimeMillisecVector.size();
            for (int i = 0; i < size; i++)
            {
                acumValue = mProcessingTimeMillisecVector.at(i) + acumValue;
            }

            mProcessingTimeMillisecVector.clear();
            return acumValue / size;
        }

        void Benchmark::setWeightedAverageProcessingTimeMillisec(double value)
        {
            mWeightedAverageProcessingTimeMillisec = value;
        }
        bool Benchmark::getIsPlaying() const
        {
            return mIsPlaying;
        }

        void Benchmark::setIsPlaying(bool value)
        {
            mIsPlaying = value;
        }
        bool Benchmark::getIsGPU() const
        {
            return mIsGPU;
        }

        void Benchmark::setIsGPU(bool value)
        {
            mIsGPU = value;
        }


    }
}
