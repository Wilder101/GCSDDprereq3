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
*   BinaryMountainFactory.cpp
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

#include "BinaryMountainFactory.h"

// Destructor - clean up allocated memory
BinaryMountainFactory::~BinaryMountainFactory()
{
	delete[] root;
	delete[] r1;
	delete[] l1;
	delete[] l1r;
	delete[] l1l;
	delete[] l1r2l;
}

// Get mountain top override
MountainCave* BinaryMountainFactory::getMountainTop()
{
    return getSmallStaticMountainTop();
}

// Get small static mountain top
MountainCave* BinaryMountainFactory::getSmallStaticMountainTop()
{
    MountainCave* root = new MountainCave("Mountain Top", "The air density here seems to indicate you're not far from the base of the mountain");

    MountainCave* r1 = new MountainCave(root, "Clover Cove", "This cave has huge rocks covered in multi-leaf clovers");    // leaf
    MountainCave* l1 = new MountainCave(root, "Crooked Way", "This small passage makes it difficult to see ahead");

    MountainCave* l1r = new MountainCave(l1, "Hidden Nook", "The ground can't be far from here");
    MountainCave* l1l = new MountainCave(l1, "Snake Room", "It would seem snakes have inhabited this room in the past");    // leaf

    MountainCave* l1r2l = new MountainCave(l1r, "Treasure Room", "The golden scales are here!");    // leaf

    l1r->setAdjacentToScales(true);
    l1r2l->setHasScales(true);

    return root;
}
