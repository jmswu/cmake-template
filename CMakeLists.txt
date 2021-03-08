cmake_minimum_required(VERSION 3.0)
project(example_test)       # project name
set(SRC_FOLDER src)         # source files folder
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${SRC_FOLDER}/*.cpp)
add_subdirectory(googletest)
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} pthread gtest gtest_main)
#set(GCC_COVERAGE_COMPILE_FLAGS "-Werror -Wall -Wextra -Wpointer-arith -Wcast-align -Wwrite-strings -Wswitch-default -Wunreachable-code -Winit-self -Wmissing-field-initializers -Wno-unknown-pragmas -Wstrict-prototypes -Wundef -Wold-style-definition -Wno-misleading-indentation")
set(GCC_COVERAGE_COMPILE_FLAGS "-Werror -Wall -Wextra -Wpointer-arith -Wcast-align -Wwrite-strings -Wswitch-default -Wunreachable-code -Winit-self -Wmissing-field-initializers -Wno-unknown-pragmas -Wundef -Wno-misleading-indentation")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS})
