// Import required psp boilerplate
#include "pspinit.h"

#include "raylib.h"
#include <print>
int main(void) {
  const int screenWidth = 480;
  const int screenHeight = 270;
  std::print("Hello, {}!\n", "world");
  InitWindow(screenWidth, screenHeight, "Flappy Bird");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    DrawText("Sigma", 5, 30, 22, RED);
    DrawFPS(5, 10);
    EndDrawing();
  }
}
