#ifndef MAIN_H
#define MAIN_H

#include "raylib.h"

struct transform
{
    float pos_x, pos_y;
    float size_x, size_y;
};

struct sprite_renderer
{
    Texture texture;
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