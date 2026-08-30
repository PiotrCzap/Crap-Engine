#include "main.hpp"

void Projects_tab()
{
    Projects_tab_visible = 1;
    
}

void Project_window(void)
{
    Engine_draw_rectangle_shape(0, 0, 800, 600, GRAY_COLOR);
    Engine_draw_rectangle_shape(0, 0, 256, 600, DARK_GRAY_COLOR);

    // texts

    Engine_draw_text_better(font, ENGINE_NAME, (Vector2){10.0f, 10.0f}, (Vector2){0.0f, 0.0f}, 0.0f, 32.0f, 2.0f, WHITE);
    Engine_draw_text_better(font, ENGINE_VERSION, (Vector2){10.0f, 580.0f}, (Vector2){0.0f, 0.0f}, 0.0f, 16.0f, 2.0f, WHITE);

    // Buttons

    Engine_button(Projects_tab, "PROJECTS", 15.0f, 60.0f, 45.0f, 70.0f, 200.0f, 40.0f);
    Engine_button(Projects_tab, "TUTORIALS", 15.0f, 120.0f, 45.0f, 130.0f, 200.0f, 40.0f);
    Engine_button(Projects_tab, "LEARN", 15.0f, 180.0f, 45.0f, 190.0f, 200.0f, 40.0f);

    if (Projects_tab_visible == 1)
    {
        Engine_draw_rectangle_shape(250, 0, 800, 600, DARKER_GRAY_COLOR);
        Engine_draw_text_better(font, "PROJECTS", (Vector2){260, 10}, (Vector2){0.0f, 0.0f}, 0.0f, 32.0f, 2.0f, WHITE);
    }
    
}