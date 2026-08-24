#include "raylib.h"
#include <stdio.h>

const char ENGINE_NAME[13] = "Crap Engine";
int window_size_x = 800;
int window_size_y = 600;
float FPS = 60;

void input(void)
{
    
}

static inline void Engine_draw_shape(const int shape_type, const float radius_only_for_circle, const float radius_x, const float radius_y, const float pos_x, const float pos_y, const float size_x, const float size_y, const Color color)
{
    switch (shape_type)
    {
    case 2: 
    default: break;
    }
}

// FUNKCJA RYSUJĄCA KWADRAT/PROSTOKĄT
/**
 * @brief PARAMETRY FUNKCJI "Engine_draw_rectangle_shape"
 * @param pos_x pozycja koła w osi x
 * @param pos_y pozycja koła w osi y
 * @param size_x wielkość koła w osi x
 * @param size_y wielkość koła w osi y
 * @param color kolor koła
 */
static inline void Engine_draw_rectangle_shape(const float pos_x, const float pos_y, const float size_x, const float size_y, const Color color)
{
    DrawRectangle(pos_x, pos_y, size_x, size_y, color);
}

// FUNKCJA RYSUJĄCA KOŁA
/**
 * @brief PARAMETRY FUNKCJI "Engine_draw_circle_shape"
 * @param pos_x pozycja koła w osi x
 * @param pos_y pozycja koła w osi y
 * @param radius wielkość koła
 * @param color kolor koła
 */
static inline void Engine_draw_circle_shape(const float pos_x, const float pos_y, const float radius, const Color color)
{
    DrawCircle(pos_x, pos_y, radius, color);
}

// FUNKCJA RYSUJĄCA ELIPSY
/**
 * @brief PARAMETRY FUNKCJI "Engine_draw_ellipse_shape"
 * @param pos_x pozycja koła w osi x
 * @param pos_y pozycja koła w osi y
 * @param radius_x wielkość koła w osi x
 * @param radius_y wielkość koła w osi y
 * @param color kolor koła
 */
static inline void Engine_draw_ellipse_shape(const float pos_x, const float pos_y, const float radius_x, const float radius_y, const Color color)
{
    DrawEllipse(pos_x, pos_y, radius_x, radius_y, color);
}

// FUNKCJA RYSUJĄCA TEKST
/**
 * @brief PARAMETRY FUNKCJI "draw text"
 * @param text <b>wyświetlany tekst</b>
 * @param pos_x pozycja tekstu w osi x
 * @param pos_y pozycja tekstu w osi y
 * @param font_size wielkość tekstu
 * @param color kolor tekstu
 */
static inline void Engine_draw_text(const char text[], const float pos_x, const float pos_y, const float font_size, const Color color)
{
    DrawText(text, pos_x, pos_y, font_size, color);
}

// FUNKCJA PRINTUJĄCA FPSY W KONSOLI
void print_fps(void)
{
    printf("FPS: %d\n", GetFPS());
}

// FUNKCJA GŁÓWNA
int main(void)
{
    InitWindow(window_size_x, window_size_y, ENGINE_NAME);
    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        
        input();
        print_fps();

        BeginDrawing();
            ClearBackground(BLACK);

            Engine_draw_text("test", 200, 100, 50, RED);
            Engine_draw_circle_shape(100, 100, 50, RED);
            Engine_draw_ellipse_shape(200, 200, 150, 50, YELLOW);
            Engine_draw_rectangle_shape(300, 300, 50, 50, BLUE);
            Engine_draw_rectangle_shape(350, 320, 50, 70, PINK);

        EndDrawing();
    }
    
    CloseWindow();
}