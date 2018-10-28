#include <src/view/gui/widgets/ControlPanel.hpp>
#include <src/view/gui/container/ViewElements.hpp>
#include <src/model/av/AVTypes.hpp>

#include "ui_ControlPanel.h"

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                ControlPanel::ControlPanel(const model::av::AVManager& model, const int &element, QWidget *parent) :
                    QWidget(parent),
                    ui(new Ui::ControlPanel)
                  , Container(element)
                  , mAVManager(&model)
                  , mAvSelected("")
                  , mIsGPU(false)
                {
                    ui->setupUi(this);

                    mStartButton = new elements::Button(container::ViewElements::PLAY_BUTTON);
                    mStopButton = new elements::Button(container::ViewElements::STOP_BUTTON);

                    addView(*this);
                    addView(*mStartButton);
                    addView(*mStopButton);

                    if (mAVManager->getSelectedType() == model::av::AVTypes::AV_CIRCLE)
                    {
                        ui->selectCircleButton->setCheckable(true);
                        ui->selectCircleButton->setChecked(true);
                    }

                    ui->gpuRadioButton->setChecked(false);
                    ui->cpuRadioButton->setChecked(true);
                }

                ControlPanel::~ControlPanel()
                {
                    delete ui;
                }

                void ControlPanel::on_selecCircleButton_clicked()
                {
                    mAvSelected = model::av::AVTypes::AV_CIRCLE;
                    notify(events::SelectAVEvent(mAvSelected, mIsGPU));
                }

                void ControlPanel::on_selectSquareButton_clicked()
                {
                    mAvSelected = model::av::AVTypes::AV_SQUARE;
                    notify(events::SelectAVEvent(mAvSelected, mIsGPU));
                }

                void ControlPanel::on_selectGpuButton_clicked()
                {
                    mAvSelected = model::av::AVTypes::AV_TEST_GPU_CPU;
                    notify(events::SelectAVEvent(mAvSelected, mIsGPU));
                }

                void ControlPanel::on_selectFaceDetect_clicked()
                {
                    mAvSelected = model::av::AVTypes::FACE_DETECTION;
                    notify(events::SelectAVEvent(mAvSelected, mIsGPU));
                }

                void ControlPanel::on_gpuRadioButton_toggled(bool checked)
                {
                    if (checked)
                    {
                        mIsGPU = true;
                        ui->cpuRadioButton->setChecked(false);
                    }
                    notify(events::SelectAVEvent(mAvSelected, mIsGPU));
                }

                void ControlPanel::on_cpuRadioButton_toggled(bool checked)
                {
                    if (checked)
                    {
                        mIsGPU = false;
                        ui->gpuRadioButton->setChecked(false);
                    }
                    notify(events::SelectAVEvent(mAvSelected, mIsGPU));
                }

                void ControlPanel::on_backgroundSubButton_clicked()
                {
                    mAvSelected = model::av::AVTypes::BACKGROUND_SUBTRACTOR;
                    notify(events::SelectAVEvent(mAvSelected, mIsGPU));
                }

                void ControlPanel::on_opticalFlowButton_clicked()
                {
                    mAvSelected = model::av::AVTypes::OPTICAL_FLOW;
                    notify(events::SelectAVEvent(mAvSelected, mIsGPU));
                }

                void ControlPanel::on_pedestrianDetectButton_clicked()
                {
                    mAvSelected = model::av::AVTypes::PEDESTRIAN_DETECTOR;
                    notify(events::SelectAVEvent(mAvSelected, mIsGPU));
                }
            }
        }
    }
}
