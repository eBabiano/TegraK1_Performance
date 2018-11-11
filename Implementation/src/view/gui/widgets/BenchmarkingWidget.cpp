#include <src/view/gui/widgets/BenchmarkingWidget.hpp>
#include "ui_BenchmarkingWidget.h"
#include <src/util/String.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                BenchmarkingWidget::BenchmarkingWidget(model::Benchmark &benchmark, const int& element, QWidget *parent)
                    : QWidget(parent)
                    , ui(new Ui::BenchmarkingWidget)
                    , Container(element)
                    , mBenchmark(&benchmark)
                {
                    ui->setupUi(this);

                    mBenchmark->attach(*this);
                }

                BenchmarkingWidget::~BenchmarkingWidget()
                {
                    delete ui;
                }

                void BenchmarkingWidget::observableUpdated(const model::events::BenchmarkUpdatedEvent &event)
                {
                    std::string proccessigTime = util::String::getFixed(mBenchmark->getProcessingTimeMillisec(), 2);
                    std::string fps = std::to_string(mBenchmark->getFramesPerSec());
                    ui->tpProccesing->setText(proccessigTime.c_str());
                    ui->fps->setText(fps.c_str());
                }


           /*         std::string averageProccessigTime = util::String::getFixed(mBenchmark->getWeightedAverageProcessingTimeMillisec(), 2);
                    std::string fpsTime = std::to_string(mBenchmark->getWeightedAverageFramesPerSeconds());

                    ui->tpWeighted->setText(averageProccessigTime.c_str());
                    ui->fpsWeighted->setText(fpsTime.c_str());*/

            }
        }
    }
}
