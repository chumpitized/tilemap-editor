#ifndef DATA_H
#define DATA_H

#include <raylib.h>
#include <vector>

//Draw
extern int storedTileOrEntity;

//Window
extern int screenWidth;
extern int screenHeight;

//Canvas
extern float tileSize;
extern float canvasWidth;
extern float canvasHeight;
extern float xOffset;
extern float yOffset;
extern int canvasTileWidth;

//Palettes
extern int paletteWidthP;
extern int paletteWidth;

//Font
extern int fontSize;

//Entities
extern int xEntitiesFont;
extern int yEntitiesFont;
extern int xEntitiesOffset;
extern int yEntitiesOffset;

//Tiles
extern int xTilesFont;
extern int yTilesFont;
extern int xTilesOffset;
extern int yTilesOffset;

//Arrays
extern std::vector<Texture2D> entities;
extern std::vector<Texture2D> tiles;
extern std::vector<int> canvas;

#endif