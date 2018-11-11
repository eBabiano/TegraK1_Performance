#include <src/view/gui/widgets/ModifyParametersWidget.hpp>
#include <src/view/gui/container/ViewElements.hpp>
#include <src/model/av/AVTypes.hpp>

#include "ui_ModifyParametersWidget.h"

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                ModifyParametersWidget::ModifyParametersWidget(const model::av::AVManager& model, const int &element, QWidget *parent) :
                    QWidget(parent),
                    ui(new Ui::ModifyParametersWidget)
                  , Container(element)
                  , mAVManager(&model)
                  , mAvSelected(model.getSelectedType())
                  , mIsGPU(false)
                {
                    ui->setupUi(this);

                    addView(*this);

                    ui->avListComboBox->addItem(QIcon(), model::av::AVTypes::BACKGROUND_SUBTRACTOR.c_str());
                    ui->avListComboBox->addItem(QIcon(), model::av::AVTypes::FACE_DETECTION.c_str());
                    ui->avListComboBox->addItem(QIcon(), model::av::AVTypes::OPTICAL_FLOW.c_str());
                    ui->avListComboBox->addItem(QIcon(), model::av::AVTypes::PEDESTRIAN_DETECTOR.c_str());

                    ui->gpuRadioButton->setChecked(false);
                    ui->cpuRadioButton->setChecked(true);
                }

                ModifyParametersWidget::~ModifyParametersWidget()
                {
                    delete ui;
                }

                void ModifyParametersWidget::on_gpuRadioButton_toggled(bool checked)
                {
                    if (checked)
                    {
                        mIsGPU = true;
                        ui->cpuRadioButton->setChecked(false);
                    }
                    notify(events::SelectAVEvent(mAvSelected, mIsGPU));
                }

                void ModifyParametersWidget::on_cpuRadioButton_toggled(bool checked)
                {
                    if (checked)
                    {
                        mIsGPU = false;
                        ui->gpuRadioButton->setChecked(false);
                    }
                    notify(events::SelectAVEvent(mAvSelected, mIsGPU));
                }

                void ModifyParametersWidget::on_avListComboBox_activated(const QString &arg)
                {
                    mAvSelected = arg.toUtf8().constData();
                    notify(events::SelectAVEvent(mAvSelected, mIsGPU));
                }
            }
        }
    }
}


