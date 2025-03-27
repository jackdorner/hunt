//
// Created by schoenfeldsa on 3/25/2025.
//

#include "MapAreaWithPlanks.h"
#include <iostream>
using namespace std;

MapAreaWithPlanks::MapAreaWithPlanks(int xCoord, int yCoord)
    : MapArea(xCoord, yCoord), plankTaken(false) {}

//no getText here as there is no clue for when planks are nearby.

bool MapAreaWithPlanks::pickUpItem() {
  if (!plankTaken) {
    plankTaken = true;
    cout << "You pick up the plank.\n";
    return true;
  }
  return false;
}
char MapAreaWithPlanks::getSymbol() const {
  return (plankTaken ? '.' : '|');
}

