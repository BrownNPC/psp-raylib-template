cmake_minimum_required(VERSION 3.17)

project(game)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# PSP SDK
set(PSPDEV $ENV{PSPDEV})

# add sources
file(GLOB SOURCES CONFIGURE_DEPENDS src/*.c src/*.cpp)
add_executable(game ${SOURCES})

target_include_directories(game PRIVATE include/)

# Link with raylib
find_package(raylib REQUIRED)
target_link_libraries(game PUBLIC raylib)

# make clangd happy
file(GLOB GCC_INCLUDE_DIR "${PSPDEV}/lib/gcc/psp/*/include")
target_compile_options(game PRIVATE
    -isystem ${GCC_INCLUDE_DIR}
)

create_pbp_file(
  TARGET game
  TITLE change this in CMakeLists.txt
  ICON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/assets/icon.png"
  BUILD_PRX=1
  ENC_PRX=1
)

# Copy assets at build time
add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_SOURCE_DIR}/dist/psp/assets
)

# Copy the built EBOOT.PBP after building
add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_BINARY_DIR}/EBOOT.PBP
        ${CMAKE_CURRENT_SOURCE_DIR}/dist/psp/EBOOT.PBP
)
