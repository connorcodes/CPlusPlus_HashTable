//
// Created by eldoradocoder on 12/8/18.
// Lab #6 - Hash Table with Quadratic Probing
// External files: Dataset provided by bst_testfile.txt
//


#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<string>
#include<fstream>

#include "hashTable.h"

using namespace std;


int answer;
void menu();

int main(){
    char rpt;
  // hashTable hash;
    int key, value;

    //TODO: Allow program to read file from anywhere on host machine CHAR ERROR
    //TODO: Read bst_testfile.txt DONE
    //TODO: Convert yyyy-mm-dd to a single hash key number (string->int) MAYBE DO IN HASHTABLE.H?

    ifstream infile;
    string location="bstTestFile.txt";
    /*cout << "Enter the location of the file: ";
    getline(cin, location);

    while (infile.fail())
    {
        cout << "The location that is entered is wrong. Please re-enter the location: ";
        getline(cin, location);
    }*/
    infile.open(location.c_str());
    hashEntry<string, string> *h = new hashEntry<string, string>;
    hashTable<string, string> *hm = new hashTable<string, string>;

    string name, date;

    //while not the end of file
    // get name and date
    // set the value as name and key as name
    // insert the date with key as date and value as name
    while (!infile.eof())
    {
        getline(infile, name);
        getline(infile, date);
        h->setKey(date);
        h->setValue(name);
        hm->insert(date, name);
        hd->
    }

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
              /*  cout << "Enter element to be inserted: ";
                cin >> value;
                cout << "Enter key at which element to be inserted: ";
                cin >> key;
                hash.Insert(key, value);*/
                break;

            case 2:
                //Remove
                string deleteDate;
                cout << "Enter the birthdate to delete (Ex: 1974-08-24): ";
                getline(cin, deleteDate);

                string value = hm->find(deleteDate);


                cout << "The entry " << value << " has been deleted. " << endl;

                break;

            case 3:
                //Search
                string userDate;
                cout << "Enter the birthday of the person in YYYY-MM-DD format (Ex: 1974-08-24): ";
                getline(cin, userDate);

                string value = hm->find(userDate);
                cout << "The name associated with the birthday you entered is: " << value << endl;

             /*   cout<<"Enter key of the element to be searched: ";
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
                }*/

                break;

            case 4:
                //Display all
                cout << "Displays all\n";
                break;

            case 5:
               //TODO: exit message
               goto exit;
               break;

            default:
                cout << "Bad choice! Please try again: \n";
                break;
        }

        cout<<"\nDo another operation? Y/N : " << endl;
        cin >> rpt;

    } while (rpt == 'Y');

    exit:   ;
    return 0;
}
