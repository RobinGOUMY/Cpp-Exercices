#include <vector>

typedef struct node {
    int data;
    struct node* leftChild;
    struct node* rightChild; 
} Node;

void inOrderStorage(Node* root, std::vector<int>& nodeValues)
{
    if(root != NULL)
    {
        inOrderStorage(root->leftChild, nodeValues);
        nodeValues.push_back(root->data);
        inOrderStorage(root->rightChild, nodeValues);
    }
}

void sortedArrayToBalancedBST(Node* root, std::vector<int>& nodeValues, int start, int end)
{
    if(start > end)
        return;

    int median = (start + end)/2;
    Node* newNode = new Node;
    newNode->data = nodeValues[median];
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    root = newNode;

    sortedArrayToBalancedBST(newNode->leftChild, nodeValues, start, median - 1);
    sortedArrayToBalancedBST(newNode->rightChild, nodeValues, median + 1, end);
}

void balanceBST(Node* root)
{
    std::vector<int> nodeValuesInOrder;

    inOrderStorage(root, nodeValuesInOrder);

    sortedArrayToBalancedBST(root, nodeValuesInOrder, 0, nodeValuesInOrder.size() - 1);
}