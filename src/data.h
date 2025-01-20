#ifndef DATA_H
#define DATA_H

#include <raylib.h>
#include <vector>

extern int screenWidth;
extern int screenHeight;

extern float tileSize;
extern float canvasWidth;
extern float canvasHeight;
extern float xOffset;
extern float yOffset;
extern int canvasTileWidth;

extern int paletteWidth;

extern int fontSize;

extern int xEntitiesFont;
extern int yEntitiesFont;
extern int xEntitiesOffset;
extern int yEntitiesOffset;

extern int xTilesFont;
extern int yTilesFont;
extern int xTilesOffset;
extern int yTilesOffset;

extern std::vector<Texture2D> entities;
extern std::vector<Texture2D> tiles;
extern std::vector<int> canvas;

#endif