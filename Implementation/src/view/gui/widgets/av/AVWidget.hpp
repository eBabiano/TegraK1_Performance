#ifndef AVWidget_HPP
#define AVWidget_HPP

#include <QWidget>

namespace Ui {
    class AVWidget;
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
                    class AVWidget : public QWidget
                    {
                        Q_OBJECT

                        public:
                            explicit AVWidget(QWidget *parent = 0);
                            ~AVWidget();

                        private:
                            Ui::AVWidget *ui;
                    };
                }
            }
        }
    }
}

#endif // AVWidget_HPP
