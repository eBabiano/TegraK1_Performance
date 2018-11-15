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
                                   OpenCVVideoPlayer &videoPlayer,
                                   QWidget *parent) :
                QWidget(parent),
                ui(new Ui::MainWindow)
              , mVideoPlayer(&videoPlayer)
              , mAVRenderManager(&avRenderManager)
              , mAVManager(&avManager)
              , mBenchmark(&benchmark)
              , mIsPainted(false)
            {
                ui->setupUi(this);

                initializeGUI();
                mVideoPlayer->init();

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

            void MainWindow::timerEvent(QTimerEvent *event)
            {
                /*   if( mFlipVert && mFlipHoriz )
                       cv::flip( mImage,mImage, -1);
                   else if( mFlipVert )
                       cv::flip( mImage,mImage, 0);
                   else if( mFlipHoriz )
                       cv::flip( mImage,mImage, 1);*/


                   ///@todo SUM all the CV::MAT images
                   mAVRenderManager->setCaptureImage(mVideoPlayer->getCurrentFrame());
                   //std::cout << "FrAMES NUMBER: " << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_POS_FRAMES) << std::std::endl;
                 //  double tic = cvGetTickCount();

                 /*  if (!mIsPainted)
                   {
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_POS_MSEC) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_POS_FRAMES) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_POS_AVI_RATIO) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_FRAME_WIDTH) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_FRAME_HEIGHT) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_FPS) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_FOURCC) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_FRAME_COUNT) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_FORMAT) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_MODE) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_BRIGHTNESS) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_CONTRAST) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_SATURATION) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_HUE) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_GAIN) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_EXPOSURE) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_CONVERT_RGB) << std::endl;
                       std::cout << mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_RECTIFICATION) << std::endl;
                       mIsPainted = true;
                   }*/

                   //mAVRenderManager->setTotalFrames(mVideoPlayer->getVideoCapture().get(CV_CAP_PROP_FRAME_COUNT));
                   mAVRenderManager->sumAllAVImages();
           //        mImage = mImage + mAVRenderManager->getImageForRender();

                   // Show the image
                   //mVideoPlayer->runVideoPlayerInput();
                   mVideoPlayer->runVideoPlayerOutput(mAVRenderManager->getImageForRender(), false);
                   ///mBenchmarkingWidget->plot();

   /*                double toc = (cvGetTickCount() - tic) / cvGetTickFrequency();

                   toc = toc / 1000000;

                   float fps = 1 / toc;
                   std::cout << "FPS: " << fps << std::endl;*/
            }

        }
    }
}
