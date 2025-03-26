//
// Created by dornerj on 3/25/2025.
//

#include "Game.h"
#include <iostream>
#include <random>

Game::Game() {

  for (int j = 0; j < 6; j++) {
    for (int i = 0; i < 6; i ++) {
      cells[i][j] = new MapArea(i, j);
    }
  }
}

char Game::getInput() {

}

bool Game::move() {

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