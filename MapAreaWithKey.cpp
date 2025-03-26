//
// Created by schoenfeldsa on 3/25/2025.
//

#include "MapAreaWithKey.h"
#include <iostream>
using namespace std;

MapAreaWithKey::MapAreaWithKey(int xCoord, int yCoord)
    : MapArea(xCoord, yCoord), keyTaken(false) {}

std::string MapAreaWithKey::getText() const {
  if (!keyTaken) {
    return "You see a small glint on the ground";
  }
  return "This area is empty now.";
}

bool MapAreaWithKey::pickUpItem() {
  if (!keyTaken) {
    keyTaken = true;
    cout << "You pick up the key.\n";
    return true;
  }
  return false;
}
char MapAreaWithKey::getSymbol() const {
  return (keyTaken ? '.' : '*');
}

