#include <iostream>

#include <src/model/av/AVManager.hpp>
#include <src/model/Benchmark.hpp>

#include <src/view/gui/OpenGLCVPort.hpp>
#include <src/view/gui/MainWindow.hpp>
#include <src/view/gui/OpenCVVideoPlayer.hpp>
#include <src/view/gui/events/StartAVEvent.hpp>
#include <src/view/gui/events/SelectAVEvent.hpp>
#include <src/view/av/AVRenderManager.hpp>

#include <src/controller/av/StartAVController.hpp>
#include <src/controller/av/SelectAVController.hpp>
#include <src/controller/UpdateBenchmarkController.hpp>

#include <src/util/Observer.hpp>

#include <QApplication>

int main(int argc, char* argv[])
{

    int exitCode = -13;

    std::cout << "Running..." << std::endl;

    //Models
    src::model::av::AVManager* mAVManager = new src::model::av::AVManager();
    src::model::Benchmark* mBenchmark = new src::model::Benchmark();

    //Controllers
    src::controller::av::StartAVController* mStartAVController = new src::controller::av::StartAVController(*mAVManager);
    src::controller::av::SelectAVController* mSelectAVController = new src::controller::av::SelectAVController(*mAVManager);
    src::controller::UpdateBenchmarkController* mUpdateBenchmarkController = new src::controller::UpdateBenchmarkController(*mBenchmark);

    //Views
    src::view::av::AVRenderManager* mAVRenderManager = new src::view::av::AVRenderManager(*mAVManager, *mUpdateBenchmarkController);

    QApplication app(argc, argv);
    src::view::gui::OpenCVVideoPlayer* videoPlayer = new src::view::gui::OpenCVVideoPlayer(0, "Input Video", "Output Video");
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    src::view::gui::MainWindow* mainWindow = new src::view::gui::MainWindow(*mBenchmark, *mAVManager, *mAVRenderManager, *videoPlayer);

    //LINKERS
    mainWindow->getControlPanel()->src::util::Observable<src::view::gui::events::SelectAVEvent>::attach(*mSelectAVController);
    mainWindow->getBenchmarkingWidget()->src::util::Observable<src::view::gui::events::StartAVEvent>::attach(*mStartAVController);
 //   mainWindow->getControlPanel()->attach(*mStartAVRectangleController);

    mainWindow->show();

    exitCode = app.exec();

    if (exitCode == 0)
    {
       delete mAVRenderManager;
    }
    return exitCode;

}
