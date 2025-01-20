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

std::vector<Texture2D> entities;
std::vector<Texture2D> tiles;
std::vector<int> canvas(canvasTileWidth * canvasTileWidth, 200);