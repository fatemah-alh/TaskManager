
add_subdirectory(./lib/googletest)

set(gtest_SOURCE_DIR, ./lib/googletest/)

INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})

set(SOURCE_TEST_FILES RunAllTests.cpp DateTest.cpp)
add_executable(RunAllTests.cpp ${SOURCE_TEST_FILES})

target_link_libraries(RunAllTests.cpp gtest gtest_main core)



