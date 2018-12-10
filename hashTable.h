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

const int DEFAULT_TABLE_SIZE = 128;

template<typename K, typename V>
class hashTable {
private:
    double size;
    hashEntry<K, V> **table;
    int capacity;
    int collisions;
    double maxLoadFactor;
    int threshold;
    int maxSize;
    int tableSize;

public:
    hashTable();

    ~hashTable();

    V find(K key);

    bool isPrime(int n);

    void insert(K key, V value);

    //TODO: void remove(K key);

    void display();

    int compute(std::string d);

    int getCollisions();

    int nextPrime(int n);

    int capacityF();

    double mapSize();

};

template<typename K, typename V>
hashTable<K, V>::hashTable() {
    tableSize = 12;
    size = 0;
    capacity = .75;
    table = new hashEntry<K, V> *[capacity];
    collisions = 0;

    for (int i = 0; i < capacity; i++)
        table[i] = nullptr;
}


template<typename K, typename V>
hashTable<K, V>::~hashTable() {
    delete[]table;
}

template<typename K, typename V>
int hashTable<K, V>::compute(std::string d) {
    int sum = 0; // sum of all the digits in date
    int s = d.length(); // length of date string
    for (int i = 0; i < s; i++) //traversing date string
    {
        if (d[i] != '-') //if the char is not a hyphen, add it to sum
        {
            sum += (d[i] - 48); //ascii, numbers start from 48
        }
    }
    std::string inter = std::to_string(sum); //string of intermediate sum

    int size2 = inter.length(); //length of inter
    if (size2 == 1)
        return sum;
    int num = 0;
    if (size2 > 1) {
        num = 0;

        while (size2 > 1) {
            num = 0;
            //cout << size2 << endl;
            for (int t = 0; t < size2; t++) {
                num += (inter[t] - 48);
            }
            inter = std::to_string(num);
            size2 = inter.length();
            //cout << size2 << endl;

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

/*
	A function to insert the name and birthday
	@param key - a string of the birthday
	@param value - a string name
	if Load factor is greater than max load factor the capacity is increased to the next prime number
	if the value at the hashIndex is a nullptr insert the value
	while there is no empty space go through quadratic probing to find a new spot to insert the value
*/
template<typename K, typename V>
void hashTable<K, V>::insert(K key, V value) {
    // if loadfactor is greater than or equal to 75% then increase the capacity by double
    if ((size / capacity) >= maxLoadFactor) {
        int newCapacity = nextPrime(capacity);
        auto **newTable = new hashEntry<K, V> *[newCapacity];
        for (int i = 0; i < capacity; i++) {
            newTable[i] = table[i];
        }
        for (int i = capacity; i < newCapacity; i++) {
            newTable[i] = nullptr;
        }
        table = newTable;
        capacity = newCapacity;
    }
    hashEntry<K, V> *temp = new hashEntry<K, V>(key, value);
    int hashed = compute(key);
    // Apply hash function to find index for given key
    int hashIndex = hashed % capacity;
    int NUM = 1;
    //find next free space
    while (table[hashIndex] != nullptr && NUM * NUM < capacity && table[hashIndex]->getKey() != key) {
        //hashIndex = hashed % capacity;
        hashIndex += (NUM * NUM);
        hashIndex = hashIndex % capacity;
        NUM++;
        collisions++;
    }

    //if new node to be inserted increase the current size
    if (table[hashIndex] == NULL)size++;
    table[hashIndex] = temp;

    return;
}

template<typename K, typename V>
V hashTable<K, V>::find(K key) {
    bool found = false;
    //int countSmthng=0;
    size_t hashIndex = static_cast<size_t>(compute(key));
    hashIndex = hashIndex % capacity;
    int NUM = 1;
    while (!found && NUM * NUM < capacity && table[hashIndex] != nullptr) {

        found = table[hashIndex]->getKey() == key;
        if (!found && NUM * NUM < capacity) {
            hashIndex += NUM * NUM;
            hashIndex = hashIndex % capacity;
            NUM++;
        }
    }
    if (found) {
        return table[hashIndex]->getValue();
    } else
        return "an Invalid Data";
}

template<typename K, typename V>
double hashTable<K, V>::mapSize() {
    return size;
}

template<typename K, typename V>
void hashTable<K, V>::display() {
    std::cout << "See the capacity in display  " << capacity << std::endl;
    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr)
            std::cout << "Key = " << table[i]->getKey() << " Value = " << table[i]->getValue() << std::endl;
    }
}

template<typename K, typename V>
int hashTable<K, V>::capacityF() {
    return capacity;
}

template<typename K, typename V>
int hashTable<K, V>::getCollisions() {
    return collisions++;
}

/*template<typename K, typename V>
void hashTable<K, V>::remove(K key) {

    int hash = (key % tableSize);

    if (table[hash] != NULL) {

        hashEntry *prevEntry = NULL;

        hashEntry *entry = table[hash];

        while (entry->getNext() != NULL && entry->getKey() != key) {

            prevEntry = entry;

            entry = entry->getNext();

        }

        if (entry->getKey() == key) {

            if (prevEntry == NULL) {

                hashEntry *nextEntry = entry->getNext();

                delete entry;

                table[hash] = nextEntry;

            } else {

                hashEntry *next = entry->getNext();

                delete entry;

                prevEntry->setNext(next);

            }

            size--;

        }

    }*/

#endif //LAB6_CRS_HASHTABLE_H
