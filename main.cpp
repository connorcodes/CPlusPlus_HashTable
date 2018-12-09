//
// Created by eldoradocoder on 12/8/18.
// Lab #6 - Hash Table with Quadratic Probing
// External files: Dataset provided by bst_testfile.txt
//

#include <iostream>
#include <string>
#include <stdlib.h>


#include "hashTable.h"

using namespace std;


int main(){
    //TODO: Allow program to read file from anywhere on host machine CHAR ERROR
    //TODO: Read bst_testfile.txt DONE
    //TODO: Convert yyyy-mm-dd to a single hash key number (string->int) MAYBE DO IN HASHTABLE.H?



    return 0;
}

/*
 * Hashing usage reference:

    hashTable table1;

    // storing elements in table
    table1.insert(12);
    table1.insert(26);
    table1.insert(31);
    table1.insert(17);
    table1.insert(90);
    table1.insert(28);
    table1.insert(88);
    table1.insert(40);
    table1.insert(77);		// element that causes collision at position 0

    // displaying the Table
    table1.display();
    cout<<"\n";

    // printing position of elements
    cout<<"\nThe position of element 31 is : " <<table1.search(31);
    cout<<"\nThe position of element 28 is : " <<table1.search(28);
    cout<<"\nThe position of element 90 is : " <<table1.search(90);
    cout<<"\nThe position of element 77 is : " <<table1.search(77);
    cout<<"\nThe position of element 1 is : " <<table1.search(1);

    cout<<"\n";

    table1.remove(90);
    table1.remove(12);

    table1.display();
*/
