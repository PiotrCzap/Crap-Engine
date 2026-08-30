#include "main.hpp"


// =================================================================================================
// FUNKCJA GŁÓWNA
// =================================================================================================

int main(void)
{
    window_size_x = 800;
    window_size_y = 600;
    FPS = 60;
    InitWindow(window_size_x, window_size_y, ENGINE_NAME);
    window_icon = LoadImage("src/Engine Data/icon.png");
    SetWindowIcon(window_icon);
    SetTargetFPS(FPS);
    Engine_texture_loader();
    

while (!WindowShouldClose())
{
        // ==========================================
        // UPDATE
        // ==========================================

        print_fps();

        // ==========================================
        // RENDER
        // ==========================================

        BeginDrawing();
            ClearBackground(BLACK);
            Project_window();
            

        EndDrawing();
    }
    UnloadImage(window_icon);
    Engine_texture_unloader();
    UnloadFont(font);
    CloseWindow();
}