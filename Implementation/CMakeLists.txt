cmake_minimum_required(VERSION 2.8)
project(FirstPrototype_Tegra)

find_package(Boost REQUIRED COMPONENTS system filesystem thread chrono)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(OpenCV REQUIRED)
find_package(OpenGL)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_FLAGS "-g -Wall -fPIC -std=c++11")
#SET(CMAKE_AUTOMOC ON)
#set(FLYCAPTURE2_LIB ${CMAKE_SOURCE_DIR}/lib/flycapture2)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE sources "src/application/*.cpp"
                          "src/application/*.hpp")

file(GLOB_RECURSE views "src/view/*.cpp"
                        "src/view/*.hpp")
file(GLOB_RECURSE widgets_headers "src/view/gui/*.hpp")
file(GLOB_RECURSE widgets_forms "src/view/gui/*.ui")

file(GLOB util "src/util/*.hpp"
               "src/util/*.cpp")

file(GLOB_RECURSE controller "src/controller/*.hpp"
                             "src/controller/*.cpp")

file(GLOB_RECURSE model "src/model/*.hpp"
                        "src/model/*.cpp")

qt5_wrap_ui(FORM_H ${widgets_forms})
qt5_wrap_cpp(HEADER_H ${widgets_headers})

ADD_LIBRARY(FirstPrototype_Tegra_CONFIG ${FORM_H} ${HEADER_H})
QT5_USE_MODULES(FirstPrototype_Tegra_CONFIG Widgets)

set(MAIN_SRC ${sources}
             ${views}
             ${widgets_headers}
             ${widgets_forms}
             ${util}
             ${controller}
             ${model})

#################### PROJECT DEPENDENCIES #######################################

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Gui_INCLUDE_DIRS})
include_directories(${Qt5OpenGL_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${FLYCAPTURE2_LIB})

add_executable(FirstPrototype_Tegra ${MAIN_SRC}
                                ${FORM_H}
                                ${HEADER_H})

QT5_USE_MODULES(FirstPrototype_Tegra Core Gui Widgets OpenGL)

target_link_libraries(FirstPrototype_Tegra   ${Qt5Core}
                                       ${Qt5Widgets}
                                       ${Qt5Gui}
                                       ${Qt5OpenGL}
                                       ${Boost_LIBRARIES}
                                       ${OpenCV_LIBS})

