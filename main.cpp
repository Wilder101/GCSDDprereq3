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
*   main.cpp
*/

/**
 * WMDriver
 *
 * This contains a few lines of code to start things off.  Once you
 * have made a WumpusHunter subclass by extending the WumpusHunter
 * class, you'll need to change the (currently broken) line of code so
 * that it creates an object of your new class.
 *
 * The other interesting thing here is to change the MountainFactory
 * from a Binary Tree to a 3-ary (Trinary) Tree by commenting out the
 * BinaryMountainFactory line and uncommenting the
 * TrinaryMountainFactory line below.  Note too you can make your own
 * Factories for this exercise!
 *
 */

/*
Reference:
https://www.uwb.edu/getattachment/stem/graduate/gcsdd/sample-coursework/CSS143-SampleCoursework.pdf?lang=en-US
*/

#include "BinaryMountainFactory.h"
#include "BinaryMountainFactoryComplex.h"
#include "TrinaryMountainFactory.h"
#include "MyMountainFactory.h"
#include "StackBasedWumpusHunter.h"


int main() 
{
    // Round One in a given binary mountain
    WumpusHunter* myHunter = new StackBasedWumpusHunter();
    BinaryMountainFactory caveFactory = BinaryMountainFactory(); 

    //get the top of the mountain, which is the top of our tree
    MountainCave* theBeginning = caveFactory.getMountainTop();

    //begin your algorithm by writing the function below for your hunter
    myHunter->startAt(theBeginning);

    cout << "Hunter's name: " << myHunter->getName() << endl
         << "Hunter's report: " << endl
         << myHunter->report() << endl;

    // Round Two in a given trinary mountain
    WumpusHunter* myHunterTri = new StackBasedWumpusHunter();
    TrinaryMountainFactory caveFactoryTri = TrinaryMountainFactory();

    //get the top of the mountain, which is the top of our tree
    MountainCave* theBeginningTri = caveFactoryTri.getMountainTop();

    //begin your algorithm by writing the function below for your hunter
    myHunterTri->startAt(theBeginningTri);

    cout << "Hunter's name: " << myHunterTri->getName() << endl
         << "Hunter's report: " << endl
         << myHunterTri->report() << endl;

    // Round Three in a custom complex binary mountain
    WumpusHunter* myHunterComplex = new StackBasedWumpusHunter();
    BinaryMountainFactoryComplex caveFactoryComplex = BinaryMountainFactoryComplex();

    //get the top of the mountain, which is the top of our tree
    MountainCave* theBeginningComplex = caveFactoryComplex.getMountainTop();

    //begin your algorithm by writing the function below for your hunter
    myHunterComplex->startAt(theBeginningComplex);

    cout << "Hunter's name: " << myHunterComplex->getName() << endl
         << "Hunter's report: " << endl
         << myHunterComplex->report() << endl;

    // Round Four in a custom random binary mountain
    WumpusHunter* myHunterRandom = new StackBasedWumpusHunter();
    MyMountainFactory caveFactoryRandom = MyMountainFactory();

    //get the top of the mountain, which is the top of our tree
    MountainCave* theBeginningRandom = caveFactoryRandom.getMountainTop();

    //begin your algorithm by writing the function below for your hunter
    myHunterRandom->startAt(theBeginningRandom);

    cout << "Hunter's name: " << myHunterRandom->getName() << endl
         << "Hunter's report: " << endl
         << myHunterRandom->report() << endl;

    // Deletions for memory management
    delete myHunter;
    delete myHunterTri;
    delete myHunterComplex;
    delete myHunterRandom;
    
    return 0;
}
