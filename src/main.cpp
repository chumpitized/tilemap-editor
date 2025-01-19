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

struct TileSqr {
	int x;
	int y;

	int width;
	int length;
	std::vector<int> tiles;

	TileSqr(int x, int y, int width, int length) {
		this->x 	= x;
		this->y 	= y;
		this->width = width;
		tiles 		= std::vector(0, length);
	}
};

void draw_tile_sqr(TileSqr tileSqr) {
	for (int i = 0; i < tileSqr.width; ++i) {
		for (int j = 0; j < tileSqr.width; ++j) {
			float xTileOffset = tileSqr.x + (j * tileSize);
			float yTileOffset = tileSqr.y + (i * tileSize);

			//We draw the sprite from the sprite array here... using the index from tiles...
			Rectangle tile = Rectangle{xTileOffset, yTileOffset, tileSize, tileSize};		
			
			//this can just be black by default...
			if (j + i & 1) DrawRectangleRec(tile, BLACK);
			else DrawRectangleRec(tile, GRAY);
		}
	}
}

int main() {
	TileSqr canvas 			= TileSqr(xOffset, yOffset, canvasTileWidth, canvasTileWidth * canvasTileWidth);
	TileSqr entityPalette 	= TileSqr(xOffset + canvasWidth + 25, yOffset, 3, 9);
	TileSqr tilePalette		= TileSqr(xOffset + canvasWidth + 25, yOffset + 300, 3, 7);

	InitWindow(screenWidth, screenHeight, "Tilemap Editor");

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);

			draw_tile_sqr(canvas);
			draw_tile_sqr(entityPalette);
			draw_tile_sqr(tilePalette);
			
		EndDrawing();
	}
}
