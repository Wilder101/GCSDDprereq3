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
*   BinaryMountainFactoryComplex.cpp
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

#include "BinaryMountainFactoryComplex.h"

// Destructor
BinaryMountainFactoryComplex::~BinaryMountainFactoryComplex()
{
    delete[] root;
    delete[] r1;
    delete[] l1;
    delete[] l1r;
    delete[] l1l;

    delete[] r1r;
    delete[] r1l;
    delete[] l1r2l;
    delete[] l1l2l;
    delete[] l1l2r;

    delete[] r1r2l;
    delete[] r1r2r;
    delete[] r1r2r3l;
    delete[] l1r2r;
    delete[] l1l2r3l;

    delete[] l1l2r3l4l;
}

// Get mountain top override
MountainCave* BinaryMountainFactoryComplex::getMountainTop()
{
    return getSmallStaticMountainTop();
}

// Get small static mountain top
MountainCave* BinaryMountainFactoryComplex::getSmallStaticMountainTop()
{
    MountainCave* root = new MountainCave("Mountain Top", "The air density here seems to indicate you're not far from the base of the mountain");

    MountainCave* r1 = new MountainCave(root, "Clover Cove", "This cave has huge rocks covered in multi-leaf clovers");
    MountainCave* l1 = new MountainCave(root, "Crooked Way", "This small passage makes it difficult to see ahead");

    MountainCave* l1r = new MountainCave(l1, "Hidden Nook", "The ground can't be far from here");
    MountainCave* l1l = new MountainCave(l1, "Snake Room", "It would seem snakes have inhabited this room in the past");

    // Additional caves for complexity
    MountainCave* r1r = new MountainCave(r1, "Crooked Nook", "There is a bent root in here");
    MountainCave* r1l = new MountainCave(r1, "Crooked Snake Room", "It would seem snakes were here recently");    // leaf

    MountainCave* l1r2l = new MountainCave(l1r, "Mystery Cafe", "The great mystery may or may not have been in here");    // leaf

    MountainCave* l1l2l = new MountainCave(l1l, "Boom Room", "Blast evidence from the past here");    // leaf
    MountainCave* l1l2r = new MountainCave(l1l, "Log Room", "Some logs were left here for snakes");

    MountainCave* r1r2l = new MountainCave(r1r, "Flower Nook", "Some old flowers were left in here");    // leaf
    MountainCave* r1r2r = new MountainCave(r1r, "Flower Room", "Some flowers were left in her recently");

    MountainCave* r1r2r3l = new MountainCave(r1r2r, "Flat Way", "The cave floor is flat here");    // leaf

    MountainCave* l1r2r = new MountainCave(l1r, "Historical Cave", "Some books were left for reading");    // leaf
    MountainCave* l1l2r3l = new MountainCave(l1l2r, "Quite Brook", "A small stream is in here");

    MountainCave* l1l2r3l4l = new MountainCave(l1l2r3l, "Treasure Room", "The golden scales are here!");    // leaf       
    l1l2r3l->setAdjacentToScales(true);
    l1l2r3l4l->setHasScales(true);

    return root;
}
