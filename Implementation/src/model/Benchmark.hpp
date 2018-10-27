#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <string>
#include <src/util/Observable.hpp>
#include <src/model/events/BenchmarkUpdatedEvent.hpp>

namespace src
{
    namespace model
    {
        class Benchmark
                : public util::Observable<events::BenchmarkUpdatedEvent>
        {
            public:
                Benchmark();

                double getProcessingTimeMillisec() const;
                void setProcessingTimeMillisec(double value);

                int getFramesPerSec() const;
                void setFramesPerSec(int value);

                int getFrames() const;
                void setFrames(int value);

                double getWeightedAverageProcessingTimeMillisec();
                void setWeightedAverageProcessingTimeMillisec(double value);

                bool getIsPlaying() const;
                void setIsPlaying(bool value);

                bool getIsGPU() const;
                void setIsGPU(bool value);

            private:
                double mProcessingTimeMillisec;
                int mFramesPerSec;
                bool mIsGPU;

                int mFrames;
                double mWeightedAverageProcessingTimeMillisec;
                bool mIsPlaying;

                std::vector<double> mProcessingTimeMillisecVector;

                using util::Observable<events::BenchmarkUpdatedEvent>::notify;

        };
    }
}

#endif // BENCHMARK_HPP
