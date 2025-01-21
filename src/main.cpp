#include "draw.h"
#include "input.h"
#include "data.h"

#include <raylib.h>

//SetWindowIcon to change... window icon
int main() {
	InitWindow(screenWidth, screenHeight, "Tilemap Editor");
	load_sprites(entities, tiles);

	while (!WindowShouldClose()) {
		//Input
		handle_left_mouse_click();

		//Draw
		BeginDrawing();
			ClearBackground(GRAY);
			DrawFPS(0, 0);

			//Draw Canvas
			draw_canvas(canvas, entities, tiles, canvasTileWidth, xOffset, yOffset, tileSize);
			draw_canvas_border();
		
			//Draw Entity Palette
			DrawText("Entities", xEntitiesFont, yEntitiesFont, fontSize, BLACK);
			draw_tile_rect(entities, paletteWidth, xEntitiesOffset, yEntitiesOffset, tileSize);

			//Draw Tile Palette
			DrawText("Tiles", xTilesFont, yTilesFont, fontSize, BLACK);
			draw_tile_rect(tiles, paletteWidth, xTilesOffset, yTilesOffset, tileSize);
		EndDrawing();
	}
}
