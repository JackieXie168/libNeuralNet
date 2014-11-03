cmake_minimum_required(VERSION 2.6)

file(GLOB src source/*.cpp)
add_library(opennn ${src})

file(GLOB tinyxml2_src tinyxml2/*.cpp)
add_library(tinyxml2 ${tinyxml2_src})

add_executable(simple_function_regression examples/simple_function_regression/main.cpp)
target_link_libraries(simple_function_regression opennn)
target_link_libraries(simple_function_regression tinyxml2)
