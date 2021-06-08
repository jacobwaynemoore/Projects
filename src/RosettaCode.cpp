#include "RosettaCode.h"

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

RosettaCode::RosettaCode()
{

}

//------------------------------------------------------------------------------
// There are 100 doors in a row that are all initially closed.
// You make 100 passes by the doors.
// The first time through, visit every door and  toggle  the door  (if the door is closed,  open it;   if it is open,  close it).
// The second time, only visit every 2nd door   (door #2, #4, #6, ...),   and toggle it.
// The third time, visit every 3rd door   (door #3, #6, #9, ...), etc,   until you only visit the 100th door.
// Challenge url: http://rosettacode.org//wiki/100_doors
//------------------------------------------------------------------------------
void RosettaCode::oneHundredDoors()
{
    // The doors, true is open, false is closed
    bool doors[101] {false};
    // By definitoin, the step value increments each time
    int step = 1;
    while (step != 100) {
        // Open the closed doors and close the open ones
        for (int i = 1; i < 101; i += step) {
            doors[i] = !doors[i];
        }
        step++;
    }
    // Output
    printDoors(doors);
}

//------------------------------------------------------------------------------
// Helper function for oneHundredDoors()
//------------------------------------------------------------------------------
void RosettaCode::printDoors(bool doors[101])
{
    for (int i = 1; i < 101; i++) {
        if (doors[i]) {
            std::cout << "Door " << i - 1 << " is open." << std::endl;
        }
    }
}

//------------------------------------------------------------------------------
// TODO enter description
//------------------------------------------------------------------------------
void RosettaCode::twentyFour()
{
    srand(time(NULL));
    int first  = rand() % 9 + 1;
    int second = rand() % 9 + 1;
    int third  = rand() % 9 + 1;
    int fourth = rand() % 9 + 1;
    std::cout << "Try to make 24 with these four numbers." << std::endl;
    std::cout << first << " " << second << " " << third << " " << fourth << std::endl;
    std::string input;
    getline(std::cin, input);
    std::string preParse = "";
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
            preParse.push_back(input[i]);
        }
    }
    parseTwentyFour(preParse, first, second, third, fourth);
}

void RosettaCode::parseTwentyFour(std::string input, int first, int second, int third, int fourth)
{

}

//------------------------------------------------------------------------------
// TODO add description
//------------------------------------------------------------------------------
void RosettaCode::nineBillionNames(int const n)
{
    partitionTable.resize(n);
    for (int i = 0; i < n; i++) {
        partitionTable[i].resize(n);
    }

    partition(n-1, n-2);

    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            std::cout << partitionTable[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//------------------------------------------------------------------------------
// partition()
//------------------------------------------------------------------------------
int RosettaCode::partition(int sumToReach, int largest)
{
    if (largest == 0 || sumToReach < 0) {
        return 0;
    }
    if (sumToReach == 0) {
        return 1;
    }
    if (partitionTable[sumToReach][largest] != 0) {
        return partitionTable[sumToReach][largest];
    }

    partitionTable[sumToReach][largest] = partition(sumToReach, largest - 1) + partition(sumToReach - largest, largest);
    return partitionTable[sumToReach][largest];
}

//------------------------------------------------------------------------------
// partition()
//------------------------------------------------------------------------------
void RosettaCode::bottlesOnWall(int n)
{
    for (int i = n; i > 0; i--) {
        char print[113];
        if (i != 1) {
            sprintf(print, "%d bottles of beer on the wall\n%d bottles of beer\nTake one down, pass it around\n%d bottles of beer on the wall\n", i, i, i - 1);
        }
        else {
            sprintf(print, "%d bottle of beer on the wall\n%d bottle of beer\nTake one down, pass it around\n%d bottles of beer on the wall\n", i, i, i - 1);
        }
        std::cout << print << std::endl;
    }
}

//------------------------------------------------------------------------------
// TODO add description
//------------------------------------------------------------------------------
void RosettaCode::aPlusB()
{
    std::string nums;
    getline(std::cin, nums);
    int sum = (nums[0] - 48) + (nums[2] - 48);
    std::cout << "The sum of " << nums[0] << " and " << nums[2] << " is " << sum << std::endl;
}

//------------------------------------------------------------------------------
// TODO add description
//------------------------------------------------------------------------------
void RosettaCode::abc(std::string word, std::vector<std::pair<char, char>> blocks)
{
    bool canMake {};
    bool* usedBlocks = new bool[blocks.size()] {};
    for (int i = 0; i < word.length(); i++) {
        bool matched {};
        char toMatch = toupper(word[i]);
        for (int j = 0; j < blocks.size(); j++) {
            if (!usedBlocks[j]) {
                char front = toupper(blocks[j].first);
                char back = toupper(blocks[j].second);
                if (front == toMatch || back == toMatch) {
                    matched = true;
                    usedBlocks[j] = true;
                    break;
                }
            }
        }
        if (matched == true) {
            canMake = true;
        }
        else {
            canMake = false;
            break;
        }
    }
    if (canMake) {
        std::cout << "You can make the word " << word << " with the given blocks." << std::endl;
    }
    else {
        std::cout << "You can not make the word " << word << " with the given blocks." << std::endl;
    }
}

//------------------------------------------------------------------------------
// TODO add description
//------------------------------------------------------------------------------
long long RosettaCode::ackermann(int m, int n)
{
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return ackermann(m - 1, 1);
    }
    return ackermann(m - 1, ackermann(m, n - 1));
}

//------------------------------------------------------------------------------
// TODO add description
//------------------------------------------------------------------------------
void RosettaCode::priceFraction(double t)
{
    if ( t >=  0.00 && t <  0.06) t =  0.10;
    else if ( t >=  0.06 && t <  0.11) t =  0.18;
    else if ( t >=  0.11 && t <  0.16) t =  0.26;
    else if ( t >=  0.16 && t <  0.21) t =  0.32;
    else if ( t >=  0.21 && t <  0.26) t =  0.38;
    else if ( t >=  0.26 && t <  0.31) t =  0.44;
    else if ( t >=  0.31 && t <  0.36) t =  0.50;
    else if ( t >=  0.36 && t <  0.41) t =  0.54;
    else if ( t >=  0.41 && t <  0.46) t =  0.58;
    else if ( t >=  0.46 && t <  0.51) t =  0.62;
    else if ( t >=  0.51 && t <  0.56) t =  0.66;
    else if ( t >=  0.56 && t <  0.61) t =  0.70;
    else if ( t >=  0.61 && t <  0.66) t =  0.74;
    else if ( t >=  0.66 && t <  0.71) t =  0.78;
    else if ( t >=  0.71 && t <  0.76) t =  0.82;
    else if ( t >=  0.76 && t <  0.81) t =  0.86;
    else if ( t >=  0.81 && t <  0.86) t =  0.90;
    else if ( t >=  0.86 && t <  0.91) t =  0.94;
    else if ( t >=  0.91 && t <  0.96) t =  0.98;
    else if ( t >=  0.96 && t <  1.01) t =  1.00;
    std::cout << t << std::endl;
}


