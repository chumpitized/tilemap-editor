#include "input.h"
#include "data.h"

#include <raylib.h>
#include <vector>
#include <iostream>

static void update_canvas(int x, int y) {
	int xTile = x / tileSize;
	int yTile = y / tileSize;

	int index = (yTile * canvasTileWidth) + xTile;
	
	canvas[index] = 2;
}

void handle_left_mouse_click() {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mousePos = GetMousePosition();

		if (is_click_in_canvas()) {
			std::cout << "updating canvas..." << std::endl;
			update_canvas(mousePos.x - xOffset, mousePos.y - yOffset);
		}

		if (is_click_in_entities()) {
			std::cout << "storing entity..." << std::endl;
		}

		if (is_click_in_tiles()) {
			std::cout << "storing tile..." << std::endl;
		}
	}
}

bool is_click_in_canvas() {
	Vector2 mousePos = GetMousePosition();

	int x = mousePos.x - xOffset;
	int y = mousePos.y - yOffset;

	if (x >= 0 && x < canvasWidth && y >= 0 && y < canvasHeight) {
		return true;
	}
	return false;
}

bool is_click_in_entities() {
	Vector2 mousePos = GetMousePosition();
		
	int x = mousePos.x - xEntitiesOffset;
	int y = mousePos.y - yEntitiesOffset;
	int fullRowHeight = (entities.size() / 3) * tileSize;

	if (fullRowHeight > 0 && x >= 0 && x < paletteWidthP && y >= 0 && y < fullRowHeight) {
		return true;
	}

	int unfinishedRowLength = (entities.size() % 3) * tileSize;

	y = y - fullRowHeight;

	if (x >= 0 && x < unfinishedRowLength && y >= 0 && y < tileSize) {
		return true;
	}
	return false;
}

bool is_click_in_tiles() {
	Vector2 mousePos = GetMousePosition();
		
	int x 				= mousePos.x - xTilesOffset;
	int y 				= mousePos.y - yTilesOffset;
	int fullRows 		= tiles.size() / 3;
	int fullRowHeight 	= fullRows * tileSize;

	if (fullRowHeight > 0 && x >= 0 && x < paletteWidthP && y >= 0 && y < fullRowHeight) {
		return true;
	}

	int partialRow 			= tiles.size() % 3;
	int partialRowLength 	= partialRow * tileSize;

	y = y - fullRowHeight;

	if (x >= 0 && x < partialRowLength && y >= 0 && y < tileSize) {
		return true;
	}
	return false;
}