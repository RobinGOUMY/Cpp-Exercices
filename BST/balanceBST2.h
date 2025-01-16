#ifndef BALANCE_BST2_H
#define BALANCE_BST2_H

#include "header.h"

using pii = pair<int, int>;

typedef struct node {
    pii data;
    struct node* leftChild;
    struct node* rightChild; 
} Node;

void inOrderStorage(Node*& root, vector<int>& nodeValues)
{
    if(root != NULL)
    {
        inOrderStorage(root->leftChild, nodeValues);
        nodeValues.push_back(root->data.first);
        inOrderStorage(root->rightChild, nodeValues);
    }
}

void sortedArrayToBalancedBST(Node*& root, vector<int>& nodeValues, int start, int end)
{
    if(start > end)
        return;

    int median = (start + end)/2;
    Node* newNode = new Node;
    newNode->data.first = nodeValues[median];
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    root = newNode;

    sortedArrayToBalancedBST(newNode->leftChild, nodeValues, start, median - 1);
    sortedArrayToBalancedBST(newNode->rightChild, nodeValues, median + 1, end);
}

void balanceBST(Node*& root)
{
    vector<int> nodeValuesInOrder;

    inOrderStorage(root, nodeValuesInOrder);

    sortedArrayToBalancedBST(root, nodeValuesInOrder, 0, nodeValuesInOrder.size() - 1);
}

#endif