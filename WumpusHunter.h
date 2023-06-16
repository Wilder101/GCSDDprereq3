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
*   WumpusHunter.h
*/

/**
 * WumpusHunter
 *
 *   This abstract class describes the two methods that you'll need to
 *   provide in your subclass - getName() and startAt().  Note that
 *   getName should be one line of code, and that all of your
 *   functionality for traversing the mountain should go in the
 *   startAt()function, which is where 98% of your code will go for
 *   this project.
 *
 *   In your subclass, when you visit caves, add this to the actionLog
 *   string, which your subclass will have direct access to.  Then,
 *   when your hunter is done exploring you can see the list of places
 *   he/she has been, and also you can embed the solution in the
 *   actionLog if you like.
 */

#include "MountainCave.h"

class WumpusHunter 
{
  public:
    virtual string getName() = 0;
    virtual void startAt(MountainCave* root) = 0;

    /**
     * Use this to build a string of where your hunter has been
     */
    string actionLog = "";

    /**
     * This is called by the driver at the end to report where your
     * hunter has been.
     */
    virtual string report() 
    {
        return actionLog;
    }

    virtual ~WumpusHunter() {}    // virtual destructor
};
