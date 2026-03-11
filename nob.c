#define NOB_IMPLEMENTATION

#include "include/nob.h"

#include <stdio.h>
#include <string.h>

// Prints usage message
void print_usage(const char *prog_name) {
  const char *usage = "Usage: %s [options]\n"
                      "Options:\n"
                      "  prepare-psp   Generate project for PSP using CMake\n"
                      "  build           Run the project\n"
                      "  help    Show this help message\n";
  printf(usage, prog_name);
}

// Handles a single argument
bool handle_arg(const char *arg, Nob_Cmd *cmd) {
  if (!strcmp(arg, "prepare-psp")) {
    nob_log(INFO, "Preparing PSP project");
    // copy PSP CMakeLists.txt
    nob_copy_file("./platforms/psp/CMakeLists.txt", "./CMakeLists.txt");
    // delete build directory
    nob_cmd_append(cmd, "rm", "-fr", "./build/");
    nob_cmd_run(cmd);
    // bootstrap with psp-cmake
    nob_cmd_append(cmd, "psp-cmake", "-B", "build");
  } else if (!strcmp(arg, "build")) {
    nob_log(INFO, "Building...");
    // cd into build directory and run make
    nob_set_current_dir("build");
    nob_cmd_append(cmd, "make");
  } else if (!strcmp(arg, "help")) {
    // print help
    print_usage("nob");
  } else {
    return false;
  }
  return true;
}

int main(int argc, char **argv) {
  NOB_GO_REBUILD_URSELF(argc, argv);

  Nob_Cmd cmd = {0};

  // Show usage if no arguments
  if (argc == 1) {
    print_usage(argv[0]);
    return 0;
  }

  if (!handle_arg(argv[1], &cmd)) {
    printf("Unknown option: %s\n", argv[1]);
    print_usage("nob");
    return 0;
  }

  // Run the built command
  if (!nob_cmd_run(&cmd))
    return 1;

  return 0;
}
