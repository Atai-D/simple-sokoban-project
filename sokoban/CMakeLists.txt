cmake_minimum_required(VERSION 3.26.4)
project(sokoban)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib CONFIG REQUIRED)
if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
elseif(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -fsanitize=address -fsanitize=undefined")
endif()

add_executable(sokoban src/sokoban.cpp src/globals.h src/levels.h src/player.h src/graphics.h src/images.h src/sounds.h)
target_link_libraries(sokoban PRIVATE raylib)
