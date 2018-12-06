#include <iostream>

#include <src/model/av/AVManager.hpp>
#include <src/model/Benchmark.hpp>

#include <src/view/gui/MainWindow.hpp>
#include <src/view/gui/videoplayer/VideoPlayerManager.hpp>

#include <src/view/gui/events/StartAVEvent.hpp>
#include <src/view/gui/events/SelectAVEvent.hpp>
#include <src/view/av/AVRenderManager.hpp>

#include <src/controller/av/StartAVController.hpp>
#include <src/controller/av/SelectAVController.hpp>
#include <src/controller/UpdateBenchmarkController.hpp>
#include <src/controller/ModifyAlgorithmParametersController.hpp>

#include <src/util/Observer.hpp>

#include <QApplication>

static cv::Point2f point;
static bool addRemovePt;

void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        point = cv::Point2f((float) x, (float) y);
        addRemovePt = true;
    }
}

int main(int argc, char* argv[])
{

    int exitCode = -13;
    std::string videoCaptureOption = "";
    videoCaptureOption = std::string(argv[1]);

    std::cout << "Running..." << std::endl;

    //Models
    src::model::av::AVManager* mAVManager = new src::model::av::AVManager();
    src::model::Benchmark* mBenchmark = new src::model::Benchmark();

    //Controllers
    src::controller::av::StartAVController* mStartAVController = new src::controller::av::StartAVController(*mAVManager);
    src::controller::av::SelectAVController* mSelectAVController = new src::controller::av::SelectAVController(*mAVManager);
    src::controller::UpdateBenchmarkController* mUpdateBenchmarkController = new src::controller::UpdateBenchmarkController(*mBenchmark);
    src::controller::ModifyAlgorithmParametersController* mModifyAlgorithmParametersController = new src::controller::ModifyAlgorithmParametersController(*mAVManager);

    //Views
    src::view::av::AVRenderManager* mAVRenderManager = new src::view::av::AVRenderManager(*mAVManager, *mUpdateBenchmarkController);

    QApplication app(argc, argv);
   /// std::string windowOutput = "Output Video";
    src::view::gui::videoplayer::VideoPlayerManager* videoPlayerManager = new src::view::gui::videoplayer::VideoPlayerManager(videoCaptureOption);
    ///cv::setMouseCallback(windowOutput, onMouse, NULL);
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    src::view::gui::MainWindow* mainWindow;

    mainWindow = new src::view::gui::MainWindow(*mBenchmark, *mAVManager, *mAVRenderManager/*, *videoPlayerFlyCapture*/);

    mainWindow->setModifyAlgorithmParametersController(*mModifyAlgorithmParametersController);

    //LINKERS
    mainWindow->getControlPanel()->src::util::Observable<src::view::gui::events::StartAVEvent>::attach(*mStartAVController);
    mainWindow->getModifyParametersWidget()->src::util::Observable<src::view::gui::events::SelectAVEvent>::attach(*mSelectAVController);
 //   mainWindow->getControlPanel()->attach(*mStartAVRectangleController);

    mainWindow->show();

    exitCode = app.exec();

    if (exitCode == 0)
    {
       delete mAVRenderManager;
    }
    return exitCode;

}
