cmake_minimum_required(VERSION 3.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Project HashTable
project(hashtable)
add_executable(${PROJECT_NAME} ${PROJECT_NAME}/${PROJECT_NAME}.cpp)
enable_testing()

# Project Algorithms
project(algorithms)
add_executable(${PROJECT_NAME} ${PROJECT_NAME}/${PROJECT_NAME}.cpp)
enable_testing()
