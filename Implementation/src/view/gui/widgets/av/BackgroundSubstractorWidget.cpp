#include <src/view/gui/widgets/av/BackgroundSubstractorWidget.hpp>
#include "ui_BackgroundSubstractorWidget.h"

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
                    BackgroundSubstractorWidget::BackgroundSubstractorWidget(const model::av::AVManager& avManager, QWidget *parent) :
                        AVWidget(avManager, parent),
                        ui(new Ui::BackgroundSubstractorWidget)
                    {
                        ui->setupUi(this);
                    }

                    BackgroundSubstractorWidget::~BackgroundSubstractorWidget()
                    {
                        delete ui;
                    }

                   /* void BackgroundSubstractorWidget::init()
                    {
                        getParent()->parametersLayout->addWidget(this);
                    }*/
                }
            }
        }
    }
}
