#include <src/view/gui/widgets/ModifyParametersWidget.hpp>
#include "ui_ModifyParametersWidget.h"

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                ModifyParametersWidget::ModifyParametersWidget(QWidget *parent) :
                    QWidget(parent),
                    ui(new Ui::ModifyParametersWidget)
                {
                    ui->setupUi(this);
                }

                ModifyParametersWidget::~ModifyParametersWidget()
                {
                    delete ui;
                }
            }
        }
    }
}
