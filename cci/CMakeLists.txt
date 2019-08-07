cmake_minimum_required(VERSION 3.10)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CCI_SOURCES
    src/cci.cpp
)

project(cci)
add_executable(${PROJECT_NAME} ${CCI_SOURCES})
add_compile_options("-g3" "-ggdb")
enable_testing()

