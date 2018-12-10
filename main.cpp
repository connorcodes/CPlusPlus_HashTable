//
// Created by Connor Sanders (eldoradocoder) on 12/8/18.
//

#include<iostream>
#include<string>
#include<fstream>

#include"hashTable.h"
#include"hashEntry.h"

using namespace std;


int main()
{
    ifstream infile;
    string location;

    cout << "Enter location of file (example: drive//path//project//txt file): ";
    getline(cin, location);

    if (infile.fail())
    {
        cout << "Incorrect location, try again: ";

        getline(cin, location);
    } else
        infile.open(location.c_str());

    hashEntry<string, string> *Hnode = new hashEntry<string, string>;
    hashTable<string, string> *Htable = new hashTable<string, string>;

    string name = "";
    string birthdate = "";

    while (getline(infile, name)) {
        //Retrieve data
        getline(infile, name);
        getline(infile, birthdate);

        //Send data to hashTable and hashEntry
        Hnode->setKey(birthdate);
        Hnode->setValue(name);
        Htable->insert(birthdate, name);
    }
    infile.close();

    //Displays the hashTable
    Htable->display();
    Htable->mapSize();

    //Displays hashTable stats
    cout << "Load factor: "<< Htable->mapSize() / Htable->showSize() * 100 << endl;
    cout << "Collisions:" << Htable->getCollisions() << endl;

    char choice;

    // do the menu while choice is equal to 1
    do {
        string userDate=" ";

        cout << "Enter a birthday: \n";
        cin >> userDate;

        cout << "That name is: " << Htable->find(userDate) << endl;

        cout << "1. Would you like to search another Birthday: \n" << endl;
        cout << "2. End the program" << endl;
        cin >> choice;

    } while (choice == 'y');

    cout << "Now exiting. " << "Thank you for using Connor's hash table program!" << endl;
    return 0;
}