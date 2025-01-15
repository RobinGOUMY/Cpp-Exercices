#include <iostream>

class Node
{
    public:
        int value;
        Node* next;
};

class AlgoList
{
    public:
        int getSize();
        Node* getHead();
        Node* getTail();
        void push(int element);
        int pop();
        int getElementAt(int idx);
        void setElementAt(int idx, int value);
        AlgoList();
        AlgoList(int size);
        AlgoList(int size, Node* newHead);
    private:
        int size;
        Node* head;  
        Node* tail;    
};

AlgoList::AlgoList()
{
    //TODO do default constructor stuff
}

AlgoList::AlgoList()
{
    //TODO do default constructor stuff
}

AlgoList::AlgoList(int size)
{
    this->size = size;
    //allocate space for size elements
}

int AlgoList::getSize()
{
    return size;
}

Node* AlgoList::getHead()
{
    return head;
}

// TODO implement the other functions as well :)


