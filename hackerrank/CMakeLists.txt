cmake_minimum_required (VERSION 3.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

project (pathfinder)
set(PROJECT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}")
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}.cpp)
enable_testing()
add_test(
  NAME ${PROJECT_NAME}_run
  COMMAND sh -c "${PROJECT_BINARY_DIR}/bin/${PROJECT_NAME}"
)

project (swapnodes)
set(PROJECT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}")
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}.cpp)
enable_testing()
add_test(
  NAME ${PROJECT_NAME}_run
  COMMAND sh -c "${PROJECT_BINARY_DIR}/bin/${PROJECT_NAME} < ${PROJECT_SOURCE_DIR}/tests/${PROJECT_NAME}.in"
)

add_test(
  NAME ${PROJECT_NAME}
  COMMAND sh -c "${PROJECT_BINARY_DIR}/bin/${PROJECT_NAME} < ${PROJECT_SOURCE_DIR}/tests/${PROJECT_NAME}.in > ${PROJECT_SOURCE_DIR}/tests/${PROJECT_NAME}.out"
)

add_test(
  NAME ${PROJECT_NAME}_verify
  COMMAND ${CMAKE_COMMAND} -E compare_files
    ${CMAKE_CURRENT_SOURCE_DIR}/out/${PROJECT_NAME}.ok 
    ${CMAKE_CURRENT_SOURCE_DIR}/out/${PROJECT_NAME}.out
)

project (running_median)
set(PROJECT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}")
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}.cpp)
enable_testing()
add_test(
  NAME ${PROJECT_NAME} 
  COMMAND sh -c "${PROJECT_BINARY_DIR}/bin/${PROJECT_NAME} < ${PROJECT_SOURCE_DIR}/tests/${PROJECT_NAME}.in > ${PROJECT_SOURCE_DIR}/tests/${PROJECT_NAME}.out"
)

project (breadth_first_search)
set(PROJECT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}")
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}.cpp)
enable_testing()
add_test(
  NAME ${PROJECT_NAME} 
  COMMAND sh -c "${PROJECT_BINARY_DIR}/bin/${PROJECT_NAME} < ${PROJECT_SOURCE_DIR}/tests/${PROJECT_NAME}.in > ${PROJECT_SOURCE_DIR}/tests/${PROJECT_NAME}.out"
)
