#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include <raylib.h>

void handle_left_mouse_click();

int in_canvas();
int in_palette(std::vector<Texture2D>& palette, int xOffset, int yOffset);

#endif