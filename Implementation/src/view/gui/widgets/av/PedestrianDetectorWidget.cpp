#include <src/view/gui/widgets/av/PedestrianDetectorWidget.hpp>
#include "ui_PedestrianDetectorWidget.h"
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
                    PedestrianDetectorWidget::PedestrianDetectorWidget(const model::av::AVManager &avManager, QWidget *parent) :
                        AVWidget(avManager, parent) ,
                        ui(new Ui::PedestrianDetectorWidget)
                    {
                        ui->setupUi(this);
                    }

                    PedestrianDetectorWidget::~PedestrianDetectorWidget()
                    {
                        delete ui;
                    }

                  /*  void PedestrianDetectorWidget::init()
                    {
                        getParent()->parametersLayout->addWidget(this);
                    }*/
                }
            }
        }
    }
}
