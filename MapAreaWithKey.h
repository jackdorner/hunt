//
// Created by schoenfeldsa on 3/25/2025.
//

#ifndef MAPAREAWITHKEY_H
#define MAPAREAWITHKEY_H

#include "MapArea.h"
#include <string>

class MapAreaWithKey : public MapArea {
private:
  bool keyTaken;

public:
  MapAreaWithKey(int xCoord, int yCoord);
  std::string getText() const override;
  bool pickUpItem() override;
};

#endif // MAPAREAWITHKEY_H