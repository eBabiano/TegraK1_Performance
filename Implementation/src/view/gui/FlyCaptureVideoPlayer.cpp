#include <src/view/gui/FlyCaptureVideoPlayer.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            FlyCaptureVideoPlayer::FlyCaptureVideoPlayer()
            {

            }

            void FlyCaptureVideoPlayer::init()
            {
                FlyCapture2::BusManager busManager;
                unsigned int numCameras;
                FlyCapture2::Error error = busManager.GetNumOfCameras(&numCameras);
                if (error != FlyCapture2::PGRERROR_OK)
                {
                    std::cout << "FlyCapture2 camera error detected" << std::endl;
                }
                else
                {
                    std::cout << "Number of cameras detected: " << numCameras << std::endl;

                    for (unsigned int i = 0; i < numCameras; i++)
                    {
                        FlyCapture2::PGRGuid guid;
                        error = busManager.GetCameraFromIndex(i, &guid);
                        if (error != FlyCapture2::PGRERROR_OK)
                        {
                            std::cout << "Error detected for camera " << i << std::endl;
                        }
                        runSingleCamera(guid, i);
                    }
                }
            }

            int FlyCaptureVideoPlayer::runSingleCamera(FlyCapture2::PGRGuid guid, int idxCam) {
                int ret = 0;
                FlyCapture2::Error error;
                FlyCapture2::Camera cam;

                // Connect to a camera
                error = cam.Connect(&guid);
                if (error != FlyCapture2::PGRERROR_OK) {
                    std::cout << "FlyCapture2 camera error detected" << std::endl;
                    ret = -1;
                }
                else {
                    // Get the camera information
                    FlyCapture2::CameraInfo camInfo;
                    error = cam.GetCameraInfo(&camInfo);
                    if (error != FlyCapture2::PGRERROR_OK) {
                        std::cout << "FlyCapture2 camera error detected" << std::endl;
                        ret = -1;
                    }
                    else {
                        ///printCameraInfo(&camInfo);
                        // Start capturing images
                        error = cam.StartCapture();
                        if (error != FlyCapture2::PGRERROR_OK) {
                            std::cout << "FlyCapture2 camera error detected" << std::endl;
                            ret = -1;
                        }
                        else {
                            //read frames from camera and wait for user commands
                            ret = readFramesFromCamera(&cam, idxCam);
                            // Stop capturing images
                            error = cam.StopCapture();
                            if (error != FlyCapture2::PGRERROR_OK) {
                                std::cout << "FlyCapture2 camera error detected" << std::endl;
                                ret = -1;
                            }
                            else {
                                // Disconnect the camera
                                error = cam.Disconnect();
                                if (error != FlyCapture2::PGRERROR_OK) {
                                    std::cout << "FlyCapture2 camera error detected" << std::endl;
                                    ret = -1;
                                }
                            }
                        }
                    }
                }
                return ret;
            }


            int FlyCaptureVideoPlayer::readFramesFromCamera(FlyCapture2::Camera *cam, int idxCam)
            {
                int ret = 0;
                FlyCapture2::Error error;
                FlyCapture2::Image rawImage;
                char key = 'V', nombreImagen[100], nombreVideo[100];
                FILE *pf_video = NULL;
                bool isRecording = false, fail = false;
                char windName[50];
                sprintf(windName, "Camera_%02d", idxCam);

                // Retrieve an image to get image size and allocate IplImage
                error = cam->RetrieveBuffer(&rawImage);
                if (error != FlyCapture2::PGRERROR_OK) {
                    std::cout << "FlyCapture2 camera error detected" << std::endl;
                    ret = -1;
                }
                else {

                    while (key != 'Q' && !fail) {
                        // Retrieve an image
                        error = cam->RetrieveBuffer(&rawImage);
                        if (error != FlyCapture2::PGRERROR_OK) {
                            std::cout << "FlyCapture2 camera error detected" << std::endl;
                            ret = -1;
                            fail = true;
                        }
                        else {
                            // Create a converted image
                            FlyCapture2::Image convertedImage;
                            // Convert the raw image
                            error = rawImage.Convert(FlyCapture2::PIXEL_FORMAT_MONO8, &convertedImage);
                            if (error != FlyCapture2::PGRERROR_OK) {
                                std::cout << "FlyCapture2 camera error detected" << std::endl;
                                ret = -1;
                                fail = true;
                            }
                            else {
                                /* TO DO...
                                     * 1. Convertir la imagen de opencv a 3 canales para poder pintar sobre ella en color
                                     * 2. Si se pulsa 'G' grabar en un archivo en formato RAW (con fwrite) dentro de la carpeta /dat/
                                     *    En este caso se dibujara un rectangulo de color rojo y la palabra REC
                                     *    en la imagen visualizada, no en la imagen que se graba.
                                     * 3. Si se pulsa 'S' salvar una imagen en formato PNG
                                     * 4. Cada vez que se grabe un video o una imagen se debe incrementar el contador correspondiente
                                     */
                                cv::Mat imgRead = cv::Mat(convertedImage.GetRows(),convertedImage.GetCols(),CV_8UC1,convertedImage.GetData());
                                cv::Mat imgReadColor;
                                cv::cvtColor(imgRead,imgReadColor,CV_GRAY2RGB);

                                char aux = cvWaitKey(10);
                                key = toupper(aux);
                                switch (key) {
                                case 'P':
                                    cvWaitKey(0);
                                    break;
                                case 'S':
                                    ///sprintf(nombreImagen, "./dat/imagen%04d.png", globalIndexImages++);
                                    ///cv::imwrite(string(nombreImagen), imgRead);
                                    ///printf("%s saved to disk\n",nombreImagen);
                                    break;
                                case 'G':
                                {
                                    if (!isRecording) {
                                      ///  sprintf(nombreVideo, "./dat/video%04d.raw", globalIndexVideo++);
                                      ///  pf_video = fopen(nombreVideo, "w");
                                        isRecording = true;
                                        printf("recording... %s\n",nombreVideo);
                                    }
                                    else {
                                        fclose(pf_video);
                                        pf_video = NULL;
                                        isRecording = false;
                                        printf("stop recording... %s\n",nombreVideo);
                                    }
                                    break;
                                }
                                }
                                if (isRecording) {
                                    fwrite(imgRead.data, imgRead.rows*imgRead.cols, sizeof (unsigned char), pf_video);
                                    cv::rectangle(imgReadColor,cv::Point(10,10),cv::Point(50,50),CV_RGB(255,0,0),CV_FILLED);
                                    cv::putText(imgReadColor, std::string("REC"), cvPoint(60, 50), cv::FONT_HERSHEY_COMPLEX_SMALL, 2.5, CV_RGB(255,0,0), 3);
                                }
                                cv::imshow(std::string(windName),imgReadColor);
                            }
                        }
                    }
                    if (pf_video != NULL)
                        fclose(pf_video);
                }
                return ret;
            }
        }
    }
}
