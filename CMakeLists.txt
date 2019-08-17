cmake_minimum_required(VERSION 3.14)
project(ProgressBar)

include_directories(/usr/local/include/taglib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH "/opt/Qt/5.12.4/gcc_64/lib/cmake")

find_package(Qt5Widgets REQUIRED)

link_directories(/usr/local/lib)

add_executable(ProgressBar main.cpp AbstractSubject.h Observer.h Button.h Button.cpp TagReader.cpp TagReader.h ProgressDialog.cpp ProgressDialog.h ShowButton.cpp ShowButton.h)
target_link_libraries(ProgressBar Qt5::Widgets)
target_link_libraries(ProgressBar tag)