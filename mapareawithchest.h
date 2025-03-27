//
// Created by schoenfeldsa on 3/25/2025.
//

#ifndef MAPAREAWITHCHEST_H
#define MAPAREAWITHCHEST_H

#include "MapArea.h"
#include <string>

class MapAreaWithChest : public MapArea {
private:
  bool chestOpened;

public:
  MapAreaWithChest(int xCoord, int yCoord);
  std::string getText() const override;

  void openChest(bool hasKey);
  char getSymbol() const override;

};

#endif // MAPAREAWITHCHEST_H

