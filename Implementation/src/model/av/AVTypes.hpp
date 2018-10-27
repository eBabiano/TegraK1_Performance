#ifndef AVTYPES_HPP
#define AVTYPES_HPP

#include <string>

namespace src
{
    namespace model
    {
        namespace av
        {
            class AVTypes
            {
                public:
                    static const std::string AV_CIRCLE;
                    static const std::string AV_SQUARE;
                    static const std::string AV_TEST_GPU_CPU;
                    static const std::string FACE_DETECTION;
                    static const std::string BACKGROUND_SUBTRACTOR;
                    static const std::string OPTICAL_FLOW;

                    static const std::string CPU_DEVICE;
                    static const std::string GPU_DEVICE;

            };
        }
    }
}

#endif // AVTYPES_HPP
