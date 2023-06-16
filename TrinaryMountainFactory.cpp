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
*   TrinaryMountainFactory.cpp
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

#include "TrinaryMountainFactory.h"

TrinaryMountainFactory::~TrinaryMountainFactory()
{
	delete[] root;

	delete[] r1;
	delete[] r2;
	delete[] r3;

	delete[] r11;
	delete[] r12;
	delete[] r13;

	delete[] r21;
	delete[] r22;
	delete[] r23;

	delete[] r31;
	delete[] r32;
	delete[] r33;

	delete[] r331;
}

// Get mountain top override
MountainCave* TrinaryMountainFactory::getMountainTop()
{
	return getSmallStaticMountainTop();
}

MountainCave* TrinaryMountainFactory::getSmallStaticMountainTop()
{
	MountainCave* root = new MountainCave("Mountain Top", "The air density here seems to indicate you're not far from the base of the mountain");

	MountainCave* r1 = new MountainCave(root, "Craggy Cliff", "This small passage makes it difficult to see ahead");    // leaf
	MountainCave* r2 = new MountainCave(root, "Dragon's Alley", "This cave has huge rocks covered in multi-leaf clovers");	  //leaf
	MountainCave* r3 = new MountainCave(root, "Fox Den", "This cave has huge rocks covered in multi-leaf clovers");    //leaf

	MountainCave* r11 = new MountainCave(r1, "Sword Room", "This cave has huge rocks covered in multi-leaf clovers");		//leaf
	MountainCave* r12 = new MountainCave(r1, "Shield Room", "This cave has huge rocks covered in multi-leaf clovers");		//leaf
	MountainCave* r13 = new MountainCave(r1, "Helm Room", "This cave has huge rocks covered in multi-leaf clovers");		//leaf

	MountainCave* r21 = new MountainCave(r2, "Thief's Pass", "This cave has huge rocks covered in multi-leaf clovers");	  //leaf
	MountainCave* r22 = new MountainCave(r2, "Warrior's Way", "This cave has huge rocks covered in multi-leaf clovers");	  //leaf
	MountainCave* r23 = new MountainCave(r2, "Priest's Path", "This cave has huge rocks covered in multi-leaf clovers");	  //leaf

	MountainCave* r31 = new MountainCave(r3, "Gem Mine", "This cave has huge rocks covered in multi-leaf clovers");		//leaf
	MountainCave* r32 = new MountainCave(r3, "Alabaster Room", "This cave has huge rocks covered in multi-leaf clovers");	//leaf
	MountainCave* r33 = new MountainCave(r3, "Underground River", "This cave has huge rocks covered in multi-leaf clovers");	//leaf

	MountainCave* r331 = new MountainCave(r33, "Treasure Room", "The golden scales are here!");	//leaf

	r33->setAdjacentToScales(true);
	r331->setHasScales(true);

	return root;
}
