#include <raylib.h>

#include <iostream>


int screenWidth = 1920;
int screenHeight = 1080;

int main() {
	
	int xOffset = screenWidth / 2;
	int yOffset = screenHeight / 2;

	int xRect = 1024;
	int yRect = 1024;

	int xRectPos = xOffset - (xRect / 2);
	int yRectPos = yOffset - (yRect / 2);

	Rectangle canvas = Rectangle{(float)xOffset - (xRect / 2), (float)yOffset - (yRect / 2), (float)xRect, (float)yRect};
	//Rectangle rect2 = Rectangle{(float)xOffset - (xRect / 2), (float)yOffset - (yRect / 2), (float)64, (float)64};
	
	//DrawRectangleRec(rect, BLACK);

	InitWindow(screenWidth, screenHeight, "Tilemap Editor");

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawRectangleRec(canvas, BLACK);

			//DrawRectangleRec(rect2, PINK);
		EndDrawing();
	}
}
