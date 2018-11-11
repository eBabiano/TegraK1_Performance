#ifndef CONTROLPANELWIDGET_HPP
#define CONTROLPANELWIDGET_HPP

#include <src/view/gui/events/StartAVEvent.hpp>
#include <src/view/gui/container/Container.hpp>
#include <src/util/Observable.hpp>
#include <src/model/av/AVManager.hpp>

#include <QWidget>

namespace Ui {
class ControlPanelWidget;
}

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                class ControlPanelWidget
                        : public QWidget
                        , public container::Container
                        , public util::Observable<events::StartAVEvent>
                {
                    Q_OBJECT

                    public:
                        explicit ControlPanelWidget(const model::av::AVManager& model, const int &element, QWidget *parent = 0);
                        ~ControlPanelWidget();

                    private slots:
                        void on_playButton_clicked();
                        void on_stopButton_clicked();

                    private:
                            Ui::ControlPanelWidget *ui;

                            using util::Observable<events::StartAVEvent>::notify;
                };
            }
        }
    }
}

#endif // CONTROLPANELWIDGET_HPP