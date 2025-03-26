//
// Created by dornerj on 3/25/2025.
//

#ifndef GAME_H
#define GAME_H

#include <string>
#include "MapArea.h"
#include "Player.h"

class Game {
public:
  Game();
  void startGame();

private:
  bool over = false;
  MapArea *cells[7][7];
  Player* player;
  char getInput();
  bool moveNorth();
  bool moveSouth();
  bool moveEast();
  bool moveWest();
  void move(MapArea* area);
  void printSurrounding();
  void printHelp();
  void printMap();
  MapArea* getMapArea(char type, int i, int j);
};

#endif
//GAME_H