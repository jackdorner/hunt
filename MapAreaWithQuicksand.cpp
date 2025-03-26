//
// Created by schoenfeldsa on 3/25/2025.
//

#include "MapAreaWithQuicksand.h"
#include <iostream>
using namespace std;


MapAreaWithQuicksand::MapAreaWithQuicksand(int xCoord, int yCoord)
    : MapArea(xCoord, yCoord), covered(false) {}

std::string MapAreaWithQuicksand::getText() const {
  if (!covered) {
    return "The ground starts to soften...";
  }
  return "This area was quicksand, but you've covered it with a plank.";
}

bool MapAreaWithQuicksand::coverWithPlank() {
  if (!covered) {
    covered = true;
    cout << "You place a plank over the quicksand, it's now safe to cross.\n";
    return true;
  }
  return false;
}
char MapAreaWithQuicksand::getSymbol() const {
  return (covered ? '.' : 'O');
}
