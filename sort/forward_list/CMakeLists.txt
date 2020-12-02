cmake_minimum_required(VERSION 3.6.0)
project(forward_list)
add_executable(forward_list_bin main.cc myforward_list.cc)
target_include_directories(forward_list_bin 
    PUBLIC
      ${PROJECT_SOURCE_DIR}
)