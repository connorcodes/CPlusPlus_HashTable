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

//template <typename birthday, typename name> // K = bday, V = name
template<typename K, typename V>
class hashEntry {
private:
    V value;
    K key;
public:
   /* hashEntry(int key, int value) {
        this->key = key;
        this->value = value;
    }*/

    hashEntry();

    hashEntry(K key2, V value2);

    void setKey(K key2);

    K getKey();

    void setValue(V value2);

    V getValue();
};

template<typename K, typename V>
hashEntry<K, V>::hashEntry() {
    this->value = "";
    this->key = "";
}

template<typename K, typename V>
hashEntry<K, V>::hashEntry(K key2, V value2) {
    this->value = value2;
    this->key = key2;
}

template<typename K, typename V>
void hashEntry<K, V>::setKey(K key2) {
    key = key2;
}

template<typename K, typename V>
K hashEntry<K, V>::getKey() {
    return key;
}

template<typename K, typename V>
void hashEntry<K, V>::setValue(V value2) {
    value = value2;
}

template<typename K, typename V>
V hashEntry<K, V>::getValue() {
    return value;

};


#endif //LAB6_CRS_HASHNODE_H
