#include <raylib.h>
#include <iostream>

int screenWidth = 1920;
int screenHeight = 1080;

struct Vec2 {
	int x;
	int y;
};

int main() {
	float tileSize		= 64;
	float canvasWidth	= 1024;
	float canvasHeight 	= 1024;
	float xOffset 		= 25;
	float yOffset 		= (screenHeight / 2) - (canvasHeight / 2);

	int canvasTileWidth = canvasWidth / tileSize;

	InitWindow(screenWidth, screenHeight, "Tilemap Editor");

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);

			//Draw the canvas as a grid of tiles
			for (int i = 0; i < canvasTileWidth; ++i) {
				for (int j = 0; j < canvasTileWidth; ++j) {			
					float xTileOffset = xOffset + (j * tileSize);
					float yTileOffset = yOffset + (i * tileSize);

					Rectangle tile = Rectangle{xTileOffset, yTileOffset, tileSize, tileSize};		
			
					if (j + i & 1) DrawRectangleRec(tile, BLACK);
					else DrawRectangleRec(tile, GRAY);
				}
			}
		EndDrawing();
	}
}
