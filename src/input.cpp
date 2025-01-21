#include "input.h"
#include "data.h"

#include <raylib.h>
#include <vector>
#include <iostream>

void update_canvas(int x, int y) {
	int xTile = x / tileSize;
	int yTile = y / tileSize;

	int index = (yTile * canvasTileWidth) + xTile;
	
	//use tile or entity from stored value
	canvas[index] = 2;
}

void click_in_canvas(int xOffset, int yOffset, int canvasWidth, int canvasHeight) {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mousePos = GetMousePosition();

		int x = mousePos.x - xOffset;
		int y = mousePos.y - yOffset;

		if (x >= 0 && x < canvasWidth && y >= 0 && y < canvasHeight) {
			std::cout << "in canvas" << std::endl;
			update_canvas(x, y);
		}
	}
}

void click_in_entities(int xOffset, int yOffset) {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mousePos = GetMousePosition();
		
		int x = mousePos.x - xOffset;
		int y = mousePos.y - yOffset;
		int fullRowHeight = (entities.size() / 3) * tileSize;

		if (fullRowHeight > 0 && x >= 0 && x < paletteWidthP && y >= 0 && y < fullRowHeight) {
			std::cout << "in palette 1" << std::endl;
		}

		int unfinishedRowLength = (entities.size() % 3) * tileSize;

		y = y + fullRowHeight;

		if (x >= 0 && x < unfinishedRowLength && y >= 0 && y < tileSize) {
			std::cout << "in palette 2" << std::endl;
		}

	}
}

void click_in_tiles(int xOffset, int yOffset) {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mousePos = GetMousePosition();
		
		int x 				= mousePos.x - xOffset;
		int y 				= mousePos.y - yOffset;
		int fullRows 		= tiles.size() / 3;
		int fullRowHeight 	= fullRows * tileSize;

		if (fullRowHeight > 0 && x >= 0 && x < paletteWidthP && y >= 0 && y < fullRowHeight) {
			std::cout << "in tiles 1" << std::endl;
		}

		int partialRow 			= tiles.size() % 3;
		int partialRowLength 	= partialRow * tileSize;

		y = y + fullRowHeight;

		if (x >= 0 && x < partialRowLength && y >= 0 && y < tileSize) {
			std::cout << "in tiles 2" << std::endl;
		}

	}
}