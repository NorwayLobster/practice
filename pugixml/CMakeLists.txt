cmake_minimum_required(VERSION 3.5)
project(pugixml)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEX2" CACHE STRING "Set C++ Compiler Flags" FORCE)

# try conditional compilation
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

# check results and add flag
if(COMPILER_SUPPORTS_CXX17)#
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(COMPILER_SUPPORTS_CXX11)#
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)#
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

find_package(Boost 1.46.1 REQUIRED COMPONENTS regex system filesystem)

# check if boost was found
if(Boost_FOUND)
    message ("boost found")
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()

add_executable(${PROJECT_NAME} 
  src/main.cc  
  src/pugixml.cpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  # ${Boost_LIBRARIES}// link all library
  ${Boost_REGEX_LIBRARY}
  # ${Boost_SYSTEM_LIBRARY}// link specific library
  # ${Boost_FILESYSTEM_LIBRARY}
    # Boost::regex
    # Boost::system
    # Boost::filesystem
)



target_include_directories(${PROJECT_NAME}
  PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
)