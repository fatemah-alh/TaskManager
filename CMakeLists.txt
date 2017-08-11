cmake_minimum_required(VERSION 3.6)
project(TaskManger)
add_subdirectory(Test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Task.cpp Task.h Date.cpp Date.h TaskList.cpp TaskList.h Color.h Tag.h ListView.cpp ListView.h Test/DateTest.cpp)
add_executable(TaskManger ${SOURCE_FILES} Task.cpp Task.h Date.cpp Date.h TaskList.cpp TaskList.h Color.h Test/DateTest.cpp)
add_library(core ${SOURCE_FILES} Test/DateTest.cpp Test/DateTest.cpp)
target_link_libraries(TaskManger core)