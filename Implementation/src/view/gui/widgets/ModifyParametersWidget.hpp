#ifndef MODIFYPARAMETERSWIDGET_HPP
#define MODIFYPARAMETERSWIDGET_HPP

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
                class ModifyParametersWidget : public QWidget
                {
                    Q_OBJECT

                    public:
                        explicit ModifyParametersWidget(QWidget *parent = 0);
                        ~ModifyParametersWidget();

                    private:
                        Ui::ModifyParametersWidget *ui;
                };
            }
        }
    }
}

#endif // MODIFYPARAMETERSWIDGET_HPP
