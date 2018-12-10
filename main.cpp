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

    //getFile: ;
    cout << "Enter location of file (example: drive//path//project//txt file): ";
    getline(cin, location);

    if (infile.fail())
    {
        cout << "Incorrect location, try again: ";
      //  goto getFile;
        getline(cin, location);
    } else
        infile.open(location.c_str());

    hashEntry<string, string> *Hnode = new hashEntry<string, string>;
    hashTable<string, string> *Htable = new hashTable<string, string>;

    string name;
    string birthdate;

    while (!infile.eof()) {
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

    //Displays hashTable stats
    cout << "Load factor: "<< Htable->mapSize() / Htable->capacityF() * 100 << endl;
    cout << "Collisions:" << Htable->getCollisions() << endl;

    int choice=0;

    // do the menu while choice is equal to 1
    do {
        string userDate=" ";

        cout << "Enter the birthday of the person in YYYY-MM-DD format (Ex: 1974-08-24): ";
        cin >> userDate;

        cout << "The Name of the Birthday that you entered is " << Htable->find(userDate) << endl;

        cout << "1. Would you like to search another Birthday (type 1): " << endl;
        cout << "2. End the program" << endl;
        cin >> choice;

    } while (choice == 1);

   /* char rpt;
    do {
            string inputBday=" ";

            cout << "Enter a birthdate (YYYY-MM-DD): ";
            cin >> inputBday;

            cout << "That is: " << Htable->find(inputBday) << "'s birthday! " << endl;

        cout<<"\nDo another operation? Y/N : " << endl;
        cin >> rpt;
    } while (rpt == 'Y');*/

    cout << "Now exiting. " << "Thank you for using Connor's hash table program!" << endl;
    return 0;
}