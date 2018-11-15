#ifndef ModifyParametersWidget_HPP
#define ModifyParametersWidget_HPP

#include <src/view/gui/events/SelectAVEvent.hpp>
#include <src/view/gui/container/Container.hpp>
#include <src/view/gui/widgets/av/AVWidget.hpp>
#include <src/util/Observable.hpp>
#include <src/model/av/AVManager.hpp>
#include <src/model/av/events/AVSelectedEvent.hpp>
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
                        , public util::Observer<model::av::events::AVSelectedEvent>
                {
                    Q_OBJECT

                    public:
                        explicit ModifyParametersWidget(model::av::AVManager& model, const int& element, QWidget *parent = 0);
                        ~ModifyParametersWidget();

                    virtual void observableUpdated(const model::av::events::AVSelectedEvent& event);

                private slots:
                    void on_avListComboBox_activated(const QString &arg);

                private:
                        void initAVParameters();

                        Ui::ModifyParametersWidget *ui;
                        model::av::AVManager* mAVManager;

                        std::string mAvSelected;
                        bool mIsGPU;

                        std::map<std::string, av::AVWidget*> mAVWidgetVector;
                        using util::Observable<events::SelectAVEvent>::notify;
                };
            }
        }
    }
}

#endif // ModifyParametersWidget_HPP
