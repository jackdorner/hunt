//
// Created by schoenfeldsa on 3/25/2025.
//

#include "MapArea.h"

MapArea::MapArea(int xCoord, int yCoord)
    : x(xCoord), y(yCoord) {}

int MapArea::getLocationX() const {
  return x;
}
int MapArea::getLocationY() const {
  return y;
}

bool MapArea::pickUpItem() {
  return false;
}

bool MapArea::coverWithPlank() {
  return false;
}

std::string MapArea::getText() const {
  return "none";
}

char MapArea::getSymbol() const {
  return '.';
}