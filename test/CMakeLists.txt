

add_subdirectory(./lib/googletest)

include_directories(./lib/googletest/include)

include_directories(./lib/googlemock/include)

set(SOURCE_TEST_FILES RunAllTests.cpp DateTest.cpp TaskTest.cpp)
add_executable(RunAllTests ${SOURCE_TEST_FILES})

target_link_libraries(RunAllTests gtest gtest_main core)



