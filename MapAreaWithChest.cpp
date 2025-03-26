//
// Created by schoenfeldsa on 3/25/2025.
//

#include "MapAreaWithChest.h"
#include <iostream>
using namespace std;


MapAreaWithChest::MapAreaWithChest(int xCoord, int yCoord)
    : MapArea(xCoord, yCoord), chestOpened(false) {}

string MapAreaWithChest::getText() const {
  if (!chestOpened) {
    return "Your heart starts to race.";
  }
  return "You've already opened this chest.";
}

void MapAreaWithChest::openChest(bool hasKey) {
  if (chestOpened) {
    cout << "The chest is already open.\n";
    return;
  }

  if (hasKey) {
    chestOpened = true;
    cout << "You open the chest and claim the treasure!\n";
  } else {
    cout << "You need a key to open the chest.\n";
  }
}
char MapAreaWithChest::getSymbol() const {
  // Return '$' if the chest is unopened, or '.' if opened.
  return (chestOpened ? '.' : '$');
}
