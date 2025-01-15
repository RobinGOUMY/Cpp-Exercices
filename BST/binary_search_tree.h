#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "header.h"

Node* BST_brands_ROOT = NULL;
Node* BST_states_ROOT = NULL;
Node* BST_factoryYears_ROOT = NULL;
Node* BST_prices_ROOT = NULL;
Node* BST_IDs_ROOT = NULL;

void insertBST(Node*& ROOT, pii data)
{
    Node* newNode = new Node;
    newNode->data.first = data.first;
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

            if(data.first < parent->data.first) // go to the left subtree
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

// recursive function to retrieve a car by ID
int retrieveBST(Node* ROOT, int key)
{
    if(ROOT != NULL)
    {
        cout << "exploring... " << ROOT->data.first << endl;
        if(ROOT->data.first == key)
        {
            return ROOT->data.second;
        }
        else if(ROOT->data.first > key)
        {
            return retrieveBST(ROOT->leftChild, key);
        }
        else
        {
            return retrieveBST(ROOT->rightChild, key);
        }
    }
    
    return -1;
}

void preOrderTraversal(Node* root)
{
    if(root != NULL)
    {
        cout << root->data.first << endl;
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }
}

void inOrderTraversal(Node* root)
{
    if(root != NULL)
    {
        inOrderTraversal(root->leftChild);
        cout << root->data.first << endl;
        inOrderTraversal(root->rightChild);
    }
}

void postOrderTraversal(Node* root)
{
    if(root != NULL)
    {
        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        cout << root->data.first << endl;
    }
}



#endif