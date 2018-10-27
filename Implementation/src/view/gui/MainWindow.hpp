#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>

#include <src/view/gui/widgets/ControlPanel.hpp>
#include <src/view/gui/widgets/BenchmarkingWidget.hpp>

#include <src/view/gui/OpenCVVideoPlayer.hpp>
#include <src/view/av/AVRenderManager.hpp>
#include <src/model/av/AVManager.hpp>
#include <src/model/Benchmark.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace Ui {
class MainWindow;
}

namespace src
{
    namespace view
    {
        namespace gui
        {
            class MainWindow : public QWidget
            {
                Q_OBJECT

            public:
                explicit MainWindow(model::Benchmark &benchmark, const model::av::AVManager& avManager
                                    , av::AVRenderManager &avRenderManager
                                    , src::view::gui::OpenCVVideoPlayer& videoPlayer
                                    , QWidget *parent = 0);
                virtual ~MainWindow();

                widgets::ControlPanel* getControlPanel();
                widgets::BenchmarkingWidget* getBenchmarkingWidget();

            protected:
                void timerEvent(QTimerEvent *event);

            private:
                void initializeGUI();

                Ui::MainWindow *ui;
                src::view::gui::OpenCVVideoPlayer* mVideoPlayer;
                src::view::av::AVRenderManager* mAVRenderManager;
                const src::model::av::AVManager* mAVManager;
                src::model::Benchmark* mBenchmark;

                bool mFlipVert;
                bool mFlipHoriz;

                widgets::ControlPanel* mControlPanel;
                widgets::BenchmarkingWidget* mBenchmarkingWidget;
                cv::Mat mImage;

                bool mIsPainted;

            };
        }
    }
}

#endif // MAINWINDOW_HPP
