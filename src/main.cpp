#include <raylib.h>
#include <iostream>
#include <vector>

std::vector<Texture2D> entities;
std::vector<Texture2D> tiles;

int screenWidth = 1295;
int screenHeight = 1080;

float tileSize		= 64;
float canvasWidth	= 1024;
float canvasHeight 	= 1024;
float xOffset 		= 25;
float yOffset 		= (screenHeight / 2) - (canvasHeight / 2);
int canvasTileWidth = canvasWidth / tileSize;

struct TileRect {
	int x;
	int y;

	int width;
	int length;
	std::vector<int> cells;

	TileRect(int x, int y, int width, int length) {
		this->x 		= x;
		this->y 		= y;
		this->width 	= width;
		this->length 	= length;
		cells 			= std::vector(0, length);
	}
};

Texture2D load_sprite(const char* path) {
	Image image = LoadImage(path);
	Texture2D texture = LoadTextureFromImage(image);
	UnloadImage(image);
	return texture;
};

void load_sprites() {
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

void draw_tile_sqr(TileRect sqr) {
	for (int i = 0; i < sqr.length; ++i) {

		int row = i / sqr.width;
		int col = i - (row * sqr.width);

		float xTileOffset = sqr.x + (col * tileSize);
		float yTileOffset = sqr.y + (row * tileSize);

		//We draw the sprite from the sprite array here...
		Rectangle tile = Rectangle{xTileOffset, yTileOffset, tileSize, tileSize};		
			
		//this can just be black by default...
		if (col + row & 1) DrawRectangleRec(tile, BLACK);
		else DrawRectangleRec(tile, GRAY);
	}
}

void draw_tile_rect(std::vector<Texture2D>& rect, int width, int x, int y) {
	for (int i = 0; i < rect.size(); ++i) {
		int row = i / width;
		int col = i - (row * width);

		float xTileOffset = x + (col * tileSize);
		float yTileOffset = y + (row * tileSize);

		Rectangle tile = Rectangle{xTileOffset, yTileOffset, tileSize, tileSize};
			
		//this can just be black by default...
		if (col + row & 1) DrawRectangleRec(tile, BLACK);
		else DrawRectangleRec(tile, GRAY);

		DrawTextureEx(entities[i], Vector2{xTileOffset, yTileOffset}, (float)0, (float)4, RAYWHITE);
	}	
}

int main() {
	InitWindow(screenWidth, screenHeight, "Tilemap Editor");
	load_sprites();

	TileRect canvas 		= TileRect(xOffset, yOffset, canvasTileWidth, canvasTileWidth * canvasTileWidth);
	TileRect entityPalette 	= TileRect(xOffset + canvasWidth + 25, yOffset, 3, entities.size());
	TileRect tilePalette	= TileRect(xOffset + canvasWidth + 25, yOffset + 300, 3, tiles.size());

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);

			draw_tile_sqr(canvas);
			//only draw black background on palettes...
			draw_tile_rect(entities, 3, entityPalette.x, entityPalette.y);
			draw_tile_sqr(tilePalette);
			
		EndDrawing();
	}
}
