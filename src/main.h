#ifndef MAIN_H
#define MAIN_H

#include "raylib.h"

char null_txt[26] = "src/Engine Data/null.png";

struct transform
{
    float pos_x, pos_y;
    float size_x, size_y;
};

struct sprite_renderer
{
    Texture2D texture;
    Color color;
    int visible;
};

struct text_renderer
{
    char *text;
    float font_size;
    Color color;
    int visible;
};


struct GameObject
{
   struct transform transform;
   struct sprite_renderer sprite_renderer;
   struct text_renderer text_renderer;
};

#endif