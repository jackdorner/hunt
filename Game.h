//
// Created by dornerj on 3/25/2025.
//

#ifndef GAME_H
#define GAME_H

#include <string>
#include "MapArea.h"

class Game {
    int numCoconutAreas =3;
    int numQuicksandAreas = 3;
    int numPlankAreas = 3;
    int numKeyAreas = 2;
    int numChestAreas = 1;
    int numRegularAreas = 37;
    MapArea *cells[7][7];
public:
  Game();
  void startGame();

private:
  char getInput();
  bool moveNorth();
  bool moveSouth();
  bool moveEast();
  bool moveWest();
  void printSurrounding();
  void printHelp();
  void printMap();
  MapArea* getMapArea();
};

#endif
//GAME_H