#define NOB_IMPLEMENTATION

#include "include/nob.h"

#include <stdio.h>
#include <string.h>

// Prints usage message
void print_usage() {
  const char *usage =
      "HOW TO USE:\n"
      "   1. First prepare the project:\n"
      "   ./nob prepare-psp\n"
      "   2. Compile:\n"
      "   ./nob build\n"
      "   3. Run the code from dist folder\n"
      "   4. recompile every time you make a change.\n"

      "Usage: ./nob [options]\n"
      "Options:\n"
      "  prepare-psp         Generate project for PSP using CMake\n"
      "  prepare-desktop     Generate project for current OS (linux, mac, "
      "bsd)\n"
      "  prepare-desktop-win Generate project for windows. Supports "
      "cross-compiling using mingw64\n"
      "  build         compile to dist folder\n"
      "  help          Show this help message\n"
      "  run           runs ./dist/desktop/game\n"
      "  run-win       runs ./dist/desktop/game.exe\n";
  printf(usage, "");
}

// Handles a single argument
// Return 1 = print usage.
void handle_arg(const char *arg, Nob_Cmd *cmd) {
  // ----- PREPARE PSP -----
  if (!strcmp(arg, "prepare-psp")) {
    nob_log(INFO, "Preparing PSP project");
    // copy PSP CMakeLists.txt
    nob_copy_file("./platforms/psp/CMakeLists.txt", "./CMakeLists.txt");
    // delete build directory
    nob_cmd_append(cmd, "rm", "-fr", "./build/");
    nob_cmd_run(cmd);
    // bootstrap with psp-cmake
    nob_cmd_append(cmd, "psp-cmake", "-B", "build");
    nob_cmd_run(cmd);
    // ----- PREPARE DESKTOP-----
  } else if (!strcmp(arg, "prepare-desktop")) {
    nob_log(INFO, "Preparing project current OS");
    // copy DESKTOP CMakeLists.txt
    nob_copy_file("./platforms/desktop/CMakeLists.txt", "./CMakeLists.txt");
    // delete build directory
    nob_cmd_append(cmd, "rm", "-fr", "./build/");
    nob_cmd_run(cmd);
    // bootstrap with cmake
    nob_cmd_append(cmd, "cmake", "-B", "build");
    nob_log(NOB_INFO, "THIS WILL DOWNLOAD STUFF. BE PATIENT");
    nob_cmd_run(cmd);
    // ----- PREPARE DESKTOP WIN-----
  } else if (!strcmp(arg, "prepare-desktop-win")) {
    nob_log(INFO, "Preparing project current OS");
    // copy DESKTOP CMakeLists.txt
    nob_copy_file("./platforms/desktop/CMakeLists.txt", "./CMakeLists.txt");
    // delete build directory
    nob_cmd_append(cmd, "rm", "-fr", "./build/");
    nob_cmd_run(cmd);
    // bootstrap with cmake + mingw64
    nob_cmd_append(
        cmd, "cmake", "-B", "build",
        "-DCMAKE_TOOLCHAIN_FILE=./platforms/desktop/toolchain-mingw64.cmake");
    nob_log(NOB_INFO, "THIS WILL DOWNLOAD STUFF. BE PATIENT");
    nob_cmd_run(cmd);
    // ----- BUILD -----
  } else if (!strcmp(arg, "build")) {
    nob_log(NOB_INFO, "Building...");
    // cd into build directory and run make
    nob_set_current_dir("build");
    nob_cmd_append(cmd, "make");
    if (!nob_cmd_run(cmd)) { // run make
      nob_log(NOB_ERROR, "failed to compile.");
      return;
    }
    // print tree of dist folder.
    nob_set_current_dir("..");
    nob_cmd_append(cmd, "tree", "dist");
    nob_cmd_run(cmd); // run tree
    // user experience :)
    nob_log(INFO, "Compiled to dist folder");
    // ----- BUInLD -----
  } else if (!strcmp(arg, "run")) {
    if (!nob_set_current_dir("./dist/desktop")) {
      nob_log(NOB_ERROR,
              "./dist/desktop not found. build for desktop first using ./nob "
              "prepare-desktop or ./nob prepare-desktop-win");
      print_usage();
      return;
    }
    // ----- HELP -----
  } else if (!strcmp(arg, "help")) {
    print_usage();
  } else {
    nob_log(INFO, "Unknown arg %s", arg);
    print_usage();
  }
}

int main(int argc, char **argv) {
  NOB_GO_REBUILD_URSELF(argc, argv);

  Nob_Cmd cmd = {0};

  // Show usage if no arguments
  if (argc == 1) {
    print_usage();
    return 0;
  }

  handle_arg(argv[1], &cmd);
  return 0;
}
