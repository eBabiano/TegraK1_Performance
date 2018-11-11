#include <src/view/gui/widgets/ControlPanelWidget.hpp>
#include "ui_ControlPanelWidget.h"

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                ControlPanelWidget::ControlPanelWidget(const model::av::AVManager& model, const int &element, QWidget *parent) :
                    QWidget(parent),
                    ui(new Ui::ControlPanelWidget)
                  , Container(element)
                {
                    ui->setupUi(this);
                }

                ControlPanelWidget::~ControlPanelWidget()
                {
                    delete ui;
                }

                void ControlPanelWidget::on_playButton_clicked()
                {
                    notify(events::StartAVEvent(true));
                }

                void ControlPanelWidget::on_stopButton_clicked()
                {
                    notify(events::StartAVEvent(false));
                }
            }
        }
    }
}
