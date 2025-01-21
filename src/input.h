#ifndef INPUT_H
#define INPUT_H

#include <raylib.h>

//bool click_in_tiles();
//bool click_in_entities();
void update_canvas(int x, int y);
void click_in_canvas(int xOffset, int yOffset, int canvasWidth, int canvasHeight);

void click_in_entities(int xOffset, int yOffset);
void click_in_tiles(int xOffset, int yOffset);


//tile and entity storage in the paint buffer are mutuall exclusive
//but an entity and tile can live in the same spot on the canvas
//void store_tile_or_entity();

#endif