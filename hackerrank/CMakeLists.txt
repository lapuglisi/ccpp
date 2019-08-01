cmake_minimum_required (VERSION 3.0)
project (swapnodes)
add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cpp)
enable_testing()
add_test(
  NAME ${PROJECT_NAME} 
  COMMAND sh -c "${CMAKE_CURRENT_SOURCE_DIR}/build/${PROJECT_NAME} < ${CMAKE_CURRENT_SOURCE_DIR}/in/${PROJECT_NAME}.in > ${CMAKE_CURRENT_SOURCE_DIR}/out/${PROJECT_NAME}.out "
)

add_test(
  NAME ${PROJECT_NAME}_verify
  COMMAND ${CMAKE_COMMAND} -E compare_files 
    ${CMAKE_CURRENT_SOURCE_DIR}/out/${PROJECT_NAME}.ok 
    ${CMAKE_CURRENT_SOURCE_DIR}/out/${PROJECT_NAME}.out
)

project (running_median)
add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cpp)
enable_testing()
add_test(
  NAME ${PROJECT_NAME} 
  COMMAND sh -c "${CMAKE_CURRENT_SOURCE_DIR}/build/${PROJECT_NAME} < ${CMAKE_CURRENT_SOURCE_DIR}/in/${PROJECT_NAME}.in"
)
