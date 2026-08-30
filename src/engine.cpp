#include <stdio.h>
#include "main.hpp"

int window_size_x = 800;
int window_size_y = 600;
const char* ENGINE_NAME = "Crap Engine\0";
const char* ENGINE_VERSION = "Version: 0.0.1\0";
int FPS = 60;

int Projects_tab_visible = 0;

Color LIGHT_GRAY_COLOR = { 60, 60, 60, 255 };
Color GRAY_COLOR = { 50, 50, 50, 255 };
Color DARK_GRAY_COLOR = { 40, 40, 40, 255 };
Color DARKER_GRAY_COLOR = { 30, 30, 30, 255 };

Font font;

struct GameObject player;
struct GameObject test_text;

// FUNKCJA RYSUJĄCA TEKSTURE
/**
 * @brief PARAMETRY FUNKCJI "Engine_button"
 * @param action akcja wywoływana przez przycisk
 * @param text tekst na przycisku
 * @param pos_x pozycja tekstury w osi x
 * @param pos_y pozycja tekstury w osi y
 * @param text_pos_x pozycja tekstu w osi x
 * @param text_pos_y pozycja tekstu w osi y
 * @param size_x wielkość tekstury w osi x
 * @param size_y wielkość tekstury w osi y
 * @param rotation obrót tekstury
 * @param color kolor tekstury
 */
void Engine_button(ButtonAction action, const char text[], const float pos_x, const float pos_y, const float text_pos_x, const float text_pos_y, const float size_x, const float size_y)
{
    Vector2 mouse_pos = GetMousePosition();
    Rectangle button = { pos_x, pos_y, size_x, size_y }; // Użyj przekazanych pozycji i rozmiarów!
    
    Color button_color_normal = LIGHT_GRAY_COLOR;
    Color button_color_hovered = GRAY_COLOR;
    Color button_color_clicked = DARKER_GRAY_COLOR;
    Color button_current_color = button_color_normal;

    if (CheckCollisionPointRec(mouse_pos, button))
    {
        button_current_color = button_color_hovered;

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            button_current_color = button_color_clicked;
            if (action != nullptr) 
                action();
        }
    }
    
    DrawRectangleRec(button, button_current_color);
    Engine_draw_text_better(font, text, (Vector2){text_pos_x, text_pos_y}, (Vector2){0.0f, 0.0f}, 0.0f, 24.0f, 2.0f, WHITE);
}

// =================================================================================================
// Funkcje z Teksturami
// =================================================================================================

void Engine_texture_loader(void)
{
    null_txt = LoadTexture("src/Engine Data/null.png");
}
void Engine_texture_unloader(void)
{
    UnloadTexture(null_txt);
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
void Engine_draw_rectangle_shape(const float pos_x, const float pos_y, const float size_x, const float size_y, const Color color)
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
void Engine_draw_circle_shape(const float pos_x, const float pos_y, const float radius, const Color color)
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
void Engine_draw_ellipse_shape(const float pos_x, const float pos_y, const float radius_x, const float radius_y, const Color color)
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
void Engine_draw_text(const char text[], const float pos_x, const float pos_y, const float font_size, const Color color)
{
    DrawText(text, pos_x, pos_y, font_size, color);
}

// FUNKCJA RYSUJĄCA LEPSZY TEKST
/**
 * @brief PARAMETRY FUNKCJI "draw text"
 * @param font czcionka tekstu
 * @param text wyświetlany tekst
 * @param crap_engine_text_position pozycja tekstu > przykład: (Vector2){x, y}
 * @param crap_engine_text_origin punkt centralny tekstu > przykład: (Vector2){x, y}
 * @param rotation obrót tekstu
 * @param font_size wielkość tekstu
 * @param spacing odstępy między literami
 * @param color kolor tekstu
 */
void Engine_draw_text_better(const Font font, const char text[], const Vector2 crap_engine_text_position, const Vector2 crap_engine_text_origin, const float rotation, const float font_size, const float spacing, const Color color)
{
    DrawTextPro(font, text, crap_engine_text_position, crap_engine_text_origin, rotation, font_size, spacing, color);
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
void Engine_draw_rectangle_shape_with_texture(const Texture2D texture, const float pos_x, const float pos_y, const float size_x, const float size_y, float rotation, const Color color)
{
    Rectangle sourceRec = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
    Rectangle destRec = { pos_x, pos_y, size_x, size_y };
    Vector2 origin = { 0.0f, 0.0f };
    DrawTexturePro(texture, sourceRec, destRec, origin, rotation, color);
}

// FUNKCJA PRINTUJĄCA FPSY W KONSOLI
void print_fps(void)
{
    printf("FPS: %d\n", GetFPS());
}