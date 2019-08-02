cmake_minimum_required(VERSION 3.14)
project(ProgressBar)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED)

add_executable(ProgressBar main.cpp AbstractSubject.h Observer.h ProgressBar.cpp ProgressBar.h Button.h Button.cpp)
target_link_libraries(ProgressBar Qt5::Widgets)