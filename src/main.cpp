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

//using INT_MAX cuz we're gonna change this to uint16_t
std::vector<int> canvas(canvasTileWidth * canvasTileWidth, INT_MAX);

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

void draw_canvas(std::vector<int>& canvas, int width, int x, int y) {
	for (int i = 0; i < canvas.size(); ++i) {
		int row = i / width;
		int col = i - (row * width);

		float xTileOffset = x + (col * tileSize);
		float yTileOffset = y + (row * tileSize);

		Rectangle tile = Rectangle{xTileOffset, yTileOffset, tileSize, tileSize};
		
		if (canvas[i] > 100) DrawRectangleRec(tile, GRAY);
		else DrawTextureEx(tiles[canvas[i]], Vector2{xTileOffset, yTileOffset}, (float)0, (float)4, RAYWHITE);
	}	
}

void draw_tile_rect(std::vector<Texture2D>& rect, int width, int x, int y) {
	for (int i = 0; i < rect.size(); ++i) {
		int row = i / width;
		int col = i - (row * width);

		float xTileOffset = x + (col * tileSize);
		float yTileOffset = y + (row * tileSize);

		Rectangle tile = Rectangle{xTileOffset, yTileOffset, tileSize, tileSize};		
		DrawRectangleRec(tile, BLACK);
		DrawTextureEx(rect[i], Vector2{xTileOffset, yTileOffset}, (float)0, (float)4, RAYWHITE);
	}	
}

//SetWindowIcon to change... window icon
int main() {
	InitWindow(screenWidth, screenHeight, "Tilemap Editor");
	load_sprites();

	std::cout << canvas.size() << std::endl;

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);

			draw_canvas(canvas, canvasTileWidth, xOffset, yOffset);
			draw_tile_rect(entities, 3, xOffset + canvasWidth + 25, yOffset);
			draw_tile_rect(tiles, 3, xOffset + canvasWidth + 25, yOffset + 300);
			
		EndDrawing();
	}
}
