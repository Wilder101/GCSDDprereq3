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
*   BinaryMountainFactory.h
*/

/**
 * BinaryMoutainFactory
 * 	Creates a small tree with 0-2 children per node.
 * 	This should be where you start testing your WumpusHunter
 * 	solution.
 *
 *      It's pretty simple, actually. We creat new "caves", passing
 *      the "parent" to the constructor, along with the cave's name
 *      and a short description string. We also indicate which cave
 *      has the golden scales and which cave is adjacent to that one.
 *
 */

#include "MountainFactory.h"

class BinaryMountainFactory : public MountainFactory 
{
  public:
    ~BinaryMountainFactory();
    MountainCave* getMountainTop() override;

  private:
    MountainCave* getSmallStaticMountainTop();


    //BinaryMountainFactory data items
    MountainCave* root;
    MountainCave* r1;
    MountainCave* l1;
    MountainCave* l1r;
    MountainCave* l1l;
    MountainCave* l1r2l;
};
