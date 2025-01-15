#include <iostream>
using namespace std;

int numbers[] = {2653, 8273, 798, 624, 2, 76, 4567, 987};
int numbersSorted[] = {1, 2, 3, 4, 6, 7, 8, 9, 10, 11};

bool binarySearch(int x, int* numArray, int lowerBound, int upperBound)
{
    if(upperBound >= lowerBound)
    {
        int midElemIndex = lowerBound + (upperBound - lowerBound) / 2;
        if(x == numArray[midElemIndex])
            return true;
        else if(x > numArray[midElemIndex])
            return binarySearch(x, numArray, midElemIndex + 1, upperBound);
        else
            return binarySearch(x, numArray, lowerBound, midElemIndex - 1);
    }
    return false;
}

bool bruteForceSearch(int x, int* numArray, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(numArray[i] == x)
            return true;
    }
    return false;
}

int main()
{
    if(binarySearch(6, numbersSorted, 0, 9))
    {
        cout << "FOUND!!";
    }
    else
    {
        cout << "NOT FOUND!!";
    }
}