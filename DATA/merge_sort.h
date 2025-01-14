#include "header.h"
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

// Function to merge two halves of a car list
// Inputs: Car_list - list of cars, lowerB - lower bound, mid - middle index, UpperB - upper bound
// Output: None
void merge(vector<Car>& Car_list, int lowerB, int mid, int UpperB) {
    int sizeLeft = mid - lowerB + 1; // Size of left half
    int sizeRight = UpperB - mid; // Size of right half

    vector<Car> leftArray(sizeLeft); // Left half array
    vector<Car> rightArray(sizeRight); // Right half array

    for (int i = 0; i < sizeLeft; ++i) {
        leftArray[i] = Car_list[lowerB + i];
    }
    for (int i = 0; i < sizeRight; ++i) {
        rightArray[i] = Car_list[mid + 1 + i];
    }

    int i = 0, j = 0, k = lowerB; // Indices for merging

    while ((i < sizeLeft) && (j < sizeRight)) {
        if (leftArray[i].ID <= rightArray[j].ID) {
            Car_list[k] = leftArray[i];
            ++i;
        } else {
            Car_list[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < sizeLeft) {
        Car_list[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < sizeRight) {
        Car_list[k] = rightArray[j];
        ++j;
        ++k;
    }
}

// Function to perform merge sort on a list of cars
// Inputs: Car_list - list of cars, lowerB - lower bound, upperB - upper bound
// Output: None
void mergeSort(vector<Car>& Car_list, int lowerB, int upperB){
    if (lowerB >= upperB){
        return;
    }

    int mid = lowerB + (upperB - lowerB) / 2; // Middle index
    mergeSort(Car_list, lowerB, mid);
    mergeSort(Car_list, mid + 1, upperB);
    merge(Car_list, lowerB, mid, upperB);
}

#endif