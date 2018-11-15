#ifndef BackgroundSubstractorWidget_HPP
#define BackgroundSubstractorWidget_HPP

#include <QWidget>
#include <src/view/gui/widgets/av/AVWidget.hpp>

namespace Ui {
class BackgroundSubstractorWidget;
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
                    class BackgroundSubstractorWidget
                            : public AVWidget
                    {
                        Q_OBJECT

                    public:
                        explicit BackgroundSubstractorWidget(const model::av::AVManager& avManager, QWidget *parent = 0);
                        ~BackgroundSubstractorWidget();

                        //virtual void init();

                    private:
                        Ui::BackgroundSubstractorWidget *ui;
                    };
                }
            }
        }
    }
}

#endif // BackgroundSubstractorWidget_HPP
