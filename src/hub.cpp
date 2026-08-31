#include "main.hpp"

int tabs = 0;

void Projects_tab()
{
    tabs = 1;
}

void Learn_tab()
{
    tabs = 2;
}


void Project_window(void)
{
    Engine_draw_rectangle_shape(0.0f, 0.0f, 800.0f, 600.0f, GRAY_COLOR);
    Engine_draw_rectangle_shape(0.0f, 0.0f, 256.0f, 600.0f, DARK_GRAY_COLOR);

    // texts

    Engine_draw_text_better(font, ENGINE_NAME, (Vector2){10.0f, 10.0f}, (Vector2){0.0f, 0.0f}, 0.0f, 32.0f, 2.0f, WHITE);
    Engine_draw_text_better(font, ENGINE_VERSION, (Vector2){10.0f, 580.0f}, (Vector2){0.0f, 0.0f}, 0.0f, 16.0f, 2.0f, WHITE);

    // Buttons

    Engine_button(Projects_tab, "PROJECTS", 15.0f, 60.0f, 70.0f, 70.0f, 200.0f, 40.0f);
    Engine_button(Learn_tab, "LEARN", 15.0f, 120.0f, 60.0f, 130.0f, 200.0f, 40.0f);
    Engine_draw_rectangle_shape_with_texture(projects_icon, 25.0f, 65.0f, 30.0f, 30.0f, 0.0f, WHITE);
    Engine_draw_rectangle_shape_with_texture(learn_icon, 25.0f, 124.0f, 30.0f, 30.0f, 0.0f, WHITE);
    Engine_button_with_texture(Learn_tab, settings_icon, 195.0f, 4.0f, 50.0f, 50.0f, 0.0f, WHITE);
    
    
    // Projects Tab
    if (tabs == 1)
    {
        Engine_draw_rectangle_shape(250.0f, 0.0f, 800.0f, 600.0f, DARKER_GRAY_COLOR);
        Engine_draw_text_better(font, "PROJECTS", (Vector2){260.0f, 10.0f}, (Vector2){0.0f, 0.0f}, 0.0f, 32.0f, 2.0f, WHITE);
        Engine_button(Learn_tab, "NEW PROJECT", 580.0f, 10.0f, 591.5f, 20.0f, 200.0f, 40.0f);
        
    }

    // Learn Tab

    if (tabs == 2)
    {
        Engine_draw_rectangle_shape(250.0f, 0.0f, 800.0f, 600.0f, DARKER_GRAY_COLOR);
        Engine_draw_text_better(font, "LEARN", (Vector2){260.0f, 10.0f}, (Vector2){0.0f, 0.0f}, 0.0f, 32.0f, 2.0f, WHITE);
    }
    
}