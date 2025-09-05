// Import required psp boilerplate
#include "pspinit.h"
#include "raylib.h"
int main(void) {
  // 2.6x smaller than 1280x720
  const int screenWidth = 480;
  const int screenHeight = 270;

  InitWindow(screenWidth, screenHeight, "Change this in main.cpp");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    DrawText("Hello World", 5, 30, 22, RED);
    DrawFPS(5, 10);
    EndDrawing();
  }
}
