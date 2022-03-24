cmake_minimum_required (VERSION 3.12)

project (my_project)
set (UNIT_TEST_NAME "${PROJECT_NAME}_test")
set (APP_NAME "${PROJECT_NAME}")

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED true)

set (TEST_SRC_FOLDER unit_test)
set (TEST_SRC_FILES 
        "${TEST_SRC_FOLDER}/add_test.cpp"
        "${TEST_SRC_FOLDER}/another_test.cpp"
    )

add_subdirectory (third-party/googletest)

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
    list(
        APPEND CMAKE_CXX_CPPCHECK 
            "--enable=warning"
            "--inconclusive"
            "--force" 
            "--inline-suppr"
            "--suppressions-list=${CMAKE_SOURCE_DIR}/CppCheckSuppressions.txt"
    )
endif()

find_program(CMAKE_CXX_CLANG_TIDY NAMES clang-tidy)
if (CMAKE_CXX_CLANG_TIDY)
    list(
        APPEND CMAKE_CXX_CLANG_TIDY 
            "-header-filter=."
            #"-checks=*"
            #"-warnings-as-errors=*"
    )
endif()

#use in clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_subdirectory(my_lib)
add_executable (${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} my_lib)

add_executable (${UNIT_TEST_NAME} ${TEST_SRC_FILES})
target_link_libraries (${UNIT_TEST_NAME} pthread gtest gtest_main my_lib)

set (GCC_C_COVERAGE_COMPILE_FLAGS "-Os -Werror -Wall -Wextra -Wpointer-arith -Wcast-align -Wwrite-strings -Wswitch-default -Wunreachable-code -Winit-self -Wmissing-field-initializers -Wno-unknown-pragmas -Wstrict-prototypes -Wundef -Wold-style-definition -Wno-misleading-indentation")
set (GCC_CXX_COVERAGE_COMPILE_FLAGS "-Os -Werror -Wall -Wextra -Wpointer-arith -Wcast-align -Wwrite-strings -Wswitch-default -Wunreachable-code -Winit-self -Wmissing-field-initializers -Wno-unknown-pragmas -Wundef -Wno-misleading-indentation")

set (CMAKE_C_FLAGS ${CMAKE_C_FLAGS} ${GCC_C_COVERAGE_COMPILE_FLAGS})
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${GCC_CXX_COVERAGE_COMPILE_FLAGS})

