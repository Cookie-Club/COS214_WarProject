#ifndef CELL_H
#define CELL_H
#include <vector>
class Squad;
class Cell {

protected:
    int x;
    int y;
    Squad* occupyingForce;

public:
    Cell();
    void removeOccupyingForce(Squad* m);
    virtual void setOccupyingForce(Squad* m);
    Squad* getOccupyingForce();
    void setCoordinates(int _x, int _y);
    int getX();
    int getY();
    virtual void add(Cell * addition){};
    virtual void execute(Squad * m){};
};

#endif

#include "Squad.h"