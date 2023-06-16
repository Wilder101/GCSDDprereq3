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
*   MountainCave.h
*/

/*
 *
 * MountainCave.java (converted to C++ by Wilder)
 *
 *   This class is built for this exercise only, and has some serious
 *   flaws "by design" just so we could traverse the tree directly
 *   from our WumpusHunter code. For a better design, we would have
 *   separate classes for the tree and internal nodes (rather than
 *   packing them together here), and we'd never return private
 *   aliases for our nodes. And the list goes on...
 *
 *   To try to keep things organized, I have sorted the methods into
 *   those you can call from your MyWumpusHunter, those called from a
 *   MountainFactory, and internal stuff you shouldn't need to mess
 *   with.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class MountainCave 
{
    // The following are accessors for your Hunter
  public:

     string getCaveName() 
     {
        return caveName;
     }

     vector<MountainCave*> getChildren()
    {
        return children;
    }

    string getCaveMessage() 
    {
        return caveMessage;
    }

    bool hasScales() 
    {
        return hasWumpusScales;
    }

    bool isAdjacentToScales() 
    {
        return adjacentToScales;
    }

    // Next, we have methods that we call from a MountFactory:

    /**
     * This is the preferred constructor to use. It "attaches" the
     * cave to its parent (and the parent to its child) and assigns it
     * a name and description. The other constructors are near the end
     * of the class.
     */

    MountainCave(MountainCave* theParent, string name, string message) 
        : MountainCave(name, message)
    {
        if (theParent != nullptr) 
        {
            parent = theParent;     
            parent->addChild(this);
        }
    }

    void setAdjacentToScales(bool adjacentToScales)
    {
        this->adjacentToScales = adjacentToScales;
    }

    void setHasScales(bool hasWumpusScales) 
    {
        this->hasWumpusScales = hasWumpusScales;
    }

    void setCaveMessage(string caveName) 
    {
        this->caveName = caveName;
    }

    // And finally, methods that are used internally and that you are
    // unlikely to need to use.

    MountainCave(string name, string message) 
    {
        caveName = name;
        caveMessage = message;
    }

    MountainCave(string name) 
        : MountainCave(name, "")
    {
        // nothing else to do
    }

    void setParent(MountainCave* theParent) 
    {
        parent = theParent;
        parent->addChild(this);
    }

    void addChild(MountainCave* next) 
    {
        if (next != nullptr) 
        {
            children.push_back(next);
        }
    }

    MountainCave* getParent() 
    {
        return parent;
    }

    bool hasParent()
    {
        if (parent == nullptr) 
        {
            return false;
        }
        return true;
    }

    // Wilder addition to the class
    bool hasChildren()
	{
		if (children.size() == 0) 
		{
			return false;
		}
		return true;
	}

    // Wilder addition to the class
    int getNumberOfChildren()
    {
        return int (children.size());    // explicit cast size_t to int
    }

  private:

    //node structure pointers
    MountainCave* parent = nullptr;
    vector<MountainCave*> children;

    //MountainCave data items
    string caveMessage;
    string caveName;
    bool adjacentToScales = false;
    bool hasWumpusScales = false;

};  
