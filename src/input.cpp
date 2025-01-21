#include "input.h"
#include "data.h"

#include <raylib.h>
#include <vector>
#include <iostream>

void handle_left_mouse_click() {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mousePos = GetMousePosition();

		int index = in_canvas();
		if (index >= 0) {
			std::cout << "updating canvas at index: " << index << std::endl;
			canvas[index] = 2;
			return;
		}

		index = in_palette(entities, xEntitiesOffset, yEntitiesOffset);
		if (index >= 0) {
			std::cout << "storing entity index: " << index << std::endl;
		}

		index = in_palette(tiles, xTilesOffset, yTilesOffset);
		if (index >= 0) {
			std::cout << "storing tile index: " << index <<  std::endl;
		}
	}
}

int in_canvas() {
	Vector2 mousePos = GetMousePosition();

	int x = mousePos.x - xOffset;
	int y = mousePos.y - yOffset;

	if (x >= 0 && x < canvasWidth && y >= 0 && y < canvasHeight) {
		int xTile = x / tileSize;
		int yTile = y / tileSize;

		return (yTile * canvasTileWidth) + xTile;
	}
	return -1;
}

int in_palette(std::vector<Texture2D>& palette, int xOffset, int yOffset) {
	Vector2 mousePos = GetMousePosition();
	
	int x 				= mousePos.x - xOffset;
	int y 				= mousePos.y - yOffset;
	int fullRows 		= palette.size() / 3;
	int fullRowHeight 	= fullRows * tileSize;

	if (fullRowHeight > 0 && x >= 0 && x < paletteWidthP && y >= 0 && y < fullRowHeight) {
		int xTile = x / tileSize;
		int yTile = y / tileSize;

		return (yTile * paletteWidth) + xTile;
	}

	int partialRow 			= palette.size() % 3;
	int partialRowLength 	= partialRow * tileSize;

	y = y - fullRowHeight;

	if (x >= 0 && x < partialRowLength && y >= 0 && y < tileSize) {
		return (fullRows * paletteWidth) + (x / tileSize);
	}
	return -1;
}