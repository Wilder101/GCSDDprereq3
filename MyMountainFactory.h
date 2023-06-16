#pragma once

/*  Wilder Molyneux
*   University of Washington | Bothell (UWB)
*   Graduate Certificate in Software Design and Development (GCSDD)
*   Prerequisite Sample Coursework
*   June 15, 2023
*
*   Dr. Emily M. Bender Rule: C++
*
*   From UWB Computing & Software Systems (CSS) 143
*   Programming Competency Self-Assessment: First Assessment (three of four)
*   "Wumpus Mountain"
*
*   MyMoutainFactory.h
*/

/**
 * MyMoutainFactory
 *
 */

#include "MountainFactory.h"

class MyMountainFactory : public MountainFactory
{
  public:
    MyMountainFactory();
    ~MyMountainFactory();
    MountainCave* getMountainTop() override;

  private:
    MountainCave* getBigMountainTop();

    //MyMountainFactory data items
    static const int NUMBER_OF_CAVES = 10;
    MountainCave* root;
    vector<MountainCave*> caves;
};
