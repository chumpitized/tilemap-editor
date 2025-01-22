#include "data.h"
#include "draw.h"

#include <raylib.h>
#include <vector>

RenderTexture2D draw_setup(int screenWidth, int screenHeight) {
	RenderTexture2D texture = LoadRenderTexture(screenWidth, screenHeight);
	
	BeginTextureMode(texture);
		ClearBackground(GRAY);
		draw_canvas_border();

		//Draw Entity Palette
		DrawText("Entities", xEntitiesFont, yEntitiesFont, fontSize, BLACK);
		draw_tile_rect(entities, paletteWidth, xEntitiesOffset, yEntitiesOffset, tileSize);

		//Draw Tile Palette
		DrawText("Tiles", xTilesFont, yTilesFont, fontSize, BLACK);
		draw_tile_rect(tiles, paletteWidth, xTilesOffset, yTilesOffset, tileSize);
	EndTextureMode();
	
	return texture;
}

Texture2D load_sprite(const char* path) {
	Image image = LoadImage(path);
	Texture2D texture = LoadTextureFromImage(image);
	UnloadImage(image);
	return texture;
};

void load_sprites(std::vector<Texture2D>& entities, std::vector<Texture2D>& tiles) {
	entities = {
		load_sprite("data/sprites/character_transparent.png"),
		load_sprite("data/sprites/key_transparent.png")
	};

	tiles = {
		load_sprite("data/sprites/black_tile.png"),
		load_sprite("data/sprites/gray_tile.png"),
		load_sprite("data/sprites/horizontal_wall.png"),
		load_sprite("data/sprites/vertical_wall.png"),
		load_sprite("data/sprites/locked_door.png")
	};
}

void draw_canvas_border() {
	float thickness = 3.0;
	float width		= canvasWidth + (thickness * 2);
	DrawRectangleLinesEx(Rectangle{xOffset - thickness, yOffset - thickness, width, width}, 3.0, BLACK);
}

void draw_canvas(RenderTexture2D& texture, std::vector<u16>& canvas, std::vector<Texture2D>& entities, std::vector<Texture2D>& tiles, int width, int x, int y, int tileSize) {
	BeginTextureMode(texture);
	for (int i = 0; i < canvas.size(); ++i) {
		int row = i / width;
		int col = i - (row * width);

		float xTileOffset = x + (col * tileSize);
		float yTileOffset = y + (row * tileSize);

		Rectangle tile = Rectangle{xTileOffset, yTileOffset, (float)tileSize, (float)tileSize};
		
		if (canvas[i] > 100) {
			if (row + col & 1) DrawRectangleRec(tile, RAYWHITE);
			else DrawRectangleRec(tile, LIGHTGRAY);
		}
		else DrawTextureEx(tiles[canvas[i]], Vector2{xTileOffset, yTileOffset}, (float)0, (float)4, RAYWHITE);
	}
	EndTextureMode();
}

//can rename to palette...
void draw_tile_rect(std::vector<Texture2D>& rect, int width, int x, int y, int tileSize) {
	for (int i = 0; i < rect.size(); ++i) {
		int row = i / width;
		int col = i - (row * width);

		float xTileOffset = x + (col * tileSize);
		float yTileOffset = y + (row * tileSize);

		Rectangle tile = Rectangle{xTileOffset, yTileOffset, (float)tileSize, (float)tileSize};
		DrawRectangleRec(tile, BLACK);
		DrawTextureEx(rect[i], Vector2{xTileOffset, yTileOffset}, (float)0, (float)4, RAYWHITE);
	}	
}