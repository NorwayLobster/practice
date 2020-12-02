cmake_minimum_required(VERSION 3.6.0)
project(forward_list)
# 设置C++标准为 C++ 11
set(CMAKE_CXX_STANDARD 11)
# 编译选项
add_definitions("-Wall -g")

# add_executable(forward_list_bin quicksort_forwardlist.cc myforward_list.cc)

add_executable(forward_list_bin selectionsort_forwardlist.cc myforward_list.cc)

target_include_directories(forward_list_bin PUBLIC ${PROJECT_SOURCE_DIR})