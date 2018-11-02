#include <src/controller/UpdateBenchmarkController.hpp>

namespace src
{
    namespace controller
    {
        UpdateBenchmarkController::UpdateBenchmarkController(model::Benchmark& benchmark)
            : mBenchmark(&benchmark)
        {
        }

        void UpdateBenchmarkController::observableUpdated(const view::av::events::UpdateBenchmarkEvent &event)
        {
            mBenchmark->setProcessingTimeMillisec(event.getTimeProcMillis());
            mBenchmark->setFramesPerSec(event.getFPS());
        }
    }
}
