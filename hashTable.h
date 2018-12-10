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

template<typename K, typename V>
class hashTable {
private:
    double size;
    hashEntry<K, V> **table;
    int tableSize;
    int collisions;
    double maxLoad;

public:
    hashTable();

    ~hashTable();

    V find(K key);

    bool isPrime(int n);

    void insert(K key, V value);

    void display();

    int compute(std::string d);

    int getCollisions();

    int nextPrime(int n);

    int capacityF();

    double mapSize();

};

template<typename K, typename V>
hashTable<K, V>::hashTable() {
    tableSize = 13;
    size = 0;
    maxLoad = .75;
    table = new hashEntry<K, V> *[tableSize];
    collisions = 0;

    for (int i = 0; i < tableSize; i++)
        table[i] = nullptr;
}


template<typename K, typename V>
hashTable<K, V>::~hashTable() {
    delete[]table;
}

template<typename K, typename V>
int hashTable<K, V>::compute(std::string d) {
    int sum = 0;
    int s = d.length();
    for (int i = 0; i < s; i++)
    {
        if (d[i] != '-')
        {
            sum += (d[i] - 48);
        }
    }
    std::string inter = std::to_string(sum);

    int size2 = inter.length();
    if (size2 == 1)
        return sum;
    int num = 0;
    if (size2 > 1) {
        num = 0;

        while (size2 > 1) {
            num = 0;

            for (int t = 0; t < size2; t++) {
                num += (inter[t] - 48);
            }
            inter = std::to_string(num);
            size2 = inter.length();

        }
    }
    return num;
}

template<typename K, typename V>
bool hashTable<K, V>::isPrime(int n) {
    if (n == 2 || n == 3)
        return true;
    if (n == 1 || n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

template<typename K, typename V>
int hashTable<K, V>::nextPrime(int n) {
    if (n <= 0)
        n == 3;
    if (n % 2 == 0)
        n++;
    for (; !isPrime(n); n += 2);
    return n;
}

template<typename K, typename V>
void hashTable<K, V>::insert(K key, V value) {

    if ((size / tableSize) >= maxLoad) {
        int newCapacity = nextPrime(tableSize+1);
        hashEntry<K, V>**newTable = new hashEntry<K, V>*[newCapacity];
        for (int i = 0; i < tableSize; i++) {
            newTable[i] = table[i];
        }
        for (int i = 0; i < tableSize; i++) {
            newTable[i] = table[i];
        }
        table = newTable;
        tableSize = newCapacity;
    }
    hashEntry<K, V> *temp = new hashEntry<K, V>(key, value);
    int hashed = compute(key);

    int hashIndex = hashed % tableSize;
    int NUM = 1;

    while (table[hashIndex] != nullptr) {

        hashIndex += (NUM * NUM);
        hashIndex = hashIndex % tableSize;
        NUM++;
        collisions++;
    }

    //if new node to be inserted increase the current size
    if (table[hashIndex] == NULL) size++;
    table[hashIndex] = temp;

    return;
}

template<typename K, typename V>
V hashTable<K, V>::find(K key) {
    bool found = false;
    size_t hashIndex = compute(key);
    hashIndex = hashIndex % tableSize;
    int NUM = 1;
    while (!found && table[hashIndex] != nullptr) {

        found = table[hashIndex]->getKey() == key;
        if (!found) {
            hashIndex += NUM * NUM;
            hashIndex = hashIndex % tableSize;
            NUM++;
        }
    }
    if (found) {
        return table[hashIndex]->getValue();
    } else
        return "invalid value";
}

template<typename K, typename V>
double hashTable<K, V>::mapSize() {
    return size;
}

template<typename K, typename V>
void hashTable<K, V>::display() {
    std::cout << "Table size: " << tableSize << std::endl;
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != nullptr)
            std::cout << "Key: " << table[i]->getKey() << " Value: " << table[i]->getValue() << std::endl;
    }
}

template<typename K, typename V>
int hashTable<K, V>::capacityF() {
    return tableSize;
}

template<typename K, typename V>
int hashTable<K, V>::getCollisions() {
    return collisions++;
}

#endif //LAB6_CRS_HASHTABLE_H
