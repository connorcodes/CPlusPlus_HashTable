//
// Created by eldoradocoder on 12/8/18.
//

#ifndef LAB6_CRS_HASHTABLE_H
#define LAB6_CRS_HASHTABLE_H

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

#include "hashEntry.h"

#define SIZE 13

class hashTable
{
private:
    hashEntry **table;
public:
    hashTable()
    {
        table = new hashEntry * [TABLE_SIZE];
        for (int i = 0; i< TABLE_SIZE; i++)
        {
            table[i] = NULL;
        }
    }
    /*
     * Hash Function
     */
    int HashFunc(int key)
    {
        return key % TABLE_SIZE;
    }
    /*
     * Insert Element at a key
     */
    void Insert(int key, int value)
    {
        int hash = HashFunc(key);
        while (table[hash] != NULL && table[hash]->key != key)
        {
            hash = HashFunc(hash + 1);
        }
        if (table[hash] != NULL)
            delete table[hash];
        table[hash] = new HashEntry(key, value);
    }
    /*
     * Search Element at a key
     */
    int Search(int key)
    {
        int  hash = HashFunc(key);
        while (table[hash] != NULL && table[hash]->key != key)
        {
            hash = HashFunc(hash + 1);
        }
        if (table[hash] == NULL)
            return -1;
        else
            return table[hash]->value;
    }

    /*
     * Remove Element at a key
     */
    void Remove(int key)
    {
        int hash = HashFunc(key);
        while (table[hash] != NULL)
        {
            if (table[hash]->key == key)
                break;
            hash = HashFunc(hash + 1);
        }
        if (table[hash] == NULL)
        {
            std::cout << "No Element found at key " << key << std::endl;
            return;
        }
        else
        {
            delete table[hash];
        }
        std::cout << "Element Deleted" << std::endl;
    }
    ~hashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            if (table[i] != NULL)
                delete table[i];
            delete[] table;
        }
    }
};

#endif //LAB6_CRS_HASHTABLE_H
