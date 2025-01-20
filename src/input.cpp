#include "input.h"
#include "data.h"

#include <raylib.h>
#include <vector>
#include <iostream>

void update_canvas(Vector2 mousePos) {
	int x = mousePos.x - xOffset;
	int y = mousePos.y - yOffset;

	int xTile = x / tileSize;
	int yTile = y / tileSize;

	int index = (yTile * canvasTileWidth) + xTile;
	canvas[index] = 2;
}

bool click_in_canvas(int xOffset, int yOffset, int canvasWidth, int canvasHeight) {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mousePos = GetMousePosition();

		if (mousePos.x > xOffset && mousePos.x < (xOffset + canvasWidth) && mousePos.y > yOffset && mousePos.y < (yOffset + canvasHeight)) {
			std::cout << "in canvas" << std::endl;
			update_canvas(mousePos);
			return true;
		}
	}
	return false;
}