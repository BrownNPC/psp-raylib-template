cmake_minimum_required(VERSION 3.17)

project(game)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)

# PSP SDK
set(PSPDEV $ENV{PSPDEV})

file(GLOB SOURCES src/*.c src/*.cpp)

add_executable(game ${SOURCES})
target_include_directories(game PRIVATE include)

# Link with raylib
find_package(raylib REQUIRED)
target_link_libraries(game PUBLIC raylib)

create_pbp_file(
  TARGET game
  # CHANGE YOUR TITLE
  TITLE change this in CMakeLists.txt
  ICON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/assets/icon.png"
  BUILD_PRX=1
  ENC_PRX=1
)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
