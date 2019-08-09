cmake_minimum_required(VERSION 3.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Project Studies
project(studies)
set(${PROJECT_NAME}_SOURCES 
    algorithms/algorithms.cpp 
    algorithms/union_find.cpp
    hash_table/hash_table.cpp 
    linked_list/linked_list.cpp
    tree/tree.cpp
    graph/graph.cpp
    studies.cpp)

add_compile_options("-g3" "-ggdb")
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
enable_testing()

# Project Amazon
project(amazon)
set(${PROJECT_NAME}_SOURCES
    amazon/amazon.cpp)

add_compile_options("-g3" "-ggdb")
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
enable_testing()