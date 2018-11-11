#ifndef BENCHMARKINGWIDGET_HPP
#define BENCHMARKINGWIDGET_HPP

#include <src/view/gui/events/StartAVEvent.hpp>
#include <src/view/gui/container/Container.hpp>
#include <src/util/Observable.hpp>
#include <src/model/Benchmark.hpp>
#include <QWidget>


namespace Ui {
class BenchmarkingWidget;
}

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                class BenchmarkingWidget
                        : public QWidget
                        , public container::Container
                        , public util::Observer<model::events::BenchmarkUpdatedEvent>
                {
                    Q_OBJECT

                    public:
                        explicit BenchmarkingWidget(model::Benchmark &benchmark, const int& element, QWidget *parent = 0);
                        ~BenchmarkingWidget();

                    virtual void observableUpdated(const model::events::BenchmarkUpdatedEvent& event);

                    private:
                        Ui::BenchmarkingWidget *ui;
                        model::Benchmark* mBenchmark;

                };
            }
        }
    }
}

#endif // BENCHMARKINGWIDGET_HPP
