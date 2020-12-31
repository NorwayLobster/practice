cmake_minimum_required(VERSION 3.5)
project(graph)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")
add_executable(testGraph_bin 
     graph.cc
     testGraph.cc
)