cmake_minimum_required(VERSION 3.14)
project(nagato_render CXX C)

set(CMAKE_CXX_STANDARD 17)

# ------------------------------------------------------------------------------
# nagato lib
include_directories(src/nagatolib/src)
add_subdirectory(src/nagatolib)

# ------------------------------------------------------------------------------
# lodepng lib
include_directories(src/lodepng)
file(GLOB LODEPNG_HEADER
        ${CMAKE_SOURCE_DIR}/src/lodepng/lodepng.h)
file(GLOB LODEPNG_SOURCE
        ${CMAKE_SOURCE_DIR}/src/lodepng/lodepng.cpp)
add_library(lodepng ${LODEPNG_HEADER} ${LODEPNG_SOURCE})

# ------------------------------------------------------------------------------
# compile option
set(CMAKE_CXX_FLAGS_RELEASE  "${CMAKE_CXX_FLAGS_RELEASE} -O3 -ffast-math -Wall")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -Wall")
message(STATUS "CXX release options : ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "CXX debug options : ${CMAKE_CXX_FLAGS_DEBUG}")

# ------------------------------------------------------------------------------
# nagato render

include_directories( ${CMAKE_SOURCE_DIR}/src/core )
include_directories( ${CMAKE_SOURCE_DIR}/src/images )
include_directories( ${CMAKE_SOURCE_DIR}/src/camera )
include_directories( ${CMAKE_SOURCE_DIR}/src/light )
include_directories( ${CMAKE_SOURCE_DIR}/src/object )
include_directories( ${CMAKE_SOURCE_DIR}/src/render )
include_directories( ${CMAKE_SOURCE_DIR}/src/color )
file(GLOB RENDER_HEADERS
        ${CMAKE_SOURCE_DIR}/src/images/*.hpp
        ${CMAKE_SOURCE_DIR}/src/core/*.hpp
        ${CMAKE_SOURCE_DIR}/src/camera/*.hpp
        ${CMAKE_SOURCE_DIR}/src/light/*.hpp
        ${CMAKE_SOURCE_DIR}/src/object/*.hpp
        ${CMAKE_SOURCE_DIR}/src/render/*.hpp
        ${CMAKE_SOURCE_DIR}/src/color/*.hpp
        ${CMAKE_SOURCE_DIR}/src/images/*.hpp
        )
file(GLOB RENDER_SOURCES
        ${CMAKE_SOURCE_DIR}/src/images/*.cpp
        ${CMAKE_SOURCE_DIR}/src/core/*.cpp
        ${CMAKE_SOURCE_DIR}/src/camera/*.cpp
        ${CMAKE_SOURCE_DIR}/src/light/*.cpp
        ${CMAKE_SOURCE_DIR}/src/object/*.cpp
        ${CMAKE_SOURCE_DIR}/src/render/*.cpp
        ${CMAKE_SOURCE_DIR}/src/color/*.cpp
        ${CMAKE_SOURCE_DIR}/src/images/*.cpp
        )
add_library(renderlib
        ${RENDER_HEADERS}
        ${RENDER_SOURCES})

# ------------------------------------------------------------------------------
# nagato render

add_executable(nagato_render main.cpp)
target_link_libraries(nagato_render
        nagato lodepng renderlib)
