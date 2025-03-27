//
// Created by schoenfeldsa on 3/25/2025.
//

#ifndef MAPAREAWITHCOCONUTS_H
#define MAPAREAWITHCOCONUTS_H

#include "MapArea.h"
#include <string>

class MapAreaWithCoconuts : public MapArea {
public:
  MapAreaWithCoconuts(int xCoord, int yCoord);
  std::string getText() const override;
  char getSymbol() const override;

};

#endif // MAPAREAWITHCOCONUTS_H

