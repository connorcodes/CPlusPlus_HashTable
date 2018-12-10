//
// Created by eldoradocoder on 12/8/18.
// Lab #6 - Hash Table with Quadratic Probing
// External files: Dataset provided by bst_testfile.txt
//

#include <iostream>
#include <string>
#include <cstdlib>


#include "hashTable.h"

using namespace std;

struct bdayFound
{
    string key;
    string  data;
    int slot_found;
    int overflow_found;
};

int answer;
void menu();

int Menu();
void FindStudent(hashTable& hash);

int main(){
    char rpt;

    //TODO: Allow program to read file from anywhere on host machine CHAR ERROR
    //TODO: Read bst_testfile.txt DONE
    //TODO: Convert yyyy-mm-dd to a single hash key number (string->int) MAYBE DO IN HASHTABLE.H?

    ifstream fin;
    fin.open("bst_testfile.txt");
    hashTable hashtable;
    string blank_line, searchkey;
    while (!fin.eof())
    {
        //string blank_line fin.getline();
        getline(fin, blank_line);
        string key = blank_line.substr(0,9);
        string data = blank_line.substr(10,29);
        hashtable.insert(key,data);
    }
    fin.close();

    do {
        cout << "Welcome to The Birthdate Hasher!" << endl;
        cout << "1) Add birthday entry\n"
                "2) Remove birthday entry\n"
                "3) Search for an entry\n"
                "4) Display all entries\n" << endl;
        cout << "Choose an option (1-4): " << endl;
        cin >> answer;
        menu();

        cout<<"\nDo another operation? Y/N : " << endl;
        cin >> rpt;
    } while (rpt == 'Y');



    return 0;
}

void menu() {


    switch (answer) {
        case 1:
            //Add
            cout << "Good choice! This will help you burn some calories!\n";
            break;

        case 2:
            //Remove
            cout << "Still a good choice, as you'll burn calories slowly, but surely.\n";
            break;

        case 3:
            //Search
            cout << "We can't have that! You won't burn any calories unless you either run or walk.\n";
            break;

        case 4:
            //Display all
            cout << "Good choice! This will help you burn some calories!\n";
            break;

        default:
            cout << "Bad choice! Please try again: \n";
            break;
    }



}

/*void FindName(hashTable &hash) {
    int bday

    cout << " Enter birthdate: ";
    cin >> bday;

    //TODO: Convert bday from string->int

    hash.search(bday);
}*/

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
