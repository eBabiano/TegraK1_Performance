#ifndef OPENGLCVPORT_HPP
#define OPENGLCVPORT_HPP

#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QtOpenGL>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <mutex>


namespace src
{
    namespace view
    {
        namespace gui
        {
            class OpenGLCVPort :
                    public QGLWidget
            {
                Q_OBJECT
            public:
                explicit OpenGLCVPort(QWidget *parent = 0);
                virtual ~OpenGLCVPort();

                void setNewFrame(cv::Mat newframe);

                void resizeEvent(QResizeEvent* ev);
                virtual void paintEvent(QPaintEvent* ev);

            private:
                cv::Mat mFrame;

                qreal mScale;
                QTransform mScaler;
                QTransform mScalerI;
                const QPixmap* mPixmap;
            };
        }
    }
}

#endif // OPENGLCVPORT_HPP
