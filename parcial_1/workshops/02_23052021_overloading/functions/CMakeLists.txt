cmake_minimum_required(VERSION 3.0.0)
project(fn_overloading VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(fn_overloading main.cpp operation.h operation.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
