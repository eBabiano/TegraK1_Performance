#include <src/view/av/AVRenderManager.hpp>

#include <src/view/av/AVCircle.hpp>
#include <src/view/av/AVRectangle.hpp>
#include <src/view/av/TestCudaGpu.hpp>
#include <src/view/av/FaceDetection.hpp>
#include <src/view/av/BackgroundSubtractor.hpp>
#include <src/view/av/OpticalFlow.hpp>

#include <src/model/av/AVTypes.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           AVRenderManager::AVRenderManager(model::av::AVManager &avManager,
                                            controller::UpdateBenchmarkController& updateBenchmarkController)
               : mAVManager(&avManager)
               , mImageForRender(cv::Mat::zeros(cv::Size(640, 480), CV_8UC3))
               , mSelectedAV(model::av::AVTypes::AV_CIRCLE)
           {
               mAVViews[model::av::AVTypes::AV_CIRCLE] = new view::av::AVCircle();
               mAVViews[model::av::AVTypes::AV_SQUARE] = new view::av::AVRectangle();
               mAVViews[model::av::AVTypes::AV_TEST_GPU_CPU] = new view::av::TestCudaGpu();
               mAVViews[model::av::AVTypes::FACE_DETECTION] = new view::av::FaceDetection();
               mAVViews[model::av::AVTypes::BACKGROUND_SUBTRACTOR] = new view::av::BackgroundSubtractor();
               mAVViews[model::av::AVTypes::OPTICAL_FLOW] = new view::av::OpticalFlow();

               mAVManager->attach(*this);

               for (auto& view : mAVViews)
               {
                   view.second->src::util::Observable<view::av::events::UpdateBenchmarkEvent>::attach(updateBenchmarkController);
               }
           }

           AVRenderManager::~AVRenderManager()
           {
               for (auto& av : mAVViews)
               {
                   delete av.second;
               }
           }

           void AVRenderManager::observableUpdated(const model::av::events::AVStarted &event)
           {
               mSelectedAV = event.getType();
               mAVViews.at(mSelectedAV)->activateGPU(event.getIsGPU());
               if (event.getIsActivated())
               {
                   mAVViews.at(mSelectedAV)->start();
               }
               else
               {
                   mAVViews.at(mSelectedAV)->stop();
               }
           }

           cv::Mat AVRenderManager::getImageForRender()
           {
               cv::Mat image;
               mImageForRender.copyTo(image);
               mImageForRender = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
               return image;
           }

           void AVRenderManager::sumAllAVImages()
           {
                mImageForRender = mImageForRender + mAVViews.at(mSelectedAV)->getImage();
           }

           void AVRenderManager::setCaptureImage(cv::Mat mat)
           {
                mAVViews.at(mSelectedAV)->setCapturedImage(mat);
           }

           void AVRenderManager::setTotalFrames(int value)
           {
               mAVViews.at(mSelectedAV)->setTotalFrames(value);
           }

       }
    }
}
