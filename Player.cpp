//
// Created by dornerj on 3/25/2025.
//
#include "Player.h"

int Player::getXLocation() {
  return x;
}

int Player::getYLocation() {
  return y;
}

void Player::setLocation(int newx, int newy) {
  x = newx;
  y = newy;
}

void Player::pickupPlank() {
  numPlanks++;
}

void Player::pickupKey() {
  hasKey = true;
}

Player::Player() {}