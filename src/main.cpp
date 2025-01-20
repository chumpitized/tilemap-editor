#include "draw.h"
#include "input.h"
#include "data.h"

#include <raylib.h>

//SetWindowIcon to change... window icon
int main() {
	InitWindow(screenWidth, screenHeight, "Tilemap Editor");
	load_sprites(entities, tiles);

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			
			DrawFPS(0, 0);

			click_in_canvas(xOffset, yOffset, canvasWidth, canvasHeight);

			draw_canvas(canvas, entities, tiles, canvasTileWidth, xOffset, yOffset, tileSize);
			draw_tile_rect(entities, 3, xOffset + canvasWidth + 25, yOffset, tileSize);
			draw_tile_rect(tiles, 3, xOffset + canvasWidth + 25, yOffset + 300, tileSize);
			
		EndDrawing();
	}
}
