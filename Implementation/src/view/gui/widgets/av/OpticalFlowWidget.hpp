#ifndef OPTICALFLOWWIDGET_HPP
#define OPTICALFLOWWIDGET_HPP

#include <QWidget>
#include <src/view/gui/widgets/av/AVWidget.hpp>

namespace Ui {
class OpticalFlowWidget;
}

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
                    class OpticalFlowWidget
                           : public AVWidget
                    {
                        Q_OBJECT

                    public:
                        explicit OpticalFlowWidget(const model::av::AVManager& avManager, QWidget *parent = 0);
                        ~OpticalFlowWidget();

                      //  virtual void init();

                    private:
                        Ui::OpticalFlowWidget *ui;
                    };
                }
            }
        }
    }
}

#endif // OPTICALFLOWWIDGET_HPP
