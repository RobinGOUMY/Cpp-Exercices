#include <iostream>
#include <string>
#include <utility>

#define MAX_CAPACITY 5000

using namespace std;

class AlgoHashTable
{
    public:
        int elements;
        int capacity;
        AlgoHashTable();
        AlgoHashTable(int size);
        void addElement(string key, int value);
        pair<string, int>* getElement(string key);
        bool isEmpty();
        void releaseHashTable();
    private:
        pair<string, int>** items;
        unsigned long hashFunction(string key);   
};

AlgoHashTable::AlgoHashTable()
{
    items = new pair<string, int>*[MAX_CAPACITY];
    elements = 0;
    capacity = MAX_CAPACITY;
}

AlgoHashTable::AlgoHashTable(int size)
{
    if(size > MAX_CAPACITY)
        size = MAX_CAPACITY;

    items = new pair<string, int>*[size];
    elements = 0;
    capacity = size;
}

unsigned long AlgoHashTable::hashFunction(string key)
{
    unsigned long hash = 0;
    for(int i = 0; i < key.size(); i++)
    {
        hash += key.at(i);
    }
    return hash % capacity;
}

void AlgoHashTable::addElement(string key, int value)
{
    if(capacity == elements)
    {
        cout << "Not enough space!" << endl;
        return;
    }
    unsigned long index = hashFunction(key);
    if(items[index] != NULL)
    {
        pair<string, int>* current = items[index];
        if(key.compare(current->first) == 0)
        {
            current->second = value;
        }
        else
        {
            cout << "HASH COLLISION!" << endl;
            return;
        }
    }
    else
    {
        pair<string, int>* newELem = new pair(key, value);
        items[index] = newELem;
        elements++;
    }
}

pair<string, int>* AlgoHashTable::getElement(string key)
{
    unsigned long index = hashFunction(key);
    if(items[index] != NULL)
    {
        return items[index];
    }
    else
    {
        return NULL;
    }
}

void AlgoHashTable::releaseHashTable()
{
    for (int i = 0; i <  capacity; i++)
    {
        if(items[i] != NULL)
            delete items[i];
    }
    delete[] items;
    elements = 0;
    capacity = 0;
}

bool AlgoHashTable::isEmpty()
{
    return elements == 0;
}