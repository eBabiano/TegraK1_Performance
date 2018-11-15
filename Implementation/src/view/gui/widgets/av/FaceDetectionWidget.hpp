#ifndef FACEDETECTIONWIDGET_HPP
#define FACEDETECTIONWIDGET_HPP

#include <QWidget>
#include <src/view/gui/widgets/av/AVWidget.hpp>

namespace Ui {
class FaceDetectionWidget;
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
                    class FaceDetectionWidget
                            : public AVWidget
                    {
                        Q_OBJECT

                    public:
                        explicit FaceDetectionWidget(const model::av::AVManager& avManager, QWidget *parent = 0);
                        ~FaceDetectionWidget();

                      //  virtual void init();

                    private:
                        Ui::FaceDetectionWidget *ui;
                    };
                }
            }
        }
    }
}

#endif // FACEDETECTIONWIDGET_HPP
