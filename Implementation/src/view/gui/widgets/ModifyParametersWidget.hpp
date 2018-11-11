#ifndef ModifyParametersWidget_HPP
#define ModifyParametersWidget_HPP

#include <src/view/gui/events/SelectAVEvent.hpp>
#include <src/view/gui/container/Container.hpp>
#include <src/util/Observable.hpp>
#include <src/model/av/AVManager.hpp>
#include <QWidget>

namespace Ui {
    class ModifyParametersWidget;
}

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                class ModifyParametersWidget
                        : public QWidget
                        , public container::Container
                        , public util::Observable<events::SelectAVEvent>
                {
                    Q_OBJECT

                    public:
                        explicit ModifyParametersWidget(const model::av::AVManager& model, const int& element, QWidget *parent = 0);
                        ~ModifyParametersWidget();

                private slots:

                    void on_gpuRadioButton_toggled(bool checked);

                    void on_cpuRadioButton_toggled(bool checked);

                    void on_avListComboBox_activated(const QString &arg);

                private:
                        Ui::ModifyParametersWidget *ui;
                        const model::av::AVManager* mAVManager;

                        std::string mAvSelected;
                        bool mIsGPU;

                        using util::Observable<events::SelectAVEvent>::notify;
                };
            }
        }
    }
}

#endif // ModifyParametersWidget_HPP
