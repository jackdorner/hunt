//
// Created by schoenfeldsa on 3/25/2025.
//

#include "MapAreaWithCoconuts.h"
using namespace std;

MapAreaWithCoconuts::MapAreaWithCoconuts(int xCoord, int yCoord)
    : MapArea(xCoord, yCoord) {}

string MapAreaWithCoconuts::getText() const {
  return "You hear a thunk, what's that?";
}
char MapAreaWithCoconuts::getSymbol() const {
  return '%';
}
