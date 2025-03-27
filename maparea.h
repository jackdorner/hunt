//
// Created by schoenfeldsa on 3/25/2025.
//

#ifndef MAPAREA_H
#define MAPAREA_H

#include <string>


class MapArea {
protected:
  int x;
  int y;

public:
  MapArea(int xCoord, int yCoord);
  virtual ~MapArea() = default;

  int getLocationX() const;
  int getLocationY() const;

  virtual std::string getText() const;
  virtual char getSymbol() const;
  virtual bool pickUpItem();
  virtual bool coverWithPlank();
};

#endif
//MAPAREA_H
