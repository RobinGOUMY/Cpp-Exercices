#include "header.h"
#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

// Function to perform binary search on cars by ID
// Inputs: Car_list - list of cars, low - lower bound, high - upper bound, searchID - ID to search for
// Output: Index of the car if found, -1 otherwise
int binarySearch(vector<Car>& Car_list, int low, int high, int searchID) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // Middle index
        if (searchID == Car_list[mid].ID){
            return mid;
        }
        if (searchID > Car_list[mid].ID){
            low = mid + 1;
        }
        if (searchID < Car_list[mid].ID){
            high = mid - 1;
        }
    }
    return -1;
}


#endif