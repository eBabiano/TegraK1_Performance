#include <src/view/gui/MainWindow.hpp>
#include <src/view/gui/container/ViewElements.hpp>
#include "ui_MainWindow.h"

namespace src
{
    namespace view
    {
        namespace gui
        {
            MainWindow::MainWindow(model::Benchmark& benchmark,
                                   model::av::AVManager &avManager,
                                   av::AVRenderManager &avRenderManager,
                                   /*videoplayer::VideoPlayer& videoPlayer,*/
                                   QWidget *parent) :
                QWidget(parent),
                ui(new Ui::MainWindow)
              ///, mVideoPlayer(&videoPlayer)
              , mAVRenderManager(&avRenderManager)
              , mAVManager(&avManager)
              , mBenchmark(&benchmark)
              , mIsPainted(false)
            {
                ui->setupUi(this);

                initializeGUI();
                ///mVideoPlayer->init();

                mFlipVert=false;
                mFlipHoriz=false;

                startTimer(0);
            }

            MainWindow::~MainWindow()
            {
                delete ui;
            }

            void MainWindow::initializeGUI()
            {
                mModifyParametersWidget = new widgets::ModifyParametersWidget(*mAVManager, container::ViewElements::AV_WIDGET);
                ui->modifyParametersLayout->addWidget(mModifyParametersWidget, 0, 0);

                mBenchmarkingWidget = new widgets::BenchmarkingWidget(*mAVManager, *mBenchmark, container::ViewElements::BENCHMARKING_WIDGET);
                ui->benchmarkLayout->addWidget(mBenchmarkingWidget, 0, 0);

                mControlPanelWidget = new widgets::ControlPanelWidget(*mAVManager, container::ViewElements::CONTROL_PANEL);
                ui->controlPanelLayout->addWidget(mControlPanelWidget, 0, 0);
            }

            widgets::ControlPanelWidget *MainWindow::getControlPanel()
            {
                return mControlPanelWidget;
            }

            widgets::BenchmarkingWidget *MainWindow::getBenchmarkingWidget()
            {
                return mBenchmarkingWidget;
            }

            widgets::ModifyParametersWidget *MainWindow::getModifyParametersWidget()
            {
                return mModifyParametersWidget;
            }

            void MainWindow::setModifyAlgorithmParametersController(controller::ModifyAlgorithmParametersController &ModifyAlgorithmParametersController)
            {
                mModifyParametersWidget->setModifyAlgorithmParametersController(ModifyAlgorithmParametersController);
                mModifyParametersWidget->initAVParameters();
            }

            void MainWindow::timerEvent(QTimerEvent *event)
            {
                ///@todo SUM all the CV::MAT images
                ////mAVRenderManager->setCaptureImage(mVideoPlayer->getCurrentFrame());
                ////mAVRenderManager->sumAllAVImages();

                // Show the image
                ////mVideoPlayer->run(mAVRenderManager->getImageForRender());
            }

        }
    }
}
