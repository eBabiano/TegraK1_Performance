#ifndef CONTROLPANEL_HPP
#define CONTROLPANEL_HPP

#include <src/view/gui/events/SelectAVEvent.hpp>
#include <src/view/gui/container/Container.hpp>
#include <src/view/gui/elements/Button.hpp>
#include <src/util/Observable.hpp>
#include <src/model/av/AVManager.hpp>
#include <QWidget>

namespace Ui {
class ControlPanel;
}

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                class ControlPanel
                        : public QWidget
                        , public container::Container
                        , public util::Observable<events::SelectAVEvent>
                {
                    Q_OBJECT

                    public:
                        explicit ControlPanel(const model::av::AVManager& model, const int& element, QWidget *parent = 0);
                        ~ControlPanel();

                private slots:

                    void on_selectGpuButton_clicked();

                    void on_selectFaceDetect_clicked();

                    void on_gpuRadioButton_toggled(bool checked);

                    void on_cpuRadioButton_toggled(bool checked);

                    void on_backgroundSubButton_clicked();

                    void on_opticalFlowButton_clicked();

                    void on_pedestrianDetectButton_clicked();

                private:
                        elements::Button* mStartButton;
                        elements::Button* mStopButton;

                        Ui::ControlPanel *ui;
                        const model::av::AVManager* mAVManager;

                        std::string mAvSelected;
                        bool mIsGPU;

                        using util::Observable<events::SelectAVEvent>::notify;
                };
            }
        }
    }
}

#endif // CONTROLPANEL_HPP
