//
// Created by eldoradocoder on 12/8/18.
//

#ifndef LAB6_CRS_HASHTABLE_H
#define LAB6_CRS_HASHTABLE_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>

#define SIZE 13

class hashTable{

private:
    int table[SIZE], elementCount;

public:

    //Initialize hash Table
    hashTable(){
        for (int &i : table) {
            i = 0;
        }
        elementCount = 0;
    }

    //Displays the file
    void writeOut(char * fileName)
    {
        std::ofstream out;

        out.open(fileName);
        if(!out)
        {
            std::cerr << "fail to open " << fileName << " for output!" << std::endl;
            return;
        }

        int i;
        char birthdate[100];
        char name[100];
       // node * curr;
        for(i=0; i<capacity; i++) //TODO: What is capacity?
        {
            for(curr = table[i]; curr; curr = curr->next)
            {
                curr->item.getTickerSymbol (birthdate);
                curr->item.getName (name);
                out << birthdate << ';' << name << ';' << curr->item.getNetValue () << '\n';
            }
        }
        out.close ();
    }


    //Read from textfile to hash Table
    hashTable(char * fileName)
    {
        std::ifstream in;
        data currData; //TODO: Replace 'data'
        char birthdate[100];
        char name[100];

       // initializeTable();

        in.open(fileName);
        if(!in)
        {
            std::cerr << "fail to open " << fileName << " for input!" << std::endl;
            return;
        }

        in.get(birthdate, 100, ';');
        while(!in.eof())
        {
            in.ignore(100, ';');
            in.get(name, 100, ';');
            in.ignore(100, ';');

            currData.setbirthdate (birthdate);
            currData.setName (name);

            insert(currData);

            in.get(birthdate, 10, ';');
        }
        in.close ();
    }


    // method that checks if the hash table is full or not
    bool isFull(){
        if(elementCount == SIZE){
            return true;
        }else{
            return false;
        }
    }


    // method that returns position for a given element
    int hashFunction(int element){
        return element % SIZE;
    }

    // method that finds the next empty position using quadratic probing
    int quadraticProbing(int element, int position){
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

    // method that inserts element inside the hash table
    void insert(int element){  //TODO: change ints to strings
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
        return;
    }

    // method that searches for an element in the table
    // returns position of element if found
    // else returns false
    int search(int element){
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


    // method to remove an element from the table
    void remove(int element){
        int position = this->search(element);
        if(position != -1){
            table[position] = 0;
            std::cout<<"\nElement " <<element<<" is Deleted";
            this->elementCount -= 1;
        }else{
            std::cout<<"\nElement is not present in the Hash Table";
        }
        return;
    }

    // method to display the hash table
    void display(){
        for (int i = 0; i < SIZE; i++){
            std::cout << "\n"<<i<<" = "<<table[i];
        }
        std::cout<<"\nThe number of element is the Table are : " <<this->elementCount;
    }
};

#endif //LAB6_CRS_HASHTABLE_H
