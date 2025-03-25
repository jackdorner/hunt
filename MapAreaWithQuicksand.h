//
// Created by schoenfeldsa on 3/25/2025.
//

#ifndef MAPAREAWITHQUICKSAND_H
#define MAPAREAWITHQUICKSAND_H

#include "MapArea.h"
#include <string>

class MapAreaWithQuicksand : public MapArea {
private:
  bool covered;

public:
  MapAreaWithQuicksand(int xCoord, int yCoord);
  std::string getText() const override;
  bool coverWithPlank() override;
};

#endif // MAPAREAWITHQUICKSAND_H

