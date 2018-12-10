//
// Created by eldoradocoder on 12/8/18.
// Hash node template class that assigns keys
//

#ifndef LAB6_CRS_HASHNODE_H
#define LAB6_CRS_HASHNODE_H

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

#include "hashtable.h"

template <typename birthday, typename name> // K = bday, V = name
class hashEntry
{
public:
    int key;
    int value;
    hashEntry(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};


#endif //LAB6_CRS_HASHNODE_H
