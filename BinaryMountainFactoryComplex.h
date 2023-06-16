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
*   BinaryMountainFactoryComplex.h
*/

/**
 * BinaryMoutainFactoryComplex -- custom mountain factory
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

class BinaryMountainFactoryComplex : public MountainFactory
{
  public:
    ~BinaryMountainFactoryComplex();
    MountainCave* getMountainTop() override;

  private:
    MountainCave* getSmallStaticMountainTop();

    //BinaryMountainFactoryComplex data items
    MountainCave* root;

    MountainCave* r1;
    MountainCave* l1;

    MountainCave* l1r;
    MountainCave* l1l;

    MountainCave* r1r;
    MountainCave* r1l;

    MountainCave* l1l2l;
    MountainCave* l1l2r;

    MountainCave* l1r2l; 

    MountainCave* r1r2l;
    MountainCave* r1r2r;

    MountainCave* r1r2r3l;

    MountainCave* l1r2r;
    MountainCave* l1l2r3l;

    MountainCave* l1l2r3l4l;
};