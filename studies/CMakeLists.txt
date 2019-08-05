cmake_minimum_required(VERSION 3.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(SOURCES 
    algorithms/algorithms.cpp 
    hash_table/hash_table.cpp 
    linked_lists/linked_lists.cpp
    studies.cpp)

# Project Studies
project(studies)
add_executable(${PROJECT_NAME} ${SOURCES})
enable_testing()