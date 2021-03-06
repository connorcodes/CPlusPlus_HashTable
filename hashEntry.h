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

template<typename K, typename V>
class hashEntry
{
private:
    V value;
    K key;
public:
    hashEntry();
    hashEntry(K key, V value);
    void setKey(K key2);
    K getKey();
    void setValue(V value2);
    V getValue();
};

//default constructor
template<typename K, typename V>
hashEntry<K,V>::hashEntry()
{
    this->value = "";
    this->key = "";
}

//constructor with parameters
template<typename K, typename V>
hashEntry<K, V>::hashEntry(K key2, V value2)
{
    this->value = value2;
    this->key = key2;
}

//A function to set the key
//@param key2 - the birthday
template<typename K, typename V>
void hashEntry<K, V>::setKey(K key2)
{
    key = key2;
}

//a function that returns the key
template<typename K, typename V>
K hashEntry<K, V>::getKey()
{
    return key;
}

//A function to set the Value
//@param value2 - the name
template<typename K, typename V>
void hashEntry<K, V>::setValue(V value2)
{
    value = value2;
}

//A function to return the value
template<typename K, typename V>
V  hashEntry<K, V>::getValue()
{
    return value;
}


#endif //LAB6_CRS_HASHNODE_H
