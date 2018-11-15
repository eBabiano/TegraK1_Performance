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
                  , mIsTimerRunning(false)
                {
                    ui->setupUi(this);

                 //   startTimer(0);
                 //   mTime = new QTime();
                }

                ControlPanelWidget::~ControlPanelWidget()
                {
                    delete ui;
                }

                void ControlPanelWidget::timerEvent(QTimerEvent *event)
                {
                    if (mIsTimerRunning)
                    {
                   //     ui->minLabel->setText(QDateTime::fromTime_t(10).toUTC().toString("hh:mm:ss"));
                   //     ui->secLabel->setText(std::to_string(mTime->elapsed()).c_str());
                    }
                }

                void ControlPanelWidget::on_playButton_clicked()
                {
                    notify(events::StartAVEvent(true));
                //    mTime->restart();
                    mIsTimerRunning = true;
                }

                void ControlPanelWidget::on_stopButton_clicked()
                {
                    notify(events::StartAVEvent(false));
                    mIsTimerRunning = false;
                }
            }
        }
    }
}
