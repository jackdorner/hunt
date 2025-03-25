//
// Created by schoenfeldsa on 3/25/2025.
//

#ifndef MAPAREAWITHPLANKS_H
#define MAPAREAWITHPLANKS_H

#include "MapArea.h"

class MapAreaWithPlanks : public MapArea {
private:
  bool plankTaken;

public:
  MapAreaWithPlanks(int xCoord, int yCoord);

  bool pickUpItem() override;
};

#endif // MAPAREAWITHPLANKS_H

