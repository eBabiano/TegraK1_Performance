#include <src/view/gui/widgets/av/OpticalFlowWidget.hpp>
#include "ui_OpticalFlowWidget.h"
//#include "ui_AVWidget.h"

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
                    OpticalFlowWidget::OpticalFlowWidget(const model::av::AVManager &avManager, QWidget *parent) :
                        AVWidget(avManager, parent) ,
                        ui(new Ui::OpticalFlowWidget)
                    {
                        ui->setupUi(this);
                    }

                    OpticalFlowWidget::~OpticalFlowWidget()
                    {
                        delete ui;
                    }

                 /*   void OpticalFlowWidget::init()
                    {
                        getParent()->parametersLayout->addWidget(this);
                    }*/
                }
            }
        }
    }
}
