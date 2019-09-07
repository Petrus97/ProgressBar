cmake_minimum_required(VERSION 3.14)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt5Test REQUIRED)
set(TEST_SRC TestProgressDialog.h run_test.cpp TestProgressDialog.cpp TestTagReader.cpp TestTagReader.h)
add_executable(test_runner ${TEST_SRC})

target_link_libraries(test_runner Qt5::Test core tag)

