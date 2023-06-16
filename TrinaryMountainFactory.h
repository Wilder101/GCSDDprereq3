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
*   TrinaryMountainFactory.h
*/

/**
 * TrinaryMoutainFactory
 *
 * 	Offers a small tree with 0-3 children per node.
 *
 * 	This is useful for testing the generality of your WumpusHunter
 * 	solution. Creates a small set of caves.
 *
 */

#include "MountainFactory.h"

class TrinaryMountainFactory : public MountainFactory
{
  public:
	~TrinaryMountainFactory();
	MountainCave* getMountainTop() override;

  private:
	MountainCave* getSmallStaticMountainTop();

	//TrinaryMountainFactory data items
	MountainCave* root;

	MountainCave* r1;
	MountainCave* r2;
	MountainCave* r3;

	MountainCave* r11;
	MountainCave* r12;
	MountainCave* r13;

	MountainCave* r21;
	MountainCave* r22;
	MountainCave* r23;

	MountainCave* r31;
	MountainCave* r32;
	MountainCave* r33;

	MountainCave* r331;
};
