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
    string getCaveName();
    vector<MountainCave*> getChildren();
    string getCaveMessage();
    bool hasScales();
    bool isAdjacentToScales();

    // Next, we have methods that we call from a MountainFactory:
    /**
     * This is the preferred constructor to use. It "attaches" the
     * cave to its parent (and the parent to its child) and assigns it
     * a name and description. The other constructors are near the end
     * of the class.
     */
    MountainCave(MountainCave* theParent, string name, string message);
    void setAdjacentToScales(bool adjacentToScales);
    void setHasScales(bool hasWumpusScales);
    void setCaveMessage(string caveName);

    // And finally, methods that are used internally and that you are
    // unlikely to need to use.
    MountainCave(string name, string message);
    MountainCave(string name);
    void setParent(MountainCave* theParent);
    void addChild(MountainCave* next);
    MountainCave* getParent();
    bool hasParent();

    // Wilder addition to the class
    bool hasChildren();

    // Wilder addition to the class
    int getNumberOfChildren();

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
