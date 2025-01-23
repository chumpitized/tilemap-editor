#ifndef DRAW_H
#define DRAW_H

#include "data.h"
#include <raylib.h>
#include <vector>

void draw_selected_palette_tile();

RenderTexture2D draw_setup(int screenWidth, int screenHeight);
Texture2D load_sprite(const char* path);
void load_sprites(std::vector<Texture2D>& entities, std::vector<Texture2D>& tiles);
void draw_canvas_border();
void draw_canvas(RenderTexture2D& texture, std::vector<u16>& canvas, std::vector<Texture2D>& entities, std::vector<Texture2D>& tiles, int width, int x, int y, int tileSize);
void draw_palette(std::vector<Texture2D>& palette, int width, int x, int y, int tileSize);

#endif