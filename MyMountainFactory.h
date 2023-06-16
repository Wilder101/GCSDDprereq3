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
    MountainCave* getMountainTop() override
    {
        return getBigMountainTop();
    }

    MyMountainFactory()
    {
        root = nullptr;
    }

    ~MyMountainFactory()
    {
        delete[] root;
        
        for (auto cave : caves)
        {
			delete[] cave;
		}
    }

  private:
    MountainCave* getBigMountainTop()
    {
        const int capacity = 2;     // Capacity of max children
        
        // Set root cave
        MountainCave* root = new MountainCave("Mountain Top", "The air density here seems to indicate you're not far from the base of the mountain");

        caves.push_back(root);

        int parentIdx = 0;
        int childIdx = 1;

        while (childIdx < NUMBER_OF_CAVES) 
        {
            MountainCave* parent = caves[parentIdx];

            while (parent->getNumberOfChildren() < capacity && childIdx < NUMBER_OF_CAVES) 
            {
                string tempCaveName = "Cave: " + to_string(childIdx);
                string tempCaveMsg = "This is the inside of cave " + to_string(childIdx);
                MountainCave* child = new MountainCave(parent, tempCaveName, tempCaveMsg);
                
                parent->addChild(child);
                caves.push_back(child);
                ++childIdx;
            }
            ++parentIdx;
        }

        // Set cave values explicitly; ref: NUMBER_OF_CAVES
        caves[5]->setAdjacentToScales(true);
        caves[9]->setHasScales(true);

        // Test cave count; commented out for future development
        // cout << "Number of caves is: " << caves.size() << endl;

        return root;
    }

    //BinaryMountainFactory data items
    static const int NUMBER_OF_CAVES = 10;

    MountainCave* root;
    vector<MountainCave*> caves;
};
