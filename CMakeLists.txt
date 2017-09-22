cmake_minimum_required(VERSION 3.6)
project(TaskManger)
add_subdirectory(Test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES main.cpp Task.cpp Task.h Date.cpp Date.h TaskList.cpp TaskList.h Color.h
        Tag.h ListView.cpp ListView.h Percent.cpp Percent.h
        Control.h GUITaskManager.cpp GUITaskManager.h
        GUITask.cpp GUITask.h GUIDate.cpp GUIDate.h GUIMoveTask.cpp GUIMoveTask.h GUIRemoveTask.cpp
        GUIRemoveTask.h main.h Control.cpp)
add_executable(TaskManger ${SOURCE_FILES} )
add_library(core ${SOURCE_FILES} Control.cpp)
target_link_libraries(TaskManger core ${wxWidgets_LIBRARIES})