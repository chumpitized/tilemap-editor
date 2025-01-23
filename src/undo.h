#ifndef UNDO_H
#define UNDO_H

#include "data.h"

#include <vector>

extern std::vector<std::vector<u16>> history;

void undo();

#endif