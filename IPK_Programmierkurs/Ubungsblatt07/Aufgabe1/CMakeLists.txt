cmake_minimum_required(VERSION 3.5)

project(shapes)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

add_library(shapeslib point.cc polygon.cc)

add_executable(main main.cc point.cc polygon.cc)
target_link_libraries(main PUBLIC shapeslib)

enable_testing()

add_executable(shapestest polygontest.cc)
target_link_libraries(shapestest PUBLIC shapeslib)
add_test(NAME shapestest COMMAND test)
