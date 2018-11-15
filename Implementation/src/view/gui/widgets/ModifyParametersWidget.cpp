#include <src/view/gui/widgets/ModifyParametersWidget.hpp>
#include <src/view/gui/container/ViewElements.hpp>
#include <src/view/gui/widgets/av/BackgroundSubstractorWidget.hpp>
#include <src/view/gui/widgets/av/FaceDetectionWidget.hpp>
#include <src/view/gui/widgets/av/OpticalFlowWidget.hpp>
#include <src/view/gui/widgets/av/PedestrianDetectorWidget.hpp>
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
                ModifyParametersWidget::ModifyParametersWidget(model::av::AVManager& model, const int &element, QWidget *parent) :
                    QWidget(parent),
                    ui(new Ui::ModifyParametersWidget)
                  , Container(element)
                  , mAVManager(&model)
                  , mAvSelected(model.getSelectedType())
                  , mIsGPU(false)
                {
                    ui->setupUi(this);

                    addView(*this);

                    initAVParameters();

                    ui->avListComboBox->addItem(QIcon(), model::av::AVTypes::BACKGROUND_SUBTRACTOR.c_str());
                    ui->avListComboBox->addItem(QIcon(), model::av::AVTypes::FACE_DETECTION.c_str());
                    ui->avListComboBox->addItem(QIcon(), model::av::AVTypes::OPTICAL_FLOW.c_str());
                    ui->avListComboBox->addItem(QIcon(), model::av::AVTypes::PEDESTRIAN_DETECTOR.c_str());

                    mAVManager->src::util::Observable<model::av::events::AVSelectedEvent>::attach(*this);
                }

                ModifyParametersWidget::~ModifyParametersWidget()
                {
                    delete ui;
                }

                void ModifyParametersWidget::observableUpdated(const model::av::events::AVSelectedEvent &event)
                {
                    mAVWidgetVector.at(mAvSelected)->setVisible(false);
                    mAvSelected = event.getType();

                    for (auto& widget : mAVWidgetVector)
                    {
                        if (widget.first == mAvSelected)
                        {
                            widget.second->setVisible(true);
                        }
                    }
                }

                void ModifyParametersWidget::on_avListComboBox_activated(const QString &arg)
                {
                    notify(events::SelectAVEvent(arg.toUtf8().constData(), mIsGPU));
                }

                void ModifyParametersWidget::initAVParameters()
                {
                    mAVWidgetVector[src::model::av::AVTypes::BACKGROUND_SUBTRACTOR] = new av::BackgroundSubstractorWidget(*mAVManager);
                    mAVWidgetVector[src::model::av::AVTypes::FACE_DETECTION] = new av::FaceDetectionWidget(*mAVManager);
                    mAVWidgetVector[src::model::av::AVTypes::OPTICAL_FLOW] = new av::OpticalFlowWidget(*mAVManager);
                    mAVWidgetVector[src::model::av::AVTypes::PEDESTRIAN_DETECTOR] = new av::PedestrianDetectorWidget(*mAVManager);

                    for (auto& widget : mAVWidgetVector)
                    {
                        ui->modifyParamLayout->addWidget(widget.second);
                        if (widget.first != mAvSelected)
                        {
                            widget.second->setVisible(false);
                        }
                    }
                }
            }
        }
    }
}


