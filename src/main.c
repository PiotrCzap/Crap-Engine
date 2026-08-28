#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

const char ENGINE_NAME[13] = "Crap Engine";
int window_size_x = 800;
int window_size_y = 600;
float FPS = 60.0f;

struct GameObject player;
struct GameObject test_text;

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
    
    player.sprite_renderer.color = RED;
    player.transform.pos_x = 300;
    player.transform.pos_y = 300;
    player.transform.size_x = 100;
    player.transform.size_y = 100;
    player.sprite_renderer.visible = 1;
    
    test_text.text_renderer.text = "hello world!";
    test_text.text_renderer.font_size = 64;
    test_text.text_renderer.color = GREEN;
    test_text.transform.pos_x = 10;
    test_text.transform.pos_y = 10;
    test_text.text_renderer.visible = 1;

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
            Engine_draw_rectangle_shape_with_texture(null_txt, 100, 100, 100, 100, 0, WHITE);
            if (test_text.text_renderer.visible == 1)
            {
                Engine_draw_text(test_text.text_renderer.text, test_text.transform.pos_x, test_text.transform.pos_y, test_text.text_renderer.font_size, test_text.text_renderer.color);
            }
            if (player.sprite_renderer.visible == 1)
            {
                Engine_draw_rectangle_shape(player.transform.pos_x, player.transform.pos_y, player.transform.size_x, player.transform.size_y, player.sprite_renderer.color);
            }

        EndDrawing();
    }
    Engine_texture_unloader();
    CloseWindow();
}