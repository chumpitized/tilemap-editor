#include "draw.h"

#include <raylib.h>
#include <iostream>
#include <vector>

int screenWidth = 1295;
int screenHeight = 1080;

float tileSize		= 64;
float canvasWidth	= 1024;
float canvasHeight 	= 1024;
float xOffset 		= 25;
float yOffset 		= (screenHeight / 2) - (canvasHeight / 2);
int canvasTileWidth = canvasWidth / tileSize;

std::vector<Texture2D> entities;
std::vector<Texture2D> tiles;
std::vector<int> canvas(canvasTileWidth * canvasTileWidth, INT_MAX);

//SetWindowIcon to change... window icon
int main() {
	InitWindow(screenWidth, screenHeight, "Tilemap Editor");
	load_sprites(entities, tiles);

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);

			draw_canvas(canvas, entities, tiles, canvasTileWidth, xOffset, yOffset, tileSize);
			draw_tile_rect(entities, 3, xOffset + canvasWidth + 25, yOffset, tileSize);
			draw_tile_rect(tiles, 3, xOffset + canvasWidth + 25, yOffset + 300, tileSize);
			
		EndDrawing();
	}
}
