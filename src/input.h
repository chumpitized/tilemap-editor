#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include <raylib.h>

void handle_mouse_hover();
void handle_left_mouse_click();
void handle_right_mouse_click();

int in_canvas(Vector2 mousePos);
int in_palette(std::vector<Texture2D>& palette, int xOffset, int yOffset, Vector2 mousePos);

#endif