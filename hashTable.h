//
// Created by eldoradocoder on 12/8/18.
//
#pragma once

#ifndef LAB6_CRS_HASHTABLE_H
#define LAB6_CRS_HASHTABLE_H

#include <iostream>
#include <string>

#include "hashEntry.h"

using namespace std;

template<typename K, typename V>
class hashTable
{
private:
    double size;
    hashEntry<K, V> **mainTable;
    int cap;
    int collisionsCount;
    double maxLoadFactor;

public:
    hashTable();
    ~hashTable();
    bool isPrime(int n);
    int nextPrime(int n);
    void insert(K key, V value);
    V find(K key);
    int compute(string d);
    int getCollisions();
    double mapSize();
    void display();
    int showSize();

};

template <typename K,typename V>
hashTable<K, V>::hashTable()
{
    cap = 13;
    size = 0;
    maxLoadFactor = .75;
    mainTable = new hashEntry<K, V>*[cap];
    collisionsCount = 0;
    for (int i = 0; i < cap; i++)
        mainTable[i] = nullptr;
}


template <typename K, typename V>
hashTable <K, V>::~hashTable()
{
    delete[]mainTable;
}

template <typename K, typename V>
int hashTable <K, V>::getCollisions()
{
    return collisionsCount++;
}

template <typename K, typename V>
double hashTable <K, V>::mapSize()
{
    return cap;
}


template <typename K, typename V>
void hashTable <K, V>::display()
{
    for (int i = 0; i < cap; i++)
    {
        if (mainTable[i] != nullptr)
            cout << "Key = " << mainTable[i]->getKey() << " Value = " << mainTable[i]->getValue() << endl;
    }
}


template <typename K, typename V>
int hashTable <K, V>::showSize()
{
    return size;
}

template <typename K, typename V>
int hashTable <K, V>::compute(string d)
{
    int sum = 0;
    int s = d.length();
    for (int i = 0; i < s; i++)
    {
        if (d[i] != '-')
        {
            sum += (d[i] - 48);
        }
    }
    string inter = to_string(sum);

    int size2 = inter.length();
    if (size2 == 1)
        return sum;
    int num = 0;
    if (size2 > 1)
    {
        num = 0;

        while (size2 > 1)
        {
            num = 0;
            for (int t = 0; t < size2; t++)
            {
                num += (inter[t] - 48);
            }
            inter = to_string(num);
            size2 = inter.length();

        }
    }
    return num;
}


template <typename K, typename V>
bool hashTable <K, V>::isPrime(int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n == 1 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

template <typename K, typename V>
int hashTable <K, V>::nextPrime(int n)
{
    if (n <= 0)
        n == 3;
    if (n % 2 == 0)
        n++;
    for (; !isPrime(n); n += 2);
    return n;
}

template <typename K, typename V>
void hashTable <K, V>::insert(K key, V value)
{
    if ((size / cap) >= maxLoadFactor)
    {
        int newCap = nextPrime(cap+1);
        hashEntry<K, V>**newTable = new hashEntry<K, V>*[newCap];
        for (int i = 0; i < cap; i++)
        {
            newTable[i] = mainTable[i];
        }
        for (int i = cap; i < newCap; i++)
        {
            newTable[i] = nullptr;
        }
        mainTable = newTable;
        cap = newCap;
    }
    hashEntry<K, V> *temp = new hashEntry<K, V>(key, value);
    int hashed = compute(key);
    int hashIndex = hashed % cap;
    int NUM = 1;
    while (mainTable[hashIndex] != nullptr)
    {
        hashIndex += (NUM * NUM);
        hashIndex = hashIndex % cap;
        NUM++;
        collisionsCount++;
    }

    if (mainTable[hashIndex] == NULL)size++;
    mainTable[hashIndex] = temp;
}

template <typename K, typename V>
V hashTable <K, V>::find(K key) {
    bool found = false;
    size_t hashIndex = compute(key);
    hashIndex = hashIndex % cap;
    int NUM = 1;
    while (!found && mainTable[hashIndex] != nullptr)
    {
        found = mainTable[hashIndex]->getKey() == key;
        if (!found)
        {
            hashIndex += NUM * NUM;
            hashIndex = hashIndex % cap;
            NUM++;
        }
    }
    if (found) {
        return mainTable[hashIndex]->getValue();
    }
    else
        return "invalid entry";
}
#endif //LAB6_CRS_HASHTABLE_H
