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
*   MountainFactory.h
*/

#include "MountainCave.h"

/*
 * MountainFactory
 *
 *   This class provides a uniform way to obtain "mountains", which
 *   are really just trees (and the one function below returns the
 *   root of the tree).
 */

class MountainFactory 
{
  public:
    virtual MountainCave* getMountainTop() = 0;
};
