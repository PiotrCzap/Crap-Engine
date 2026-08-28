#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

const char ENGINE_NAME[13] = "Crap Engine";
char ENGINE_VERSION[16] = "Version: 0.0.1";
int window_size_x = 800;
int window_size_y = 600;
float FPS = 60.0f;
Color GRAY_COLOR = { 40, 40, 40, 255 };
Color DARK_GRAY_COLOR = { 30, 30, 30, 255 };
Color LIGHT_GRAY_COLOR = { 70, 70, 70, 255 };

Font font;

struct GameObject player;
struct GameObject test_text;

static inline void Engine_draw_rectangle_shape(const float pos_x, const float pos_y, const float size_x, const float size_y, const Color color);
static inline void Engine_draw_text_better(const Font font, const char text[], const Vector2 crap_engine_text_position, const Vector2 crap_engine_text_origin, const float rotation, const float font_size, const float spacing, const Color color);

// =================================================================================================
// Funkcje z GUI
// =================================================================================================

static inline void Project_window()
{
    Engine_draw_rectangle_shape(0, 0, 800, 600, GRAY_COLOR);
    Engine_draw_rectangle_shape(0, 0, 256, 600, DARK_GRAY_COLOR);
    Engine_draw_text_better(font, ENGINE_NAME, (Vector2){10.0f, 10.0f}, (Vector2){0.0f, 0.0f}, 0.0f, 32.0f, 2.0f, WHITE);
    Engine_draw_text_better(font, ENGINE_VERSION, (Vector2){10.0f, 580.0f}, (Vector2){0.0f, 0.0f}, 0.0f, 16.0f, 2.0f, WHITE);
    
}

// =================================================================================================
// Funkcje z Teksturami
// =================================================================================================

Texture2D null_txt;

static inline void Engine_texture_loader()
{
    null_txt = LoadTexture("src/Engine Data/null.png");
}

static inline void Engine_texture_unloader()
{
    UnloadTexture(null_txt);
}

// FUNKCJA RYSUJĄCA TEKSTURE
/**
 * @brief PARAMETRY FUNKCJI "Engine_draw_rectangle_shape_with_texture"
 * @param texture tekstura
 * @param pos_x pozycja tekstury w osi x
 * @param pos_y pozycja tekstury w osi y
 * @param size_x wielkość tekstury w osi x
 * @param size_y wielkość tekstury w osi y
 * @param rotation obrót tekstury
 * @param color kolor tekstury
 */
static inline void Engine_draw_rectangle_shape_with_texture(const Texture2D texture, const float pos_x, const float pos_y, const float size_x, const float size_y, float rotation, const Color color)
{
    Rectangle sourceRec = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
    Rectangle destRec = { pos_x, pos_y, size_x, size_y };
    Vector2 origin = { 0.0f, 0.0f };
    
    DrawTexturePro(texture, sourceRec, destRec, origin, rotation, color);
}

// =================================================================================================
// Standardowe Funkcje
// =================================================================================================

static inline void Engine_draw_text_better(const Font font, const char text[],const Vector2 crap_engine_text_position, const Vector2 crap_engine_text_origin, const float rotation, const float font_size, const float spacing, const Color color)
{
    DrawTextPro(font, text, crap_engine_text_position, crap_engine_text_origin, rotation, font_size, spacing, color);
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

// =================================================================================================
//
// =================================================================================================

// FUNKCJA PRINTUJĄCA FPSY W KONSOLI
void print_fps(void)
{
    printf("FPS: %d\n", GetFPS());
}

// =================================================================================================
// FUNKCJA GŁÓWNA
// =================================================================================================

int main(void)
{
    InitWindow(window_size_x, window_size_y, ENGINE_NAME);
    SetTargetFPS(FPS);
    Engine_texture_loader();
    

while (!WindowShouldClose())
{
        // ==========================================
        // UPDATE
        // ==========================================

        if (10 % 10 == 0)
        {
            print_fps();
        }

        // ==========================================
        // RENDER
        // ==========================================

        BeginDrawing();
            ClearBackground(BLACK);
            
            Project_window();

        EndDrawing();
    }
    Engine_texture_unloader();
    UnloadFont(font);
    CloseWindow();
}