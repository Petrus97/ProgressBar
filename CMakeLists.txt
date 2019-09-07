#CMAKE settings
cmake_minimum_required(VERSION 3.14)

#Project name
project(ProgressBar)

# Compile flag
set(CMAKE_CXX_STANDARD 14)

# Required Qt settings
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Qt5 Path
set(CMAKE_PREFIX_PATH "/opt/Qt/5.12.4/gcc_64/lib/cmake")

# Source Files
set(SOURCE_FILES
        AbstractSubject.cpp AbstractSubject.h
        Observer.h
        Button.cpp Button.h
        TagReader.cpp TagReader.h
        ProgressDialog.cpp ProgressDialog.h
        ShowButton.cpp ShowButton.h
        )

# Find the necessary Qt5 modules
find_package(Qt5Widgets REQUIRED)

# Find TagLib library
include_directories(/usr/local/include/taglib)
link_directories(/usr/local/lib)

# Src executable
add_executable(ProgressBar main.cpp
        AbstractSubject.cpp AbstractSubject.h
        Observer.h
        Button.cpp Button.h
        TagReader.cpp TagReader.h
        ProgressDialog.cpp ProgressDialog.h
        ShowButton.cpp ShowButton.h
        )

add_library(core ${SOURCE_FILES})

# Link libraries
target_link_libraries(ProgressBar Qt5::Widgets)
target_link_libraries(ProgressBar tag)
target_link_libraries(ProgressBar core)
target_link_libraries(core Qt5::Widgets)


# Test dir
link_directories(tests)
enable_testing()
add_subdirectory(tests)



