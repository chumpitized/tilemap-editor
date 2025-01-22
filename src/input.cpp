#include "input.h"
#include "data.h"

#include <raylib.h>
#include <vector>
#include <iostream>

void reset_canvas() {
	if (IsKeyPressed(KEY_R)) {
		for (int i = 0; i < canvas.size(); ++i) {
			canvas[i] = -1;
		}
	}
}

void handle_mouse_hover() {
	Vector2 mousePos = GetMousePosition();

	int index = in_canvas(mousePos);
	if (index >= 0) {
		//std::cout << "drawing example at canvas index: " << index << std::endl;

		float y = ((index / canvasTileWidth) * tileSize) + yOffset;
		float x = ((index % canvasTileWidth) * tileSize) + xOffset;

		if (storedTileOrEntity >= 0) DrawTextureEx(tiles[storedTileOrEntity], Vector2{x,y}, 0, 4.0, RAYWHITE);
	}
}

void handle_right_mouse_click() {
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
		Vector2 mousePos = GetMousePosition();

		int index = in_canvas(mousePos);
		if (index >= 0) {
			std::cout << "erasing at canvas index: " << index << std::endl;
			canvas[index] = -1;
			return;
		}	
	}
}

void handle_left_mouse_click() {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mousePos = GetMousePosition();

		//Entities
		int index = in_palette(entities, xEntitiesOffset, yEntitiesOffset, mousePos);
		if (index >= 0) {
			storedTileOrEntity = index;
			//std::cout << "storing entity index: " << index << std::endl;
		}

		//Tiles
		index = in_palette(tiles, xTilesOffset, yTilesOffset, mousePos);
		if (index >= 0) {
			storedTileOrEntity = index;
			//std::cout << "storing tile index: " << index <<  std::endl;
		}
	}
}

void handle_left_mouse_held() {
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		Vector2 mousePos = GetMousePosition();

		//Canvas
		int index = in_canvas(mousePos);
		if (index >= 0) {
			//std::cout << "updating canvas at index: " << index << std::endl;
			if (storedTileOrEntity >= 0) canvas[index] = storedTileOrEntity;
			return;
		}
	}
}

void handle_left_mouse_release() {
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		std::cout << "released left mouse button..." << std::endl;
	}
}

int in_canvas(Vector2 mousePos) {
	int x = mousePos.x - xOffset;
	int y = mousePos.y - yOffset;

	if (x >= 0 && x < canvasWidth && y >= 0 && y < canvasHeight) {
		int xTile = x / tileSize;
		int yTile = y / tileSize;

		return (yTile * canvasTileWidth) + xTile;
	}
	return -1;
}

int in_palette(std::vector<Texture2D>& palette, int xOffset, int yOffset, Vector2 mousePos) {
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