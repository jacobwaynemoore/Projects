#include "Utility.h"

#include <iostream>
using namespace std;

template <typename T>
void Utility::printArray (T arr[])
{
    for (int i = 0; i < arr.length(); i ++) {
        cout << arr[i] << endl;
    }
}

template <typename T>
void Utility::printArrayWithLineNums (T arr[])
{
    for (int i = 0; i < arr.length(); i ++) {
        cout << i << ": " << arr[i] << endl;
    }
}