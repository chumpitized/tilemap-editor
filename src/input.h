#ifndef INPUT_H
#define INPUT_H

#include <raylib.h>

static void update_canvas(int x, int y);

void handle_left_mouse_click();

bool is_click_in_canvas();
bool is_click_in_entities();
bool is_click_in_tiles();

#endif