/**
    \file WorldMap.h
    \class WorldMap
    \brief Creates the Map for the simulation
    \details Creates a 2D array of Cells. Each Cell is decorated with the type of cell it is and features that it has
    \author Megan Hugo
*/
#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <cstdlib>

class FeatureFactory;

class Cell;

class WorldMap {
protected:
    Cell ***grid;
    int mapSize;
    FeatureFactory *factories;

public:
    /**
     * \fn WorldMap::WorldMap
     * \param[in] worldSize  int value to initialise the size of the map
     * \brief constructor method
     */
    WorldMap(int worldSize);

    /**
     * \fn WorldMap::~WorldMap
     * \brief destructor for WorldMap
     */
    ~WorldMap();

    /**
     * \fn WorldMap::getGrid
     * \return 2D array of cell pointers
     * \brief getter method for grid variable
     */
    Cell ***getGrid();

    /**
     * \fn WorldMap::getSize
     * \return int value of map size
     * \brief getter method for mapSize variable
     */
    int getSize();

    /**
     * \fn WorldMap::getCell
     * \param[in] x     int value for x co-ordinate of cell
     * \param[in] y     int vale for y co-ordinate of cell
     * \return cell pointer
     * \brief Method to return a specific cell with given co-ordinate
     */
    Cell *getCell(int x, int y);
};

#endif

