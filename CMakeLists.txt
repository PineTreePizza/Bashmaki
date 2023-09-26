cmake_minimum_required(VERSION 3.12)

project(something VERSION 1.0)

add_executable(bashmaki src/main.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)

target_link_libraries(bashmaki SDL2::SDL2main SDL2::SDL2 SDL2_image::SDL2_image)
