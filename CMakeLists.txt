cmake_minimum_required(VERSION 3.17)

project(game)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# PSP SDK
set(PSPDEV $ENV{PSPDEV})

file(GLOB SOURCES src/*.c src/*.cpp)

add_executable(game ${SOURCES})
target_include_directories(game PRIVATE include)


target_include_directories(game PRIVATE
    ${PSPDEV}/psp/include
    include
)

# Link with raylib
find_package(raylib REQUIRED)
target_link_libraries(game PUBLIC raylib)

create_pbp_file(
  TARGET game
  TITLE Flappy Bird PSP
  # ICON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/assets/sprites/bird/idle.png"
)

# file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
