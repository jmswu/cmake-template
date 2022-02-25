cmake_minimum_required(VERSION 3.12)

project(my_poject)
set(UNIT_TEST_NAME "test_${PROJECT_NAME}")

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED true)

include_directories (includes)

set (APP_SRC_FOLDER src)
set (APP_SRC_FILES 
        "main.cpp"
        "${APP_SRC_FOLDER}/add.cpp"
    )

set (TEST_SRC_FOLDER unit_test)
set (TEST_SRC_FILES 
        "${TEST_SRC_FOLDER}/add_test.cpp"
        "${APP_SRC_FOLDER}/add.cpp"
    )



#file(GLOB_RECURSE SRC_CXX_FILES CMAKE_CONFIGURE_DEPENDS ${SRC_FOLDER}/*.cpp)
#file(GLOB_RECURSE SRC_C_FILES CMAKE_CONFIGURE_DEPENDS ${SRC_FOLDER}/*.c)

add_subdirectory (googletest)

add_executable (${PROJECT_NAME} ${APP_SRC_FILES})
add_executable (${UNIT_TEST_NAME} ${TEST_SRC_FILES})

target_link_libraries (${UNIT_TEST_NAME} pthread gtest gtest_main)

set (GCC_C_COVERAGE_COMPILE_FLAGS "-Os -Werror -Wall -Wextra -Wpointer-arith -Wcast-align -Wwrite-strings -Wswitch-default -Wunreachable-code -Winit-self -Wmissing-field-initializers -Wno-unknown-pragmas -Wstrict-prototypes -Wundef -Wold-style-definition -Wno-misleading-indentation")
set (GCC_CXX_COVERAGE_COMPILE_FLAGS "-Os -Werror -Wall -Wextra -Wpointer-arith -Wcast-align -Wwrite-strings -Wswitch-default -Wunreachable-code -Winit-self -Wmissing-field-initializers -Wno-unknown-pragmas -Wundef -Wno-misleading-indentation")

set (CMAKE_C_FLAGS ${CMAKE_C_FLAGS} ${GCC_C_COVERAGE_COMPILE_FLAGS})
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${GCC_CXX_COVERAGE_COMPILE_FLAGS})
