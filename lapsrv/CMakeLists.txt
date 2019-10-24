cmake_minimum_required(VERSION 3.0)
project(lapsrv)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

include_directories("${CMAKE_SOURCE_DIR}/inc")

set(SOURCES lapsrv.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
enable_testing()