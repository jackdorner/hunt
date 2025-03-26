//
// Created by dornerj on 3/25/2025.
//

#ifndef HUNT_PLAYER_H
#define HUNT_PLAYER_H
class Player {
public:
  Player();
  int getXLocation();
  int getYLocation();
  void setLocation(int newx, int newy);
  void pickupPlank();
  void pickupKey();

private:
    int x;
    int y;
    int numPlanks = 0;
    bool hasKey = false;
};
#endif //HUNT_PLAYER_H
