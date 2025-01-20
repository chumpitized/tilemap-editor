#include "data.h"

#include <vector>

int screenWidth 	= 1295;
int screenHeight 	= 1080;

float tileSize		= 64;
float canvasWidth	= 1024;
float canvasHeight 	= 1024;
float xOffset 		= 25;
float yOffset 		= (screenHeight / 2) - (canvasHeight / 2);
int canvasTileWidth = canvasWidth / tileSize;

int paletteWidth	= 3;
int fontSize		= 35;

int xEntitiesFont	= xOffset + canvasWidth + 25;
int yEntitiesFont	= yOffset;
int xEntitiesOffset = xEntitiesFont;
int yEntitiesOffset = yEntitiesFont + fontSize + 10;

int xTilesFont		= xOffset + canvasWidth + 25;
int yTilesFont		= yOffset + 300;
int xTilesOffset	= xEntitiesOffset;
int yTilesOffset	= yTilesFont + fontSize + 10;

std::vector<Texture2D> entities;
std::vector<Texture2D> tiles;
std::vector<int> canvas(canvasTileWidth * canvasTileWidth, 200);