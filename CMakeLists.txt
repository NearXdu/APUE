cmake_minimum_required(VERSION 2.6)

PROJECT (APUE)

set(CMAKE_C_FLAGS "-O0 -ggdb -pthread")
set(CMAKE_C_COMPILER "gcc")


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

SET(SRC_DIR ../src)
add_library(error ${SRC_DIR}/error.c)
add_library(mask ${SRC_DIR}/mask.c)


add_executable(time ${SRC_DIR}/time.c)
add_executable(environment ${SRC_DIR}/environment.c)
add_executable(fork ${SRC_DIR}/fork.c)
add_executable(bad_vfork ${SRC_DIR}/bad_vfork.c)
add_executable(vfork ${SRC_DIR}/vfork.c)
add_executable(wait ${SRC_DIR}/wait.c)
add_executable(fork_twice ${SRC_DIR}/fork_twice.c)
add_executable(ls ${SRC_DIR}/ls.c)
add_executable(signal ${SRC_DIR}/signal.c)
add_executable(reenter ${SRC_DIR}/reentrant.c)
target_link_libraries(reenter ${PROJECT_BINARY_DIR}/lib/liberror.a)
add_executable(raise ${SRC_DIR}/raise.c)
add_executable(sigsets ${SRC_DIR}/sigsets.c)
target_link_libraries(sigsets ${PROJECT_BINARY_DIR}/lib/liberror.a)
target_link_libraries(sigsets ${PROJECT_BINARY_DIR}/lib/libmask.a)

add_executable(sigaction ${SRC_DIR}/sigaction.c)
add_executable(signal_by_sigaction ${SRC_DIR}/signal_by_sigaction.c)
add_executable(system ${SRC_DIR}/system.c)

add_executable(tid ${SRC_DIR}/tid.c)

add_executable(thread_exit ${SRC_DIR}/thread_exit.c)
