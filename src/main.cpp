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
		this->x 		= x;
		this->y 		= y;
		this->width 	= width;
		this->length 	= length;
		tiles 			= std::vector(0, length);
	}
};

void draw_tile_sqr(TileSqr sqr) {
	for (int i = 0; i < sqr.length; ++i) {

		int row = i / sqr.width;
		int col = i - (row * sqr.width);

		float xTileOffset = sqr.x + (col * tileSize);
		float yTileOffset = sqr.y + (row * tileSize);

		//We draw the sprite from the sprite array here... using the index from tiles...
		Rectangle tile = Rectangle{xTileOffset, yTileOffset, tileSize, tileSize};		
			
		//this can just be black by default...
		if (col + row & 1) DrawRectangleRec(tile, BLACK);
		else DrawRectangleRec(tile, GRAY);
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
