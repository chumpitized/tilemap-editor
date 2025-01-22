#include "input.h"
#include "data.h"

#include <raylib.h>
#include <vector>
#include <iostream>

void reset_canvas() {
	if (IsKeyPressed(KEY_R)) {
		for (int i = 0; i < canvas.size(); ++i) {
			canvas[i] = 0xffff;
		}
	}
}

void handle_mouse_hover() {
	Vector2 mousePos = GetMousePosition();
	int index = in_canvas(mousePos);

	if (index < 0) return; 

	float y = ((index / canvasTileWidth) * tileSize) + yOffset;
	float x = ((index % canvasTileWidth) * tileSize) + xOffset;

	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
		std::cout << "drawing red outline for erase at canvas index: " << index << std::endl;

		DrawRectangleLinesEx(Rectangle{x, y, tileSize, tileSize}, 6, RED);
	} else {
		std::cout << "drawing example tile at canvas index: " << index << std::endl;

		if (storedTile.storedIndex >= 0) DrawTextureEx(tiles[storedTile.storedIndex], Vector2{x,y}, 0, 4.0, RAYWHITE);
	}
}

void handle_right_mouse_click() {
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
		Vector2 mousePos = GetMousePosition();

		int index = in_canvas(mousePos);
		if (index >= 0) {
			std::cout << "erasing at canvas index: " << index << std::endl;
			canvas[index] = 0xffff;
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
			storedTile.storedIndex 	= index;
			storedTile.isEntity 	= true;
			std::cout << "storing entity index: " << index << std::endl;
		}

		//Tiles
		index = in_palette(tiles, xTilesOffset, yTilesOffset, mousePos);
		if (index >= 0) {
			storedTile.storedIndex 	= index;
			storedTile.isEntity		= false;
			std::cout << "storing tile index: " << index <<  std::endl;
		}
	}
}

void handle_left_mouse_held() {
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		Vector2 mousePos = GetMousePosition();

		//Canvas
		int index = in_canvas(mousePos);
		if (index >= 0) {
			std::cout << "updating canvas at index: " << index << std::endl;
			if (storedTile.storedIndex >= 0) canvas[index] = storedTile.storedIndex;
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