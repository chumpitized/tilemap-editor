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
	float yOffset 		= screenHeight / 2;

	float yRectPos 		= yOffset - (canvasHeight / 2);

	Rectangle canvas = Rectangle{xOffset, yRectPos, canvasWidth, canvasHeight};

	int canvasTileWidth = canvasWidth / tileSize;

	for (int i = 0; i < canvasTileWidth; ++i) {


		int xTileOffset = xOffset + (i * tileSize);
		int yTileOffset = yOffset + (i * tileSize);

		//Rectangle
	}

	InitWindow(screenWidth, screenHeight, "Tilemap Editor");

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawRectangleRec(canvas, BLACK);
		EndDrawing();
	}
}
