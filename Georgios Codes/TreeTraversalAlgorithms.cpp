#include <iostream>

#include "balanaceBST2.h"

using namespace std;

Node* ROOT = NULL;

void insertBST(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    Node* parent;
    Node* current;

    if(ROOT == NULL) //tree is empty
    {
        ROOT = newNode;
    }
    else
    {
        current = ROOT;
        parent = NULL;
        while(true)
        {
            parent = current;

            if(data < parent->data) // go to the left subtree
            {
                current = current->leftChild;

                if(current == NULL)
                {
                    parent->leftChild = newNode;
                    return;
                }
            }
            else    // go to the right subtree
            {
                current = current->rightChild;

                if(current == NULL)
                {
                    parent->rightChild = newNode;
                    return;
                }
            }
        }
    }
}

void preOrderTraversal(Node* root)
{
    if(root != NULL)
    {
        cout << root->data << endl;
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }
}

void inOrderTraversal(Node* root)
{
    if(root != NULL)
    {
        inOrderTraversal(root->leftChild);
        cout << root->data << endl;
        inOrderTraversal(root->rightChild);
    }
}

void postOrderTraversal(Node* root)
{
    if(root != NULL)
    {
        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        cout << root->data << endl;
    }
}

int main()
{
    int myData[7] = {14, 27, 35, 10, 19, 31, 42};
    for(int i = 0; i < 7; i++)
    {
        insertBST(myData[i]);
    }
    preOrderTraversal(ROOT);
    balanceBST(ROOT);
    cout << "-------" << endl;
    preOrderTraversal(ROOT);
    return 0;
}