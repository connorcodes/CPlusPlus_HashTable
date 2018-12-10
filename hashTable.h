//
// Created by eldoradocoder on 12/8/18.
//

#ifndef LAB6_CRS_HASHTABLE_H
#define LAB6_CRS_HASHTABLE_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <string>

#define SIZE 13

class hashTable{

private:
    int table[SIZE]{}, elementCount;

public:
//Declarations

    //Initialize hash Table
    hashTable(){
        for (int &i : table) {
            i = 0;
        }
        elementCount = 0;
    }

    // method that checks if the hash table is full or not
    bool isFull();

    // method that returns position for a given element
    int hashFunction(int element);

    // method that finds the next empty position using quadratic probing
    int quadraticProbing(int element, int position);

    // method that inserts element inside the hash table
    void insert(int element);

    // method that searches for an element in the table
    // returns position of element if found
    // else returns false
    int search(std::string element);


    // method to remove an element from the table
    void remove(int element);

    // method to display the hash table
    void display();
};

//Public Definitions

bool hashTable::isFull() {
    return elementCount == SIZE;
}

int hashTable::hashFunction(int element) {
    return element % SIZE;
}

int hashTable::quadraticProbing(int element, int position) {
    int limit = 50, i = 1;
    int newPosition = -1;
    while(i <= 50){
        newPosition = this->hashFunction(position + (int)pow(i, 2));
        if(this->table[newPosition] == 0){
            break;
        }
        else{
            i++;
        }
    }
    return newPosition;
}

void hashTable::insert(int element) {  //TODO: change ints to strings
    int position;
    // checking if the table is full
    if(this->isFull()){
        std::cout << "\nHash Table Full";
        return;
    }

    bool isStored = false;

    position = this->hashFunction(element);

    // checking if the position is empty
    if(table[position] == 0){
        table[position] = element;
        std::cout << "\nElement " << element << " stored at position " << position;
        isStored = true;
        elementCount += 1;
    }

        // collision occured hence we do linear probing
    else{
        std::cout<<"\nCollision has occured for element " <<element<<" at position " <<position<<" finding new Position.";
        position = quadraticProbing(element, position);
        if(position != -1){
            this->table[position] = element;
            elementCount += 1;
            std::cout<<"\nElement " <<element<<" stored at position " <<position;
        }

    }
}

int hashTable::search(std::string element) {
    bool found = false;

    int position = this->hashFunction(element);

    if(table[position] == element){
        found = true;
        return position;
    }

        // if element is not found at position returned hash function
        // then we search element using quadratic probing
    else{
        int limit = 50, i = 1;
        int newPosition = -1;
        while(i <= 50){
            newPosition = this->hashFunction(position + (int)pow(i, 2));
            if(this->table[newPosition] == element){
                found = true;
                break;
            }
            else{
                i++;
            }
        }
        if(found){
            return newPosition;
        }
        else{
            std::cout<<"Element not found";
            return -1;
        }
    }
}

void hashTable::display() {
    for (int i = 0; i < SIZE; i++){
        std::cout << "\n"<<i<<" = "<<table[i];
    }
    std::cout<<"\nThe number of element is the Table are : " <<this->elementCount;
}

void hashTable::remove(int element) {
    int position = this->search(element);
    if(position != -1){
        table[position] = 0;
        std::cout<<"\nElement " <<element<<" is Deleted";
        this->elementCount -= 1;
    }else{
        std::cout<<"\nElement is not present in the Hash Table";
    }
}

//End public definitions

#endif //LAB6_CRS_HASHTABLE_H
