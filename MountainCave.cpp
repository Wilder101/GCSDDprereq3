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
*   MountainCave.cpp -- order of methods as per assignment instructions
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

#include "MountainCave.h"

   // The following are accessors for your Hunter

    string MountainCave::getCaveName()
    {
        return caveName;
    }

    vector<MountainCave*> MountainCave::getChildren()
    {
        return children;
    }

    string MountainCave::getCaveMessage()
    {
        return caveMessage;
    }

    bool MountainCave::hasScales()
    {
        return hasWumpusScales;
    }

    bool MountainCave::isAdjacentToScales()
    {
        return adjacentToScales;
    }

    // Next, we have methods that we call from a MountainFactory:
    /**
     * This is the preferred constructor to use. It "attaches" the
     * cave to its parent (and the parent to its child) and assigns it
     * a name and description. The other constructors are near the end
     * of the class.
     */

    // Delegating constructor
    MountainCave::MountainCave(MountainCave* theParent, string name, string message)
        : MountainCave(name, message)
    {
        if (theParent != nullptr)
        {
            parent = theParent;
            parent->addChild(this);
        }
    }

    void MountainCave::setAdjacentToScales(bool adjacentToScales)
    {
        this->adjacentToScales = adjacentToScales;
    }

    void MountainCave::setHasScales(bool hasWumpusScales)
    {
        this->hasWumpusScales = hasWumpusScales;
    }

    void MountainCave::setCaveMessage(string caveName)
    {
        this->caveName = caveName;
    }

    // And finally, methods that are used internally and that you are
    // unlikely to need to use.

    MountainCave::MountainCave(string name, string message)
    {
        caveName = name;
        caveMessage = message;
    }

    MountainCave::MountainCave(string name)
        : MountainCave(name, "")
    {
        // nothing else to do
    }

    void MountainCave::setParent(MountainCave* theParent)
    {
        parent = theParent;
        parent->addChild(this);
    }

    void MountainCave::addChild(MountainCave* next)
    {
        if (next != nullptr)
        {
            children.push_back(next);
        }
    }

    MountainCave* MountainCave::getParent()
    {
        return parent;
    }

    bool MountainCave::hasParent()
    {
        if (parent == nullptr)
        {
            return false;
        }
        return true;
    }

    // Wilder addition to the class
    bool MountainCave::hasChildren()
    {
        if (children.size() == 0)
        {
            return false;
        }
        return true;
    }

    // Wilder addition to the class
    int MountainCave::getNumberOfChildren()
    {
        return int(children.size());    // explicit cast size_t to int
    }
