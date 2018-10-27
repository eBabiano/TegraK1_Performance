#include <src/view/gui/widgets/BenchmarkingWidget.hpp>
#include "ui_BenchmarkingWidget.h"

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
                    ui->tpProccesing->setText(std::to_string(mBenchmark->getProcessingTimeMillisec()).c_str());
                }

                void BenchmarkingWidget::on_playButton_clicked()
                {
                    notify(events::StartAVEvent(true));
                }

                void BenchmarkingWidget::on_stopButton_clicked()
                {
                    notify(events::StartAVEvent(false));
                    ui->tpWeightedCPU->setText(std::to_string(mBenchmark->getWeightedAverageProcessingTimeMillisec()).c_str());
                }
            }
        }
    }
}
