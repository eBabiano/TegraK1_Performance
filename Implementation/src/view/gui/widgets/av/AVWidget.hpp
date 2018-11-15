#ifndef AVWidget_HPP
#define AVWidget_HPP

#include <src/model/av/AVManager.hpp>
#include <QWidget>

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
                    class AVWidget
                            : public QWidget
                    {
                        Q_OBJECT

                        public:
                            AVWidget(const model::av::AVManager& avManager, QWidget *parent = 0);

                            void hidden();

                    protected:
                            const model::av::AVManager* mAVManager;
                    };
                }
            }
        }
    }
}

#endif // AVWidget_HPP
