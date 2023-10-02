cmake_minimum_required(VERSION 3.0.0)
project(vlad_03.0 VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM SOURCES ${PROJECT_SOURCE_DIR}/src/helloworld.cpp)

message(SOURCES="${SOURCES}")
add_executable(vlad_03.0 src/helloworld.cpp ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
