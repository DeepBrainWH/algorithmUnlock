set(OpenCV_DIR /home/wangheng/app/opencv/share/OpenCV)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(ml-main1 main.cc)
target_link_libraries(ml-main1 ${OpenCV_LIBS})