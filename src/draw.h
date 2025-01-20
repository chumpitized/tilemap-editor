#ifndef DRAW_H
#define DRAW_H

#include <raylib.h>
#include <vector>

Texture2D load_sprite(const char* path);
void load_sprites(std::vector<Texture2D>& entities, std::vector<Texture2D>& tiles);
void draw_canvas_border();
void draw_canvas(std::vector<int>& canvas, std::vector<Texture2D>& entities, std::vector<Texture2D>& tiles, int width, int x, int y, int tileSize);
void draw_tile_rect(std::vector<Texture2D>& rect, int width, int x, int y, int tileSize);

#endif