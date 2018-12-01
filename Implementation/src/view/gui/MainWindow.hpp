#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>

#include <src/controller/ModifyAlgorithmParametersController.hpp>

#include <src/view/gui/widgets/ModifyParametersWidget.hpp>
#include <src/view/gui/widgets/BenchmarkingWidget.hpp>
#include <src/view/gui/widgets/ControlPanelWidget.hpp>

#include <src/view/gui/videoplayer/VideoPlayer.hpp>
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
                explicit MainWindow(model::Benchmark &benchmark, model::av::AVManager &avManager
                                    , av::AVRenderManager &avRenderManager
                                    , videoplayer::VideoPlayer& videoPlayer
                                    , QWidget *parent = 0);
                virtual ~MainWindow();

                widgets::ControlPanelWidget* getControlPanel();
                widgets::BenchmarkingWidget* getBenchmarkingWidget();
                widgets::ModifyParametersWidget* getModifyParametersWidget();

                void setModifyAlgorithmParametersController(controller::ModifyAlgorithmParametersController& ModifyAlgorithmParametersController);

            public slots:
                void timerEvent(QTimerEvent *event);

            private:
                void initializeGUI();

                Ui::MainWindow *ui;
                src::view::gui::videoplayer::VideoPlayer* mVideoPlayer;
                src::view::av::AVRenderManager* mAVRenderManager;
                src::model::av::AVManager* mAVManager;
                src::model::Benchmark* mBenchmark;

                bool mFlipVert;
                bool mFlipHoriz;

                widgets::ModifyParametersWidget* mModifyParametersWidget;
                widgets::BenchmarkingWidget* mBenchmarkingWidget;
                widgets::ControlPanelWidget* mControlPanelWidget;
                cv::Mat mImage;

                bool mIsPainted;

            };
        }
    }
}

#endif // MAINWINDOW_HPP
