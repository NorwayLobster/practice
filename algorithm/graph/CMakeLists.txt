cmake_minimum_required(VERSION 3.5)
project(graph)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")
add_executable(testgraph_bin 
     graph.cc
     testGraph.cc
)

add_executable(kruskal_bin
     graph.cc
     mst/kruskal.cc
)

target_include_directories(kruskal_bin
     PUBLIC
          ${PROJECT_SOURCE_DIR}
)

add_executable(prim_bin
     graph.cc
     mst/prim.cc
)

target_include_directories(prim_bin
     PUBLIC
          ${PROJECT_SOURCE_DIR}
)