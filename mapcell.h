/*
 * mapcell.h
 */

#ifndef MAPCELL_H_
#define MAPCELL_H_

// Tracks the contents of a particular cell on the map.
// Is there gold at this location, is it occupied by a robot,
// is there a pit there? Each cell needs to track
// where it is on the grid (x, y) and the type of
// object at that location. The provided methods are suggestions;
// feel free to add/remove as needed.
class mapcell {
    int xLocation, yLocation;
    char token;
    bool hasRobot;
public:
    mapcell(int x, int y);

    // get x location
    int getXLocation();
    // get y location
    int getYLocation();
    // Prints the clue associated with the cell.
    void printText();
};

#endif /* MAPCELL_H_ */
