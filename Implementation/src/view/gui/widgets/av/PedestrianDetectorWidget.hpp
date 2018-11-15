#ifndef PEDESTRIANDETECTORWIDGET_HPP
#define PEDESTRIANDETECTORWIDGET_HPP

#include <QWidget>
#include <src/view/gui/widgets/av/AVWidget.hpp>

namespace Ui {
class PedestrianDetectorWidget;
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
                    class PedestrianDetectorWidget
                            : public AVWidget
                    {

                    public:
                        explicit PedestrianDetectorWidget(const model::av::AVManager& avManager, QWidget *parent = 0);
                        ~PedestrianDetectorWidget();

                      //  virtual void init();

                    private:
                        Ui::PedestrianDetectorWidget *ui;
                    };
                }
            }
        }
    }
}

#endif // PEDESTRIANDETECTORWIDGET_HPP
