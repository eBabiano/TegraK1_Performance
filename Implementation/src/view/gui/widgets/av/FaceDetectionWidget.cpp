#include <src/view/gui/widgets/av/FaceDetectionWidget.hpp>
#include "ui_FaceDetectionWidget.h"

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                namespace av
                {
                    FaceDetectionWidget::FaceDetectionWidget(const model::av::AVManager &avManager, QWidget *parent) :
                        AVWidget(avManager, parent)
                        , ui(new Ui::FaceDetectionWidget)
                    {
                        ui->setupUi(this);
                    }

                    FaceDetectionWidget::~FaceDetectionWidget()
                    {
                        delete ui;
                    }

                 /*   void FaceDetectionWidget::init()
                    {
                        getParent()->parametersLayout->addWidget(this);
                    }*/
                }
            }
        }
    }
}
