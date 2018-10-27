#include <src/view/gui/OpenGLCVPort.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            OpenGLCVPort::OpenGLCVPort(QWidget *parent)
                : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
                , mPixmap(NULL)
            {
            }

            OpenGLCVPort::~OpenGLCVPort()
            {

            }

            void OpenGLCVPort::setNewFrame(cv::Mat newframe)
            {
                QPixmap map = QPixmap::fromImage(QImage((unsigned char*) newframe.data,
                                                        newframe.cols,
                                                        newframe.rows,
                                                        QImage::Format_RGB888));
                mPixmap = &map;
                resizeEvent(0);
                update();
            }

            void OpenGLCVPort::resizeEvent(QResizeEvent *ev)
            {
                if (!mPixmap)
                    return;
                // determine scale of correct aspect-ratio
                float src_aspect = mPixmap->width()/(float)mPixmap->height();
                float dest_aspect = width()/(float)height();
                float w;	// new width
                if (src_aspect > dest_aspect)
                    w = width() - 1;
                else
                    w = height()*src_aspect - 1;
                mScale = w/mPixmap->width();
                mScaler = QTransform().scale(mScale, mScale);
                mScalerI = mScaler.inverted();
            }

            void OpenGLCVPort::paintEvent(QPaintEvent *ev)
            {
                QPainter painter(this);
                if (!mPixmap) {
                    painter.fillRect(this->rect(), QBrush(Qt::gray, Qt::BDiagPattern));
                    return;
                }
                painter.setRenderHint(QPainter::SmoothPixmapTransform);
                painter.setWorldTransform(mScaler);
                QRect damaged = mScalerI.mapRect(ev->rect());
                painter.drawPixmap(damaged, *mPixmap, damaged);
            }


        }
    }
}
