cmake_minimum_required(VERSION 3.5.1)
project(terminalRunner)

set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(SOURCE_FILES main.cpp Game.cpp Game.h Player.cpp Player.h Obstacle.cpp Obstacle.h Entity.h)
add_executable(terminalRunner ${SOURCE_FILES})

target_link_libraries(terminalRunner ${CURSES_LIBRARIES})