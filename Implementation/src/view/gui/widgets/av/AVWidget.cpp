#include <src/view/gui/widgets/av/AVWidget.hpp>
#include "ui_AVWidget.h"

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
                    AVWidget::AVWidget(QWidget *parent) :
                        QWidget(parent),
                        ui(new Ui::AVWidget)
                    {
                        ui->setupUi(this);
                    }

                    AVWidget::~AVWidget()
                    {
                        delete ui;
                    }
                }
            }
        }
    }
}
