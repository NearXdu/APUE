cmake_minimum_required(VERSION 2.6)

PROJECT (APUE)

set(CMAKE_C_FLAGS "-O0 -ggdb")
set(CMAKE_C_COMPILER "gcc")


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

SET(SRC_DIR ../src)
add_executable(time ${SRC_DIR}/time.c)
add_executable(environment ${SRC_DIR}/environment.c)
add_executable(fork ${SRC_DIR}/fork.c)
add_executable(bad_vfork ${SRC_DIR}/bad_vfork.c)
add_executable(vfork ${SRC_DIR}/vfork.c)
