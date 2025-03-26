//
// Created by dornerj on 3/25/2025.
//

#include "Game.h"
#include <iostream>
#include <random>
#include <cctype>

using namespace std;

Game::Game() {

  for (int j = 0; j < 6; j++) {
    for (int i = 0; i < 6; i ++) {
      cells[i][j] = new MapArea(i, j);
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
  bool over = false;
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

}

bool Game::moveSouth() {

}

bool Game::moveEast() {

}

bool Game::moveWest() {

}

void Game::printSurrounding() {

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
  for (int j = 0; j < 6; j++) {
    for (int i = 0; i < 6; i ++) {
      cout << cells[i][j]->getSymbol();
    }
    cout << endl;
  }
  cout << endl;
}

MapArea *Game::getMapArea() {
  std::random_device rd;
  std::mt19937 gen(rd());

  // Define the distribution
  std::uniform_int_distribution<> distr(0, 6);

  // Generate a random number within the range
  int random_number = distr(gen);

  if (random_number == 0) {

  }
}