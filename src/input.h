#ifndef INPUT_H
#define INPUT_H

#include <raylib.h>

//bool click_in_tiles();
//bool click_in_entities();
void update_canvas(Vector2 mousePos);
bool click_in_canvas(int xOffset, int yOffset, int canvasWidth, int canvasHeight);

//tile and entity storage in the paint buffer are mutuall exclusive
//but an entity and tile can live in the same spot on the canvas
//void store_tile_or_entity();

#endif