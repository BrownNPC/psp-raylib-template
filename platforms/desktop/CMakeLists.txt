# from https://github.com/raysan5/raylib/blob/master/projects/CMake/CMakeLists.txt
cmake_minimum_required(VERSION 3.17)

project(game)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# PSP SDK
set(PSPDEV $ENV{PSPDEV})

# add sources
file(GLOB SOURCES CONFIGURE_DEPENDS src/*.c src/*.cpp)
add_executable(game ${SOURCES})

target_include_directories(game PRIVATE include/)

# Link with raylib
set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/external")
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
  endif()
endif()
target_link_libraries(game PUBLIC raylib)

# Copy assets at build time
add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_SOURCE_DIR}/dist/desktop/assets
)
set(EXECUTABLE_NAME game)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(EXECUTABLE_NAME game.exe)
endif()

# Copy the built game executable after building
add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_BINARY_DIR}/${EXECUTABLE_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/dist/desktop/${EXECUTABLE_NAME}
)
