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
            if (Projects_tab_visible == 1)
            {
                Engine_draw_rectangle_shape(250, 0, 800, 600, DARKER_GRAY_COLOR);
                Engine_draw_text_better(font, "PROJECTS", (Vector2){260, 10}, (Vector2){0.0f, 0.0f}, 0.0f, 32.0f, 2.0f, WHITE);
            }

        EndDrawing();
    }
    Engine_texture_unloader();
    UnloadFont(font);
    CloseWindow();
}