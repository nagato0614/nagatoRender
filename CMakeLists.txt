cmake_minimum_required(VERSION 3.13.4)
project(nagato_render CXX C)

set(CMAKE_CXX_STANDARD 17)

# ------------------------------------------------------------------------------
# Open MP
find_package(OpenMP REQUIRED)
if (OpenMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif ()

# ------------------------------------------------------------------------------
# open GL
find_package(OpenGL)

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
set(CMAKE_CXX_FLAGS_RELEASE  "${CMAKE_CXX_FLAGS_RELEASE} -O3 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -Wall")
message(STATUS "CXX release options : ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "CXX debug options : ${CMAKE_CXX_FLAGS_DEBUG}")

# ------------------------------------------------------------------------------
# nagato render

include_directories( ${CMAKE_SOURCE_DIR}/src/core )
include_directories( ${CMAKE_SOURCE_DIR}/src/images )
include_directories( ${CMAKE_SOURCE_DIR}/src/camera )
include_directories( ${CMAKE_SOURCE_DIR}/src/integrator )
include_directories( ${CMAKE_SOURCE_DIR}/src/light )
include_directories( ${CMAKE_SOURCE_DIR}/src/object )
include_directories( ${CMAKE_SOURCE_DIR}/src/render )
include_directories( ${CMAKE_SOURCE_DIR}/src/color )
include_directories( ${CMAKE_SOURCE_DIR}/src/gui )
include_directories( ${CMAKE_SOURCE_DIR}/src/material )
include_directories( ${CMAKE_SOURCE_DIR}/src/struct )
include_directories( ${CMAKE_SOURCE_DIR}/src/bxdf )
file(GLOB RENDER_HEADERS
        ${CMAKE_SOURCE_DIR}/src/images/*.hpp
        ${CMAKE_SOURCE_DIR}/src/core/*.hpp
        ${CMAKE_SOURCE_DIR}/src/camera/*.hpp
        ${CMAKE_SOURCE_DIR}/src/integrator/*.hpp
        ${CMAKE_SOURCE_DIR}/src/light/*.hpp
        ${CMAKE_SOURCE_DIR}/src/object/*.hpp
        ${CMAKE_SOURCE_DIR}/src/render/*.hpp
        ${CMAKE_SOURCE_DIR}/src/color/*.hpp
        ${CMAKE_SOURCE_DIR}/src/images/*.hpp
        ${CMAKE_SOURCE_DIR}/src/gui/*.hpp
        ${CMAKE_SOURCE_DIR}/src/material/*.hpp
        ${CMAKE_SOURCE_DIR}/src/struct/*.hpp
        ${CMAKE_SOURCE_DIR}/src/bxdf/*.hpp
        )
file(GLOB RENDER_SOURCES
        ${CMAKE_SOURCE_DIR}/src/images/*.cpp
        ${CMAKE_SOURCE_DIR}/src/core/*.cpp
        ${CMAKE_SOURCE_DIR}/src/camera/*.cpp
        ${CMAKE_SOURCE_DIR}/src/integrator/*.cpp
        ${CMAKE_SOURCE_DIR}/src/light/*.cpp
        ${CMAKE_SOURCE_DIR}/src/object/*.cpp
        ${CMAKE_SOURCE_DIR}/src/render/*.cpp
        ${CMAKE_SOURCE_DIR}/src/color/*.cpp
        ${CMAKE_SOURCE_DIR}/src/images/*.cpp
        ${CMAKE_SOURCE_DIR}/src/gui/*.cpp
        ${CMAKE_SOURCE_DIR}/src/material/*.cpp
        ${CMAKE_SOURCE_DIR}/src/struct/*.cpp
        ${CMAKE_SOURCE_DIR}/src/bxdf/*.cpp
        )
add_library(renderlib
        ${UI_HEADERS}
        ${RENDER_HEADERS}
        ${RENDER_SOURCES})

# ------------------------------------------------------------------------------
# nagato render

add_executable(nagato_render main.cpp)
target_link_libraries(nagato_render
        nagato
        lodepng
        renderlib
        )

# ------------------------------------------------------------------------------
# nagato render test

file(GLOB RENDER_TEST_SOURCES
        ${CMAKE_SOURCE_DIR}/src/test/*.cpp)
add_executable(
        nagato_render_test
        src/test/test.cpp
        ${RENDER_TEST_SOURCES}
)
target_link_libraries(nagato_render_test
        nagato
        lodepng
        renderlib
        gtest
        )