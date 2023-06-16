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
*   StackBasedWumpusHunter.cpp
*/

/**
 * WumpusHunter subclass StackBasedWumpusHunter
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

#include "StackBasedWumpusHunter.h"

StackBasedWumpusHunter::~StackBasedWumpusHunter()
{
    // nothing to do
}

string StackBasedWumpusHunter::getName()
{
    return "StackBasedV1Hunter";
}

void StackBasedWumpusHunter::startAt(MountainCave* root)
{
    // Convert tree to stack
    treeToStackBuild(root);

    // Simplify with a found flag
    bool scalesFound = false;

    // Search caves in stack for scales
    while (!resultStack.empty() && !scalesFound)
    {
        // Build search report
        actionLog += "Entering the " + resultStack.top()->getCaveName() + "\n";

        // Check if the cave is adjacent to scales
        if (resultStack.top()->isAdjacentToScales())
        {
            actionLog += "We've neared the scales! \n";
        }

        // Check if the cave has scales
        if (resultStack.top()->hasScales())
        {
            // Cave has scales, add to treasureCavesFound
            treasureCavesFound.push_back(resultStack.top());

            // Set scales found to true for efficiency
            scalesFound = true;
        }

        resultStack.pop();
    }

    buildReportToScales();
}

// Build report method
void StackBasedWumpusHunter::buildReportToScales()
{
    // Check if any scales were found
    if (treasureCavesFound.size() >= 1)
    {
        actionLog += "We've found the scales!... The path is... \n";

        // Add path from each treasure cave to root via parents
        for (size_t i = 0; i < treasureCavesFound.size(); i++)
        {
            // Build path from the treasure to the root
            vector<MountainCave*> pathToRoot;
            pathToRoot.push_back(treasureCavesFound[i]);

            MountainCave* currentCave = treasureCavesFound[i];
            while (currentCave->hasParent())
            {
                currentCave = currentCave->getParent();
                pathToRoot.push_back(currentCave);
            }

            // Reverse path so it goes from root to treasure
            reverse(pathToRoot.begin(), pathToRoot.end());

            actionLog += "Start at the " + pathToRoot[0]->getCaveName();
            if (pathToRoot.size() > 1)
            {
                actionLog += " and \n";
            }

            // Log the path from root to treasure
            for (size_t j = 1; j < pathToRoot.size(); j++)
            {
                actionLog += "then visit " + pathToRoot[j]->getCaveName();
                if (j < pathToRoot.size() - 1)
                {
                    actionLog += " and \n";
                }
            }
            actionLog += "\n";
        }
    }
    else
    {
        actionLog += "We didn't find any scales. \n";
    }
}

// Convert tree to stack method
void StackBasedWumpusHunter::treeToStackBuild(MountainCave* treeRoot)
{
    traversalStack.push(treeRoot);

    while (!traversalStack.empty())
    {
        MountainCave* currentNode = traversalStack.top();
        traversalStack.pop();

        resultStack.push(currentNode);

        // Push all child nodes onto the traversal stack
        vector<MountainCave*> theChildren = currentNode->getChildren();
        for (size_t i = 0; i < theChildren.size(); i++)
        {
            traversalStack.push(theChildren[i]);
        }
    }
}

string StackBasedWumpusHunter::report()
{
    return actionLog;
}
