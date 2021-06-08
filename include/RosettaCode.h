#ifndef GAMES_H
#define GAMES_H

#include <string>
#include <vector>

class RosettaCode {
public:
    RosettaCode();
    // One hundred doors
    void oneHundredDoors();
    void printDoors(bool doors[]);
    // Twenty four
    void twentyFour();
    void parseTwentyFour(std::string input, int first, int second, int third, int fourth);
    // 9 billion names of God the integer
    void nineBillionNames(int n);
    int partition(int sumToReach, int largest);
    // 99 bottles
    void bottlesOnWall(int n);
    // A+B
    void aPlusB();
    // ABC
    void abc(std::string word, std::vector<std::pair<char, char>> blocks);
    // Ackerman function
    long long ackermann(int m, int n);
    // Price function
    void priceFraction(double t);

private:
    std::vector<std::vector<int>> partitionTable;
    std::vector<int> primes;
};

#endif