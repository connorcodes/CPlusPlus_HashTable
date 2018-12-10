//
// Created by eldoradocoder on 12/8/18.
// Lab #6 - Hash Table with Quadratic Probing
// External files: Dataset provided by bst_testfile.txt
//


#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

#include "hashTable.h"

using namespace std;
const int TABLE_SIZE = 128;

int answer;
void menu();

int main(){
    char rpt;
    hashTable hash;
    int key, value;

    //TODO: Allow program to read file from anywhere on host machine CHAR ERROR
    //TODO: Read bst_testfile.txt DONE
    //TODO: Convert yyyy-mm-dd to a single hash key number (string->int) MAYBE DO IN HASHTABLE.H?

    do {
        cout << "Welcome to The Birthdate Hasher!" << endl;
        cout << "1) Add birthday entry\n"
                "2) Remove birthday entry\n"
                "3) Search for an entry\n"
                "4) Display all entries\n"
                "5) Quit program" << endl;
        cout << "Choose an option (1-5): " << endl;
        cin >> answer;

        switch (answer) {
            case 1:
                //Add
                cout<<"Enter element to be inserted: ";
                cin>>value;
                cout<<"Enter key at which element to be inserted: ";
                cin>>key;
                hash.Insert(key, value);
                break;

            case 2:
                //Remove
                cout<<"Enter key of the element to be searched: ";
                cin>>key;
                if (hash.Search(key) == -1)
                {
                    cout<<"No element found at key "<<key<<endl;
                    continue;
                }
                else
                {
                    cout<<"Element at key "<<key<<" : ";
                    cout<<hash.Search(key)<<endl;
                }
                break;

            case 3:
                //Search
                cout<<"Enter key of the element to be deleted: ";
                cin>>key;
                hash.Remove(key);
                break;

            case 4:
                //Display all
                cout << "Displays all\n";
                break;

            case 5:
                exit(1);

            default:
                cout << "Bad choice! Please try again: \n";
                break;
        }

        cout<<"\nDo another operation? Y/N : " << endl;
        cin >> rpt;

    } while (rpt == 'Y');

    return 0;
}
