//
// Created by dornerj on 3/25/2025.
//

#include "Game.h"
#include "Player.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <cctype>
#include <vector>
#include "MapArea.h"
#include "MapAreaWithChest.h"
#include "MapAreaWithCoconuts.h"
#include "MapAreaWithKey.h"
#include "MapAreaWithPlanks.h"
#include "MapAreaWithQuicksand.h"

using namespace std;

Game::Game() {
  player = new Player();
  std::vector<char> chars = {'|', '|', '|', '$', 'O', 'O', 'O', '*', '*', '%', '%', '%', '+'};
  chars.resize(49, '.');
  int index = 0;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::shuffle(chars.begin(), chars.end(), gen);
    for (int j = 0; j < 7; j++) {
    for (int i = 0; i < 7; i ++) {
      cells[i][j] = getMapArea(chars[index++], i, j);
    }
  }
}

char Game::getInput() {
  cout << endl << "Action: N)orth, S)outh, E)ast, W)est, H)elp, M)ap, Q)uit: ";
  char input;
  bool valid = false;

  while (!valid){
    cin >> input;
    input = toupper(input);
    if (input == 'N' || input == 'S' || input == 'E' || input == 'W' || input == 'H' || input == 'M' || input == 'Q') {
      valid = true;
    } else {
      cout << "Invalid input" << endl;
      cout << "Action: N)orth, S)outh, E)ast, W)est, H)elp, M)ap, Q)uit: ";
    }
  }
  return input;
}

void Game::startGame() {
  while (!over) {
    char input = getInput();
    switch (input) {
      case 'N':
        if (moveNorth()) {
          printSurrounding();
        } else {
          cout << "Cannot move North";
        }
        break;
      case 'S':
        if (moveSouth()) {
          printSurrounding();
        } else {
          cout << "Cannot move South";
        }
        break;
      case 'E':
        if (moveEast()) {
          printSurrounding();
        } else {
          cout << "Cannot move East";
        }
        break;
      case 'W':
        if (moveWest()) {
          printSurrounding();
        } else {
          cout << "Cannot move West";
        }
        break;
      case 'H':
        printHelp();
        break;
      case 'M':
        printMap();
        break;
      case 'Q':
        over = true;
        break;
    }
  }
}

bool Game::moveNorth() {
  if (player->getYLocation() != 0) {
    player->setLocation(player->getXLocation(), player->getYLocation() - 1);
    move(cells[player->getXLocation()][player->getYLocation()]);
    return true;
  } else {
    return false;
  }
}

bool Game::moveSouth() {
  if (player->getYLocation() != 6) {
    player->setLocation(player->getXLocation(), player->getYLocation() + 1);
    move(cells[player->getXLocation()][player->getYLocation()]);
    return true;
  } else {
    return false;
  }
}

bool Game::moveEast() {
  if (player->getXLocation() != 6) {
    player->setLocation(player->getXLocation() + 1, player->getYLocation());
    move(cells[player->getXLocation()][player->getYLocation()]);
    return true;
  } else {
    return false;
  }
}

bool Game::moveWest() {
  if (player->getXLocation() != 0) {
    player->setLocation(player->getXLocation() - 1, player->getYLocation());
    move(cells[player->getXLocation()][player->getYLocation()]);
    return true;
  } else {
    return false;
  }
}

void Game::move(MapArea *area) {
  char type = area->getSymbol();
  switch (type) {
    case '|':
      area->pickUpItem();
      player->pickupPlank();
      break;
    case '$':
      if (player->holdsKey()) {
        cout << "You open the chest and claim the treasure!";
        over = true;
      }
      break;
    case 'O':
      if (player->hasPlank()) {
        player->placePlank();
        area->coverWithPlank();
      } else {
        cout << "You died in quicksand";
        over = true;
      }
      break;
    case '*':
      area->pickUpItem();
      player->pickupKey();
      break;
    case '%':
      //FIXME
    case '.':
      break;
  }
}

void Game::printSurrounding() {
  int currx = player->getXLocation();
  int curry = player->getYLocation();
  int leftx = currx - 1;
  int rightx = currx + 1;
  int topy = curry - 1;
  int bottomy = curry + 1;
  if (leftx < 0) {
    leftx = 0;
  }
  if (topy < 0) {
    topy = 0;
  }
  for (int j = topy; j <= bottomy && j < 7; j++) {
    for (int i = leftx; i <= rightx && i < 7; i++) {
      cout << cells[i][j]->getText();
    }
  }
}

void Game::printHelp() {
  cout << "In this game the goal is to find and open the treasure chest \nhidden somewhere in a labyrinth on a tropical island. \nYou will know you are near the chest when Your heart starts to race. \nTo open the treasure chest, you must collect one of the two keys on the map. \nYou will know there is a key nearby because the game will print You see a small glint. \nThe key is one of two items that can be picked up, \nyou may also pick up planks, there is no clue for when a plank is nearby. \nSome areas will have quicksand, \nyou will know you are near quicksand because the game will print The ground starts to soften. \nIf you enter a quicksand area without a plank, you will be stuck, and the game is over. \nWhen moving around you may get hit in the head by falling coconuts. \nWhile dazed you may wander a little and lose track of where you are. \nYou will know falling coconuts are nearby when the game prints You hear a thunk.";
}

void Game::printMap() {
  cout << endl;
  cout << "Key:\n| = plank\n"
          "$ = Treasure Chest\n"
          "O = Quicksand\n"
          "* = Key\n"
          "+ = Player\n"
          "% = Falling coconut\n"
          ". = Empty area\n\n";
  for (int j = 0; j < 7; j++) {
    for (int i = 0; i < 7; i ++) {
      if (i == player->getXLocation() && j == player->getYLocation()) {
        cout << '+';
      } else {
        cout << cells[i][j]->getSymbol();
      }
    }
    cout << endl;
  }
  cout << endl;
}

MapArea *Game::getMapArea(char type, int i, int j) {
  switch (type) {
    case '|':
      return new MapAreaWithPlanks(i, j);
    case '$':
      return new MapAreaWithChest(i, j);
    case 'O':
      return new MapAreaWithQuicksand(i, j);
    case '*':
      return new MapAreaWithKey(i, j);
    case '%':
      return new MapAreaWithCoconuts(i, j);
    case '.':
      return new MapArea(i, j);
    case '+':
      player->setLocation(i,j);
      return new MapArea(i, j);
  }
  return nullptr;
}